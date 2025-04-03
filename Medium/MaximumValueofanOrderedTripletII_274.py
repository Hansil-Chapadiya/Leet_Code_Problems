from typing import List
import sys
class MaximumValueofanOrderedTripletII_274:
    def maximumTripletValue(self, nums: List[int]) -> int:
        maxValueSoFar = 0
        maxDiffSoFar = 0
        maxTriplet = 0

        n = len(nums)

        for i in range(n):
            if(maxDiffSoFar != 0):
                maxTriplet = max(maxTriplet, maxDiffSoFar * nums[i])

            maxDiffSoFar = max(maxDiffSoFar, maxValueSoFar - nums[i])
            maxValueSoFar = max(maxValueSoFar, nums[i])


        return maxTriplet


obj = MaximumValueofanOrderedTripletII_274()
print(obj.maximumTripletValue([12,6,1,2,7]))