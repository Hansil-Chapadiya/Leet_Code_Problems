#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
class FinalPricesWithSpecialDiscountShop_1475
{
private:
    /* data */
public:
    std::vector<int> finalPrices(std::vector<int> &prices)
    {
        std::vector<int> answer;
        std::stack<int> stk;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() > prices[i])
            {
                stk.pop();
            }
            if (stk.empty())
            {
                answer.push_back(prices[i]);
            }
            else
            {
                int new_element = prices[i] - stk.top();
                answer.push_back(new_element);
            }
            stk.push(prices[i]);
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
int main()
{
    FinalPricesWithSpecialDiscountShop_1475 f1;
    std::vector<int> prices = {8, 4, 6, 2, 3};
    std::vector<int> ans = f1.finalPrices(prices);
    for (auto i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();