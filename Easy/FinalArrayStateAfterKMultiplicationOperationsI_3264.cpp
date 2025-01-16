#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
class FinalArrayStateAfterKMultiplicationOperationsI_3264
{
private:
    /* data */
public:
    std::vector<int> getFinalState(std::vector<int> &nums, int k, int multiplier)
    {
        // for (int i = 0; i < k; i++)
        // {
        //     auto min = std::min_element(nums.begin(), nums.end());
        //     int index = std::distance(nums.begin(), min);
        //     // std::cout << *min << " " << index << std::endl;
        //     nums[index] *= multiplier;
        //     // for (auto n : nums)
        //     // {
        //     //     std::cout << n << " ";
        //     // }
        //     // std::cout << std::endl;

        // }
        // return nums;

        int n = nums.size();
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

        for (int i = 0; i < n; i++)
        {
            minHeap.push({nums[i], i});
        }

        while (k)
        {
            auto [value, index] = minHeap.top();
            nums[index] = nums[index] * multiplier;
            minHeap.pop();
            minHeap.push({nums[index], index});
            k--;
        }
        return nums;
    }
};

int main()
{
    FinalArrayStateAfterKMultiplicationOperationsI_3264 f1;
    std::vector<int> nums = {2, 1, 3, 5, 6};
    std::vector<int> nums_ans = f1.getFinalState(nums, 5, 2);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
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