#include <iostream>
#include <vector>
#include <cmath>
class SpiralMatrixII
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        // 0,1
        // 1,0
        // 0,-1
        // -1, 0
        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        std::vector<std::vector<int>> answer(n, std::vector<int>(n, 0));

        int row = 0, col = 0, dir = 0;

        for (int i = 1; i <= std::pow(n, 2); i++)
        {
            answer[row][col] = i;

            int nextRow = row + directions[dir][0];
            int nextCol = col + directions[dir][1];

            if (nextCol < 0 || nextRow < 0 || nextRow >= n || nextCol >= n || answer[nextRow][nextCol] != 0)
            {
                dir = (dir + 1) % 4;
                nextRow = row + directions[dir][0];
                nextCol = col + directions[dir][1];
            }

            row = nextRow;
            col = nextCol;
        }
        return answer;
    }
};

int main()
{
    SpiralMatrixII s1;
    std::vector<std::vector<int>> answer = s1.generateMatrix(3);

    for (auto i : answer)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << '\n';
    }

    return 0;
}