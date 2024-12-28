#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class MaximumSumof3Non_OverlappingSubarrays_689
{
public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        std::vector<int> sum_array(n - k + 1, 0);
        int current_sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        sum_array[0] = current_sum;

        for (int i = 1; i < sum_array.size(); i++)
        {
            current_sum += nums[i + k - 1] - nums[i - 1];
            sum_array[i] = current_sum;
        }

        std::vector<int> left_max(sum_array.size(), 0);
        int max_index = 0;
        for (int i = 0; i < sum_array.size(); i++)
        {
            if (sum_array[i] > sum_array[max_index])
            {
                max_index = i;
            }
            left_max[i] = max_index;
        }

        std::vector<int> right_max(sum_array.size(), 0);
        max_index = sum_array.size() - 1;
        for (int i = sum_array.size() - 1; i >= 0; i--)
        {
            if (sum_array[i] >= sum_array[max_index])
            {
                max_index = i;
            }
            right_max[i] = max_index;
        }

        int max_sum = 0;
        std::vector<int> answer(3, -1);

        for (int i = k; i < sum_array.size() - k; i++)
        {
            int left = left_max[i - k];
            int right = right_max[i + k];
            int total_sum = sum_array[left] + sum_array[i] + sum_array[right];

            if (total_sum > max_sum)
            {
                max_sum = total_sum;
                answer = {left, i, right};
            }
        }

        return answer;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    MaximumSumof3Non_OverlappingSubarrays_689 m1;
    std::vector<int> result = m1.maxSumOfThreeSubarrays(nums, 2);
    for (auto i : result)
    {
        std::cout << i << " ";
    }
    return 0;
}
