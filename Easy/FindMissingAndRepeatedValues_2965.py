from typing import List


class FindMissingAndRepeatedValues_2965:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        a = self.createMap(grid)
        n = len(grid[0]) ** 2
        totalSum = int((n * (n + 1)) / 2)
        gridSum = sum(sum(grid, [])) - a
        return [a, totalSum - gridSum]

    def createMap(self, grid: List[List[int]]) -> int:
        map = {}
        for i in grid:
            for j in i:
                map[j] = map.get(j, 0) + 1
        for num, count in map.items():
            if count > 1:
                return num
        return 0


obj = FindMissingAndRepeatedValues_2965()
print(obj.findMissingAndRepeatedValues([[1, 3], [2, 2]]))
