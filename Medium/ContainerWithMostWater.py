from typing import List

class ContainerWithMostWater:

    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0

        while left < right:
            length = min(height[left], height[right])
            width = right - left
            area = length * width
            max_area = max(max_area, area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area

obj = ContainerWithMostWater()
print(obj.maxArea([1,8,6,2,5,4,8,3,7]))
