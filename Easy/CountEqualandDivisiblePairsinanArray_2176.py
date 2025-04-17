from typing import List


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

print(obj.countPairs([3,1,2,2,2,1,3], 2))