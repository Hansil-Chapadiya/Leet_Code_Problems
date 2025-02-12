// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// class MaxSumOfPairWithEqualSumDigits_2342
// {
// private:
//     std::unordered_map<int, std::vector<int>> uMap;
//     int sumOfDigit(int digit)
//     {
//         int sum = 0;
//         while (digit > 0)
//         {
//             int rem = digit % 10;
//             sum += rem;
//             digit /= 10;
//         }
//         return sum;
//     }

// public:
//     int maximumSum(std::vector<int> &nums)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             uMap[sumOfDigit(nums[i])].push_back(nums[i]);
//         }
//         for (auto &i : uMap)
//         {
//             std::sort(i.second.begin(), i.second.end(), std::greater<int>());
//         }
//         int sum = 0;
//         int max = 0;
//         for (auto i : uMap)
//         {
//             std::cout << i.first << " ->";
//             sum = 0;
//             if (i.second.size() == 1)
//             {
//                 // sum += i.second[0];
//                 // std::cout << i.second[0] << std::endl;
//                 continue;
//             }
//             else
//             {
//                 for (int j = 0; j < 2; j++)
//                 {
//                     sum += i.second[j];
//                     std::cout << i.second[j] << " ";
//                 }
//             }

//             max = std::max(max, sum);
//             std::cout << std::endl;
//         }
//         return max == 0 ? -1 : max;
//     }
// };
// int main()
// {
//     MaxSumOfPairWithEqualSumDigits_2342 m1;
//     std::vector<int> nums = {18, 43, 36, 13, 7};
//     // std::vector<int> nums = {10,12,19,14};
//     std::cout << m1.maximumSum(nums);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class MaxSumOfPairWithEqualSumDigits_2342
{
private:
    std::unordered_map<int, std::priority_queue<int>> uMap;

    int sumOfDigit(int digit)
    {
        int sum = 0;
        while (digit > 0)
        {
            sum += digit % 10;
            digit /= 10;
        }
        return sum;
    }

public:
    int maximumSum(std::vector<int> &nums)
    {
        // Step 1: Populate unordered_map with max heaps
        for (int num : nums)
        {
            uMap[sumOfDigit(num)].push(num);
        }

        int maxSum = -1;  // Default return value if no valid pairs exist

        // Step 2: Find the max sum of the top two numbers for each digit sum
        for (auto &pair : uMap)
        {
            std::priority_queue<int> &pq = pair.second;
            if (pq.size() >= 2)
            {
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                maxSum = std::max(maxSum, first + second);
            }
        }

        return maxSum;
    }
};

int main()
{
    MaxSumOfPairWithEqualSumDigits_2342 m1;
    std::vector<int> nums = {18, 43, 36, 13, 7};
    std::cout << m1.maximumSum(nums) << std::endl;
    return 0;
}
