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

        // Step 2: Precompute maximum beauty up to each unique price
        std::vector<int> prices;
        std::vector<int> maxBeauty;
        int currentMaxBeauty = 0;

        for (const auto &item : items)
        {
            // Only update prices and maxBeauty when we encounter a new price
            if (prices.empty() || prices.back() != item[0])
            {
                prices.push_back(item[0]);
                maxBeauty.push_back(currentMaxBeauty); // Record max beauty up to previous price
            }
            currentMaxBeauty = std::max(currentMaxBeauty, item[1]); // Update max beauty seen so far
            maxBeauty.back() = currentMaxBeauty;                    // Update max beauty for the current price
        }

        // Step 3: For each query, find the maximum beauty with binary search
        std::vector<int> answer;
        for (int q : queries)
        {
            auto it = std::upper_bound(prices.begin(), prices.end(), q);
            if (it == prices.begin())
            {
                answer.push_back(0); // No prices are affordable
            }
            else
            {
                answer.push_back(maxBeauty[std::distance(prices.begin(), it) - 1]);
            }
        }
        return answer;
    }
};

int main()
{
    MostBeautifulItemForEachQuery_2070 m1;
    std::vector<std::vector<int>> items = {{1, 2}, {1, 5}, {2, 3}, {2, 4}};
    std::vector<int> queries = {1, 2, 3};

    std::vector<int> answer = m1.maximumBeauty(items, queries);
    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}
