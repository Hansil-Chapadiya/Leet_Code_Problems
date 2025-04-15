from typing import List

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
