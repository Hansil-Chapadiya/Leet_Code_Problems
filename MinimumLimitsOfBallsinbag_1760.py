from typing import List


class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        # Helper function to determine if we can make all bag sizes <= max_size using at most maxOperations splits
        def can_make_bags_of_size(max_size):
            operations = 0
            for balls in nums:
                if balls > max_size:
                    # Calculate how many splits are required to make each part <= max_size
                    operations += (
                        balls - 1
                    ) // max_size  # This is equivalent to ceil(balls / max_size) - 1
            return operations <= maxOperations

        # Binary search for the smallest max_size that works
        left, right = 1, max(nums)
        result = right
        while left <= right:
            mid = (left + right) // 2
            if can_make_bags_of_size(mid):
                result = mid  # Found a valid answer, but let's look for a smaller one
                right = mid - 1
            else:
                left = mid + 1
        return result


# Example usage
nums = [9, 7, 16]
maxOperations = 4
s1 = Solution()
print(s1.minimumSize(nums, maxOperations))
