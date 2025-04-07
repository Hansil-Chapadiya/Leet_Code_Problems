from typing import List

class PartitionEqualSubsetSum_416:
    def canPartition(self, nums: List[int]) -> bool:
        totalSum = sum(nums)
        if totalSum % 2 != 0:
            return False

        subSetSum = totalSum // 2
        dp = [False] * totalSum
        dp[0] = True

        for num in nums:
            for i in range(subSetSum,  num-1, -1):
                dp[i] = dp[i] or dp[i - num]

        return dp[subSetSum]

obj = PartitionEqualSubsetSum_416()
print(obj.canPartition([1, 5, 11, 5]))
