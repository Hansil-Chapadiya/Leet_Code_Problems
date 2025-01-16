#include <iostream>
#include <vector>
#include <algorithm>

class MostBeautifulItemForEachQuery_2070
{
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items, std::vector<int> &queries)
    {
        // Step 1: Sort items by price
        std::sort(items.begin(), items.end());

        // Step 2: Precompute maximum beauty up to each price
        std::vector<int> maxBeauty;
        std::vector<int> prices;
        int currentMaxBeauty = 0;

        for (const auto &item : items)
        {
            currentMaxBeauty = std::max(currentMaxBeauty, item[1]);
            prices.push_back(item[0]);
            maxBeauty.push_back(currentMaxBeauty);
        }

        for (auto &m : maxBeauty)
        {
            std::cout<<m<<" ";
        }
        std::cout<<std::endl;


        // Step 3: For each query, find the maximum beauty with binary search
        std::vector<int> answer;
        for (int q : queries)
        {
            auto it = std::upper_bound(prices.begin(), prices.end(), q);
            if (it == prices.begin())
            {
                // If query price is less than the minimum item price
                answer.push_back(0);
            }
            else
            {
                // Get the max beauty for items with price <= query price
                answer.push_back(maxBeauty[std::distance(prices.begin(), it) - 1]);
            }
        }
        return answer;
    }
};

int main()
{
    MostBeautifulItemForEachQuery_2070 m1;
    std::vector<std::vector<int>> items = {{1, 2}, {1, 2}, {1, 3}, {1, 4}};
    std::vector<int> queries = {1};

    std::vector<int> answer = m1.maximumBeauty(items, queries);
    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}
