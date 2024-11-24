#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
class MaximumMatrixSum_1975
{
private:
    /* data */
public:
    long long maxMatrixSum(std::vector<std::vector<int>> &matrix)
    {
        long long sum = 0;
        int count_negative = 0;
        int min_element = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                sum += std::abs(matrix[i][j]);
                min_element = std::min(min_element, std::abs(matrix[i][j]));
                if (matrix[i][j] < 0)
                {
                    count_negative++;
                }
            }
        }

        if (count_negative % 2 != 0)
        {
            return sum - (2 * min_element);
        }
        return sum;
    }
};
int main()
{
    std::vector<std::vector<int>> matrix = {{1, -1}, {-1, 1}};
    MaximumMatrixSum_1975 m1;
    std::cout<<m1.maxMatrixSum(matrix);
    return 0;
}