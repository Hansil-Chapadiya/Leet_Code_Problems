""" from typing import List

class CountGoodTripletsinArray_2179:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        pos_in_nums2 = [0] * n

        # Map value to index in nums2
        for i in range(n):
            pos_in_nums2[nums2[i]] = i

        # Create indexMapping for nums1
        indexMapping = [pos_in_nums2[nums1[i]] for i in range(n)]

        totalTriplet = 0

        # Fix j, and count good triplets
        for j in range(n):
            leftCount = 0
            rightCount = 0

            for i in range(j):
                if indexMapping[i] < indexMapping[j]:
                    leftCount += 1

            for k in range(j + 1, n):
                if indexMapping[k] > indexMapping[j]:
                    rightCount += 1

            totalTriplet += leftCount * rightCount

        return totalTriplet

# Test
obj = CountGoodTripletsinArray_2179()
print(obj.goodTriplets([2, 0, 1, 3], [0, 1, 2, 3]))  # Output: 1
 """


from typing import List

class BIT:

    def __init__(self, size):

        self.tree = [0] * (size + 1)

    def update(self, index, delta):

        index += 1  # 1-based indexing

        while index < len(self.tree):

            self.tree[index] += delta
            index += index & -index

    def query(self, index):

        # prefix sum up to index (inclusive)

        index += 1  # 1-based indexing
        result = 0

        while index > 0:

            result += self.tree[index]
            index -= index & -index

        return result

    def query_range(self, left, right):

        return self.query(right) - self.query(left - 1)


class CountGoodTripletsinArray_2179:

    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:

        n = len(nums1)

        # Step 1: Build indexMapping
        pos = [0] * n

        for i in range(n):

            pos[nums2[i]] = i

        indexMapping = [pos[num] for num in nums1]

        total = 0

        # Step 2: Left pass using BIT

        leftBIT = BIT(n)
        leftSmaller = [0] * n

        for j in range(n):

            val = indexMapping[j]
            leftSmaller[j] = leftBIT.query(val - 1)
            leftBIT.update(val, 1)

        # Step 3: Right pass using BIT

        rightBIT = BIT(n)
        rightGreater = [0] * n

        for j in reversed(range(n)):

            val = indexMapping[j]
            rightGreater[j] = rightBIT.query_range(val + 1, n - 1)
            rightBIT.update(val, 1)

        # Step 4: Multiply left * right for each j

        for j in range(n):

            total += leftSmaller[j] * rightGreater[j]

        return total
