#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

class LongestConsequtiveSequence_128
{
public:
    int longestSquareStreak(std::vector<int> &nums)
    {
        std::map<int, int> mp;
        std::sort(nums.begin(), nums.end());
        int res = -1;
        for (int num : nums)
        {
            int _sqrt = std::sqrt(num);
            if (_sqrt * _sqrt == num && mp.find(_sqrt) != mp.end())
            {
                mp[num] = mp[_sqrt] + 1;
                res = std::max(res, mp[num]);
            }
            else
                mp[num] = 1;
        }
        return res;
    }
};

int main()
{
    LongestConsequtiveSequence_128 l1;
    // std::vector<int> nums = {81, 2, 4, 16, 3, 6561};
    std::vector<int> nums = {2, 3, 5, 6, 7};
    std::cout << l1.longestSquareStreak(nums);
    return 0;
}

/*
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Insert elements into an unordered_set to remove duplicates
        std::unordered_set<long long> unique_elements(nums.begin(), nums.end());
        long long max_count = 0;

        // Iterate through each element to find consecutive sequences
        for (long long num : unique_elements) {
            long long current_num = num;
            long long count = 0;

            // Count the length of the sequence
            while (unique_elements.find(current_num * current_num) !=
                   unique_elements.end()) {
                current_num *= current_num;
                count += 1;
            }

            // Update maximum count of consecutive elements
            max_count = std::max(max_count, count);
        }
        return max_count ? max_count+1 : -1;
    }
};
*/
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();