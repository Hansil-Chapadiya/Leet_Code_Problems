from typing import List


class MaximumAbsoluteSumofAnySubarray_1749:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        maxSum = float("-inf")
        minSum = float("inf")
        currentSum = 0
        for num in nums:
            currentSum += num
            maxSum = max(maxSum, currentSum)
            if currentSum < 0:
                currentSum = 0

        currentSum = 0
        for num in nums:
            currentSum += num
            minSum = min(minSum, currentSum)
            if currentSum > 0:
                currentSum = 0
        return max(maxSum, abs(minSum)) # type: ignore


obj = MaximumAbsoluteSumofAnySubarray_1749()
# print(obj.maxAbsoluteSum([1, -3, 2, 3, -4]))
print(obj.maxAbsoluteSum([2,-5,1,-4,3,-2]))
