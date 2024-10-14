#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
class MaximumScoreAfterApplyingKOperation_2530
{
private:
public:
    long long maxKelements(std::vector<int> &nums, int k)
    {
        // Use a max-heap (priority queue) to keep track of the maximum element
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());

        long long score = 0;

        while (k > 0)
        {
            // Get the maximum element (the top of the heap)
            int maxElement = maxHeap.top();
            maxHeap.pop();

            // Add the maximum element to the score
            score += (long long)maxElement;

            // Divide the maximum element by 3, and round up using std::ceil
            int newElement = std::ceil(maxElement / 3.0);

            // Push the updated element back into the heap
            maxHeap.push(newElement);

            // Decrement the number of remaining operations
            k--;
        }

        return score;
    }
};
int main()
{
    MaximumScoreAfterApplyingKOperation_2530 m1;
    std::vector<int> nums = {1, 10, 3, 3, 3};
    // std::vector<int> nums = {10, 10, 10, 10, 10};
    std::cout << m1.maxKelements(nums, 3);
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/* TLE logic
 long long score = 0;
        while (k > 0)
        {
            auto max = std::max_element(nums.begin(), nums.end());
            auto index = std::distance(nums.begin(), max);
            score += (long long)nums[index];
            nums[index] = std::ceil(nums[index] / 3.0);
            // std::cout << nums[index]<< " ";
            k--;
        }
        return score; */