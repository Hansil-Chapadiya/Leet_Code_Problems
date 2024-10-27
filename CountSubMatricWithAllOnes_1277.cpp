#include <iostream>
#include <vector>
#include <algorithm>
class CountSubMatricWithAllOnes_1277
{
private:
    /* data */
public:
    int countSquare(std::vector<std::vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        std::vector<std::vector<int>> dp(r + 1, std::vector<int>(c + 1, 0));
        int answer = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 1)
                {
                    dp[i + 1][j + 1] = std::min({dp[i + 1][j], dp[i][j + 1], dp[i][j]}) + 1;
                    answer += dp[i + 1][j + 1];
                }
            }
        }
        return answer;
    }
};
int main()
{
    CountSubMatricWithAllOnes_1277 c1;
    std::vector<std::vector<int>> matrix = {{0, 1, 1, 1},
                                            {1, 1, 1, 1},
                                            {0, 1, 1, 1}};
    std::cout<<c1.countSquare(matrix);
    return 0;
}
