""" from typing import List


class CountEqualandDivisiblePairsinanArray_2176:

    def countPairs(self, nums: List[int], k: int) -> int:

        n = len(nums)
        cnt = 0

        for i in range(n):

            for j in range(i+1,n):

                if(nums[i] == nums[j] and ((i*j) % k == 0)):

                    cnt += 1


        return cnt



obj = CountEqualandDivisiblePairsinanArray_2176()

print(obj.countPairs([3,1,2,2,2,1,3], 2)) """


from typing import List
from collections import defaultdict

class CountEqualandDivisiblePairsinanArray_2176:
    def countPairs(self, nums: List[int], k: int) -> int:
        index_map = defaultdict(list)
        cnt = 0

        # Step 1: Group indices by number
        for i, val in enumerate(nums):
            index_map[val].append(i)

        # Step 2: For each group, check (i * j) % k == 0
        for indices in index_map.values():
            for i in range(len(indices)):
                for j in range(i + 1, len(indices)):
                    if (indices[i] * indices[j]) % k == 0:
                        cnt += 1

        return cnt

# Test it
obj = CountEqualandDivisiblePairsinanArray_2176()
print(obj.countPairs([3,1,2,2,2,1,3], 2))  # Output: 4
