#include <iostream>
#include <vector>
#include <queue>
#include <functional>
class MinimumOperationstoExceedThresholdValueII_3066
{
private:
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

public:
    int minOperations(std::vector<int> &nums, int k)
    {
        for (auto i : nums)
        {
            if (i >= k)
            {
                continue;
            }
            else
            {
                pq.push(i);
            }
        }
        int cnt = 0;
        while (!pq.empty())
        {
            if (pq.size() == 1)
                return cnt + 1;
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            long long val = 0;
            if (x < k && y < k)
            {
                val = std::min(x, y) * 2 + std::max(x, y);
                cnt++;
            }
            if (val < k)
                pq.push(val);
            std::cout << x << " " << y << std::endl;
        }
        return cnt;
    }
};
int main()
{
    // std::vector<int> nums = {2,11,10,1,3};
    // std::vector<int> nums = {1,1,2,4,9};
    std::vector<int> nums = {999999999, 999999999, 999999999};
    MinimumOperationstoExceedThresholdValueII_3066 m1;
    std::cout << m1.minOperations(nums, 1000000000);
    return 0;
}