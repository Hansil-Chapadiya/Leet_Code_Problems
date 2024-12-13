#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <functional>

class FindScoreOfAnArrayAfterMarkingAllElement_2593
{
private:
    /* data */
public:
    long long findScore(std::vector<int> &nums)
    {
        std::priority_queue<std::tuple<int, int, bool>, std::vector<std::tuple<int, int, bool>>, std::greater<std::tuple<int, int, bool>>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i, false});
        }
    }
};
int main()
{
    FindScoreOfAnArrayAfterMarkingAllElement_2593 f1;
    std::vector<int> nums = {2,1,3,4,5,2};
    return 0;
}