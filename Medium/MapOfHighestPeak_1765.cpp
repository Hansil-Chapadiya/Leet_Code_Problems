/* #include <iostream>
#include <vector>
class MapOfHighestPeak_1765
{
private:
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();
        std::vector<std::vector<int>> answer(m, std::vector<int>(n, m + n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    answer[i][j] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        answer[i][j] = std::min(answer[i][j], answer[i - 1][j] + 1);
                    }
                    if (j > 0)
                    {
                        answer[i][j] = std::min(answer[i][j], answer[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i < m - 1)
                {
                    answer[i][j] = std::min(answer[i][j], answer[i + 1][j] + 1);
                }
                if (j < n - 1)
                {
                    answer[i][j] = std::min(answer[i][j], answer[i][j + 1] + 1);
                }
            }
        }
        return answer;
    }
};
int main()
{
    MapOfHighestPeak_1765 m1;
    std::vector<std::vector<int>> isWater = {{0, 1}, {0, 0}};
    std::vector<std::vector<int>> answer = m1.highestPeak(isWater);
    // for (auto element : answer)
    // {
    //     std::cout << element[0] << " " << element[1] << std::endl;
    // }
    for (int i = 0; i < answer.size(); i++)
    {
        for (size_t j = 0; j < answer[0].size(); j++)
        {
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

class MapOfHighestPeak_1765
{
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();
        std::vector<std::vector<int>> answer(m, std::vector<int>(n, -1));
        std::queue<std::pair<int, int>> q;

        // Initialize the queue with all water cells
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isWater[i][j] == 1)
                {
                    answer[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, right
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS to calculate the highest peak
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && answer[nx][ny] == -1)
                {
                    answer[nx][ny] = answer[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return answer;
    }
};

int main()
{
    MapOfHighestPeak_1765 m1;
    std::vector<std::vector<int>> isWater = {{0, 1}, {0, 0}};
    std::vector<std::vector<int>> answer = m1.highestPeak(isWater);

    for (const auto &row : answer)
    {
        for (int cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
