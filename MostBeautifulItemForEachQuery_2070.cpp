#include <iostream>
#include <vector>
#include <algorithm>
class MostBeautifulItemForEachQuery_2070
{
private:
    /* data */
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items, std::vector<int> &queries)
    {
        std::sort(items.begin(), items.end());
        std::vector<int> answer;
        for (auto &q : queries)
        {
            int max = 0;
            for (int i = 0; i < items.size(); i++)
            {
                if (items[i][0] <= q)
                {
                    max = std::max(max, items[i][1]);
                }
            }
            answer.push_back(max);
        }
        return answer;
    }
};
int main()
{
    MostBeautifulItemForEachQuery_2070 m1;
    // std::vector<std::vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    // std::vector<int> queries = {1, 2, 3, 4, 5, 6};

    std::vector<std::vector<int>> items = {{1, 2}, {1, 2}, {1, 3}, {1, 4}};
    std::vector<int> queries = {1};

    // std::vector<std::vector<int>> items = {{10,1000}};
    // std::vector<int> queries = {5};

    std::vector<int> answer = m1.maximumBeauty(items, queries);
    for (auto i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}