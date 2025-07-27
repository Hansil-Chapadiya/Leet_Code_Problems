from typing import List

def sumClosest(nums: List[int], target: int) -> int:
    nums.sort()
    closest_sum = float('inf')

    for i in range(len(nums) - 2):
        left = i + 1
        right = len(nums) - 1

        while left < right:
            curr_sum = nums[i] + nums[left] + nums[right]

            if abs(target - curr_sum) < abs(target - closest_sum):
                closest_sum = curr_sum

            if curr_sum < target:
                left += 1
            elif curr_sum > target:
                right -= 1
            else:
                return curr_sum  # exact match

    return int(closest_sum)

print(sumClosest([-1, 2, 1, -4], 1))
