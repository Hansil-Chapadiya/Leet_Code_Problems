from typing import List

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or = 0

        # Find the maximum bitwise OR that can be achieved
        for num in nums:
            max_or |= num

        # Helper function to count subsets with maximum OR
        def count_subsets(i, current_or):
            if i == len(nums):
                # If the OR of the subset equals max_or, we count it
                return 1 if current_or == max_or else 0

            # Include the current element in the OR
            include = count_subsets(i + 1, current_or | nums[i])

            # Exclude the current element
            exclude = count_subsets(i + 1, current_or)

            return include + exclude

    # Start recursion from index 0 and initial OR of 0
        return count_subsets(0, 0)
