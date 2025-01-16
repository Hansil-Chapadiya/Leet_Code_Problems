#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

class SmallestRangeCoveringFromKList_632
{
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>> &nums)
    {
        // Min-heap to store {value, row, column}
        using T = std::tuple<int, int, int>;
        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;

        // Track the maximum element in the current range
        int max_val = INT_MIN;

        // Step 1: Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push({nums[i][0], i, 0});
            max_val = std::max(max_val, nums[i][0]);
        }

        // Step 2: Initialize the result range
        std::vector<int> result = {INT_MIN, INT_MAX};

        // Step 3: Process the heap
        while (!pq.empty())
        {
            auto [min_val, row, col] = pq.top();
            pq.pop();

            // Check if the current range [min_val, max_val] is smaller than the previous best
            if (static_cast<long long>(max_val) - static_cast<long long>(min_val) < static_cast<long long>(result[1]) - static_cast<long long>(result[0]))
            {
                result = {min_val, max_val};
            }

            // Move to the next element in the same list
            if (col + 1 < nums[row].size())
            {
                int next_val = nums[row][col + 1];
                pq.push({next_val, row, col + 1});
                max_val = std::max(max_val, next_val);
            }
            else
            {
                // If any list is exhausted, we stop because we can no longer form a valid range
                break;
            }
        }

        return result;
    }
};

int main()
{
    SmallestRangeCoveringFromKList_632 solution;
    std::vector<std::vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    std::vector<int> result = solution.smallestRange(nums);
    std::cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
