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
