#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Directions corresponding to signs 1 (right), 2 (left), 3 (down), 4 (up)
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Min-heap for Dijkstra's algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Distance matrix initialized with INT_MAX
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Start from (0, 0) with cost 0
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0], x = curr[1], y = curr[2];

            // If we reach the bottom-right cell, return the cost
            if (x == m - 1 && y == n - 1)
            {
                return cost;
            }

            // Skip if the current cost is greater than the recorded distance
            if (cost > dist[x][y])
                continue;

            // Explore all possible directions
            for (int d = 0; d < 4; ++d)
            {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];

                // Check bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    // Cost is 0 if current sign points in the correct direction; otherwise, it's 1
                    int newCost = cost + (grid[x][y] == d + 1 ? 0 : 1);

                    // Update distance if a cheaper cost is found
                    if (newCost < dist[nx][ny])
                    {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }

        // If no path is found (though it should not happen), return -1
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
    cout << "Minimum cost: " << solution.minCost(grid) << endl;
    return 0;
}
