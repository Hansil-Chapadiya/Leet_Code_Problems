from typing import List
from collections import defaultdict


class SortMatrixbyDiagonals:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:

        n = len(grid)
        result = defaultdict(list)

        for i in range(n):

            for j in range(n):

                result[i-j].append(grid[i][j])


        print(result)

        for key in result:

            if key >= 0:

                result[key].sort(reverse=True)

            else:

                result[key].sort()


        for i in range(n):

            for j in range(n):

                grid[i][j] = result[i-j].pop(0)

        return grid





obj = SortMatrixbyDiagonals()
print(obj.sortMatrix([[1,7,3],
                      [9,8,2],
                      [4,5,6]]))

print(obj.sortMatrix([[0,1],
                      [1,2]]))
