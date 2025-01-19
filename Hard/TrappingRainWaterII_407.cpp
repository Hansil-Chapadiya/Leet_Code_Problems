#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

class TrappingRainWaterII_407
{
public:
    int trapRainWater(std::vector<std::vector<int>> &heightMap)
    {
        int m = heightMap.size();
        if (m == 0)
            return 0;
        int n = heightMap[0].size();

        // Min-heap to store (height, row, col)
        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<>>
            min_heap;

        // Visited matrix to track cells already processed
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        // Push all boundary cells into the min-heap and mark them visited
        for (int i = 0; i < m; i++)
        {
            min_heap.emplace(heightMap[i][0], i, 0);
            min_heap.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++)
        {
            min_heap.emplace(heightMap[0][j], 0, j);
            min_heap.emplace(heightMap[m - 1][j], m - 1, j);
            visited[0][j] = visited[m - 1][j] = true;
        }

        int waterTrapped = 0;

        // Directions for moving to neighbors (up, down, left, right)
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Process cells in the heap
        while (!min_heap.empty())
        {
            auto [height, row, col] = min_heap.top();
            min_heap.pop();

            for (auto [dr, dc] : directions)
            {
                int new_row = row + dr;
                int new_col = col + dc;

                // Check bounds and if the cell is already visited
                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && !visited[new_row][new_col])
                {
                    // Water trapped = max(0, height - neighbor's height)
                    waterTrapped += std::max(0, height - heightMap[new_row][new_col]);

                    // Update neighbor's height to max of its height and the current height
                    min_heap.emplace(std::max(height, heightMap[new_row][new_col]), new_row, new_col);

                    // Mark as visited
                    visited[new_row][new_col] = true;
                }
            }
        }

        return waterTrapped;
    }
};

int main()
{
    TrappingRainWaterII_407 t1;
    std::vector<std::vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};
    std::cout << "Water trapped: " << t1.trapRainWater(heightMap) << std::endl;
    return 0;
}
