""" from typing import List
class MinimumOperationstoMakeUniValueGrid_2033:
    def isPossible(self,grid: List[List[int]], x : int) -> bool:
        rem = grid[0][0] % x
        for arr in grid:
            for i in arr:
                if(i % x != rem):
                    return False
        return True
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        if(not self.isPossible(grid,x)):
            return -1

        flattenList = [num for row in grid for num in row]
        flattenList.sort()
        midValue = len(flattenList) // 2
        cnt = 0
        for i in flattenList:
            if i == flattenList[midValue]:
                continue
            elif i > flattenList[midValue]:
                while(i != flattenList[midValue]):
                    i -= x
                    cnt += 1
            elif i < flattenList[midValue]:
                while(i != flattenList[midValue]):
                    i += x
                    cnt += 1
        return cnt


obj = MinimumOperationstoMakeUniValueGrid_2033()
print(obj.minOperations([[2,4],[6,8]],2))
print(obj.minOperations([[1,5],[2,3]],1))
# print(obj.minOperations([[1,2],[3,4]],2)) """

from typing import List

class MinimumOperationstoMakeUniValueGrid_2033:
    def isPossible(self, grid: List[List[int]], x: int) -> bool:
        rem = grid[0][0] % x
        for row in grid:
            for num in row:
                if num % x != rem:
                    return False
        return True

    def minOperations(self, grid: List[List[int]], x: int) -> int:
        if not self.isPossible(grid, x):
            return -1

        # Flatten and sort
        flattenList = [num for row in grid for num in row]
        flattenList.sort()

        # Find the median
        median = flattenList[len(flattenList) // 2]

        # Calculate the minimum operations
        return sum(abs(num - median) // x for num in flattenList)

# Test cases
obj = MinimumOperationstoMakeUniValueGrid_2033()
print(obj.minOperations([[2,4],[6,8]], 2))  # Output: 4
print(obj.minOperations([[1,5],[2,3]], 1))  # Output: 5
# print(obj.minOperations([[1,2],[3,4]], 2))  # Output: -1
