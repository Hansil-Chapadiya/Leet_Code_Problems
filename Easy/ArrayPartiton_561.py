from typing import List

class  ArrayPartition_561:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        # print(nums)
        nLen = len(nums)

        ans = 0

        for i in range(1,nLen):
            if i % 2 == 1:
                ans += nums[i - 1]
        return ans




obj  = ArrayPartition_561()
print(obj.arrayPairSum([1,4,3,2]))