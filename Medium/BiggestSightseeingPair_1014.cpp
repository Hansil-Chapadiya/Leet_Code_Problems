#include <iostream>
#include <vector>
#include <algorithm>

class BiggestSightseeingPair_1014
{
public:
    int maxScoreSightseeingPair(std::vector<int> &values)
    {
        int max_i = values[0]; // Initialize with the first element's value + index
        int max_score = 0;

        for (int j = 1; j < values.size(); j++)
        {
            // Calculate score for the pair (i, j) where i < j
            max_score = std::max(max_score, max_i + values[j] - j);

            // Update max_i for the next iteration
            max_i = std::max(max_i, values[j] + j);
        }
        return max_score;
    }
};

int main()
{
    BiggestSightseeingPair_1014 b1;
    std::vector<int> values = {8, 1, 5, 2, 6};
    std::cout << b1.maxScoreSightseeingPair(values);
    return 0;
}
