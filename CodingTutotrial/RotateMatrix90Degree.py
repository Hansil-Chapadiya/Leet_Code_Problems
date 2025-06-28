from typing import List
import copy

class RotateMatrix90Degree:
    def rotateMatrix(self, nums: List[List[int]]) -> List[List[int]]:

        # answer = copy.deepcopy(nums)
        # answer = [row[:] for row in nums]

        n = len(nums)
        answer = [[0]*n for row in range(n)]
        for i in range(n):
            for j in range(n):
                answer[i][j] = nums[n-j-1][i]

        return answer

obj = RotateMatrix90Degree()
# print(obj.rotateMatrix([[1,2,3],[4,5,6],[7,8,9]]))
print(obj.rotateMatrix([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))