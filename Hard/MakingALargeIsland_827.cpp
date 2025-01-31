#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

class MakingALargeIsland_827 {
private:
    int n;
    std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return 0;

        std::unordered_map<int, int> island_sizes;  // Stores {island_id : size}
        int island_id = 2;  // Start from 2 to differentiate from 1s
        bool has_zero = false;

        // Step 1: Label all islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, island_id);
                    island_sizes[island_id] = size;
                    island_id++;
                }
                if (grid[i][j] == 0) has_zero = true;
            }
        }

        // Step 2: If there's no `0`, return the full grid size
        if (!has_zero) return n * n;

        // Step 3: Check every `0` to see which can give the largest island
        int max_island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> neighbor_islands;
                    for (auto& dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            neighbor_islands.insert(grid[ni][nj]);
                        }
                    }
                    int new_island_size = 1; // Converting `0` to `1`
                    for (int id : neighbor_islands) {
                        new_island_size += island_sizes[id];
                    }
                    max_island = std::max(max_island, new_island_size);
                }
            }
        }
        return max_island;
    }

private:
    int dfs(std::vector<std::vector<int>>& grid, int i, int j, int island_id) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return 0;

        grid[i][j] = island_id;
        int size = 1;

        for (auto& dir : directions) {
            size += dfs(grid, i + dir[0], j + dir[1], island_id);
        }
        return size;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{1, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    MakingALargeIsland_827 m1;
    std::cout << "Largest Island Size: " << m1.largestIsland(grid) << std::endl;
    return 0;
}
