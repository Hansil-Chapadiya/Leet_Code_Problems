#include <iostream>
#include <vector>
#include <queue>

class BiggestSightseeingPair_1014
{
private:
    /* data */
public:
    int maxScoreSightseeingPair(std::vector<int> &values)
    {
        std::priority_queue<int> maxheap;
        for (int i = 0; i < values.size(); i++)
        {
            for (int j = i + 1; j < values.size(); j++)
            {
                maxheap.push(values[i] + values[j] - (j - i));
            }
        }
        return maxheap.top();
    }
};
int main()
{
    BiggestSightseeingPair_1014 b1;
    std::vector<int> values = {8, 1, 5, 2, 6};
    std::cout << b1.maxScoreSightseeingPair(values);
    return 0;
}