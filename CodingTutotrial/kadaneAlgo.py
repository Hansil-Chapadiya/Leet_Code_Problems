from typing import List


class kadaneAlgo:
    def maxSubArraySum(self, nums: List[int]) -> int:
        maxSumEnding = nums[0]
        answer = 0

        for i in range(1, len(nums)):
            maxSumEnding = max(maxSumEnding + nums[i], nums[i])
            answer = max(maxSumEnding, answer)

        return answer


obj = kadaneAlgo()
print(obj.maxSubArraySum([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
