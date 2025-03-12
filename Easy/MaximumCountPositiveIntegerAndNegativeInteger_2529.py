from typing import List


class MaximumCountPositiveIntegerAndNegativeInteger_2529:
    def binarySearchNegative(self, high: int, low: int, nums: List[int]) -> int:
        indexNeg = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] < 0:
                indexNeg = mid
                low = mid + 1
            else:
                high = mid - 1
        return indexNeg

    def binarySearchPositive(self, high: int, low: int, nums: List[int]) -> int:
        indexPos = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] > 0:
                indexPos = mid
                high = mid - 1
            else:
                low = mid + 1
        return indexPos

    def maximumCount(self, nums: List[int]) -> int:
        n = len(nums)
        negativeIndex = self.binarySearchNegative(n - 1, 0, nums)
        positiveIndex = self.binarySearchPositive(n - 1, 0, nums)

        # Count of negative numbers
        neg_count = negativeIndex + 1 if negativeIndex != -1 else 0
        # Count of positive numbers
        pos_count = n - positiveIndex if positiveIndex != -1 else 0

        return max(neg_count, pos_count)


# Test cases
obj = MaximumCountPositiveIntegerAndNegativeInteger_2529()
print(obj.maximumCount([-2, -1, -1, 1, 2, 3]))  # Output: 3
print(obj.maximumCount([-3, -2, -1, 0, 0, 1, 2]))  # Output: 3
print(obj.maximumCount([5, 20, 66, 1314]))  # Output: 4


"""
from bisect import bisect_left  # 先載入函式庫

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        first_non_negative = bisect_left(nums, 0)
        first_positive = bisect_left(nums, 1)

        neg = first_non_negative
        pos = len(nums) - first_positive

        return max(neg,pos)
"""
