#include <iostream>
#include <vector>
#include <unordered_map>

class CountTheServersThatCommunicate_1267
{
public:
    int countServers(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        std::unordered_map<int, int> row_cnt;
        std::unordered_map<int, int> col_cnt;

        // Count servers in each row and column
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    row_cnt[i]++;
                    col_cnt[j]++;
                }
            }
        }

        int communicableServer = 0;

        // Check servers
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && (row_cnt[i] > 1 || col_cnt[j] > 1))
                {
                    communicableServer++;
                }
            }
        }
        return communicableServer;
    }
};

int main()
{
    std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};
    CountTheServersThatCommunicate_1267 c1;
    std::cout << c1.countServers(grid);
    return 0;
}
