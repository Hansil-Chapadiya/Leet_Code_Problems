#include <iostream>
#include <vector>
#include <algorithm>
class MaximumNumberOfMovesInGrid_2684
{
private:
public:
    int maxMoves(std::vector<std::vector<int>> &grid)
    {
        int row = grid.size();
        int column = grid[0].size();
        int max = 0;
        int moves = 0;
        std::vector<std::vector<int>> dp(row + 1, std::vector<int>(column, 0));
        int i = 0; // Starting row index
        int j = 0; // Starting column index

        while (j < column - 1) // Traverse until the last column
        {
            // Check boundaries and update dp values with grid values if in bounds
            if (i > 0 && j + 1 < column)
            {
                dp[i - 1][j + 1] = grid[i - 1][j + 1];
            }
            dp[i][j + 1] = grid[i][j + 1];
            if (i + 1 < row && j + 1 < column)
            {
                dp[i + 1][j + 1] = grid[i + 1][j + 1];
            }

            // Calculate the maximum value among reachable cells in the next column
            int max_val = dp[i][j + 1];
            if (i > 0 && j + 1 < column)
            {
                max_val = std::max(max_val, dp[i - 1][j + 1]);
            }
            if (i + 1 < row && j + 1 < column)
            {
                max_val = std::max(max_val, dp[i + 1][j + 1]);
            }

            // Move to the position of the maximum element
            if (i > 0 && j + 1 < column && max_val == dp[i - 1][j + 1])
            {
                i = i - 1;
                j = j + 1;
            }
            else if (max_val == dp[i][j + 1])
            {
                j = j + 1;
            }
            else if (i + 1 < row && max_val == dp[i + 1][j + 1])
            {
                i = i + 1;
                j = j + 1;
            }
        }
    }
};
int main()
{
    MaximumNumberOfMovesInGrid_2684 m1;
    std::vector<std::vector<int>> grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    m1.maxMoves(grid);
    return 0;
}
