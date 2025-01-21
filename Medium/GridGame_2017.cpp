#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
class GridGame_2017
{
private:
    /* data */
public:
    long long gridGame(std::vector<std::vector<int>> &grid)
    {
        long long first_row_sum = std::accumulate(grid[0].begin(), grid[0].end(), 0);
        long long second_row_sum = 0;

        long long minimum_sum = LONG_MAX;

        for (int i = 0; i < grid[0].size(); i++)
        {
            first_row_sum -= grid[0][i];

            minimum_sum = std::min(minimum_sum, std::max(first_row_sum, second_row_sum));
            second_row_sum += grid[1][i];
        }
        return minimum_sum;
    }
};
int main()
{
    GridGame_2017 g1;
    std::vector<std::vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};
    std::cout << g1.gridGame(grid);
    return 0;
}
