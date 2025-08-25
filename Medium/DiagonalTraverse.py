from typing import List

class DiagonalTraverse:

    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:

        if not mat or not mat[0]:
            return []

        m = len(mat)
        n = len(mat[0])

        row = 0
        column = 0

        result = []

        up = True

        while row < m and  column < n:

            if up:

                while row > 0 and column < n-1:

                    result.append(mat[row][column])

                    row -= 1
                    column += 1

                result.append(mat[row][column])

                if column == n-1:

                    row += 1

                else:

                    column += 1

            else:

                while row < m-1 and column > 0:

                    result.append(mat[row][column])

                    row += 1
                    column -= 1

                result.append(mat[row][column])

                if row == m - 1:

                    column += 1

                else:

                    row += 1
            up = not up

        return result



obj = DiagonalTraverse()
print(obj.findDiagonalOrder([[1,2,3],[4,5,6],[7,8,9]]))