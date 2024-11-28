#include <iostream>
#include <queue>
#include <vector>
class Solution
{
private:
    // Directions for movement: right, left, down, up
    std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        std::vector<std::vector<int>> minObstaclesRemoved(m, std::vector<int>(n, INT_MAX));

        // Start from the top-left corner, accounting for its obstacle value
        minObstaclesRemoved[0][0] = obstacleGrid[0][0];

        // Priority queue to store cells as {obstacle_count, row, col}
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>>
            minHeap;

        // Add the starting cell to the min-heap
        minHeap.push({minObstaclesRemoved[0][0], 0, 0});

        while (!minHeap.empty())
        {
            // Process the cell with the fewest obstacles removed so far
            std::vector<int> currentCell = minHeap.top();
            minHeap.pop();

            int obstacles = currentCell[0], row = currentCell[1], col = currentCell[2];

            // If we've reached the bottom-right corner, return the result
            if (row == m - 1 && col == n - 1)
            {
                return obstacles;
            }

            // Explore all four possible directions from the current cell
            for (std::vector<int> &dir : directions)
            {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(obstacleGrid, newRow, newCol))
                {
                    // Calculate the updated obstacles removed
                    int updatedObstacleCount = obstacles + obstacleGrid[newRow][newCol];

                    // Update if we've found a path with fewer obstacles to the new cell
                    if (updatedObstacleCount < minObstaclesRemoved[newRow][newCol])
                    {
                        minObstaclesRemoved[newRow][newCol] = updatedObstacleCount;
                        minHeap.push({updatedObstacleCount, newRow, newCol});
                    }
                }
            }
        }

        return minObstaclesRemoved[m - 1][n - 1];
    }

    // Helper method to check if the cell is within the grid bounds
    bool isValid(std::vector<std::vector<int>> &obstacleGrid, int row, int col)
    {
        return row >= 0 && col >= 0 && row < obstacleGrid.size() &&
               col < obstacleGrid[0].size();
    }
};
