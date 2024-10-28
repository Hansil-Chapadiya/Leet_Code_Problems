#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
class LongestConsequtiveSequence_128
{
private:
    /* data */
public:
    int longestSquareStreak(const std::vector<int> &nums)
    {
        // Insert elements into an unordered_set to remove duplicates
        std::unordered_set<long long> unique_elements(nums.begin(), nums.end());
        long long max_count = 0;

        // Iterate through each element to find consecutive sequences
        for (long long num : unique_elements)
        {
            // Check if the number is the start of a sequence
            // if (unique_elements.find(num*num) == unique_elements.end())
            // {
            long long current_num = num;
            long long count = 0;

            // Count the length of the sequence
            while (unique_elements.find(current_num * current_num) != unique_elements.end())
            {
                current_num *= current_num;
                count += 1;
            }

            // Update maximum count of consecutive elements
            max_count = std::max(max_count, count);
            // }
        }

        return max_count ? max_count + 1 : -1;
    }
};
int main()
{
    LongestConsequtiveSequence_128 l1;
    // std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    // std::vector<int> nums = {4,3,6,16,8,2};
    std::vector<int> nums = {2, 3, 5, 6, 7};
    // std::vector<int> nums = {92682,18532};
    // std::vector<int> nums = {27,3,9,18,81};
    // std::vector<int> nums = {2,49,3,5,7,2401};
    // std::vector<int> nums = {81, 2, 4, 16, 3, 6561};
    std::cout << l1.longestSquareStreak(nums);
    return 0;
}

/*
Method 2:
std::vector<int> data = {4, 2, 5, 2, 3, 4, 1};

// Sort the vector
std::sort(data.begin(), data.end());

// Remove duplicates with std::unique and resize the vector
auto last = std::unique(data.begin(), data.end());
data.erase(last, data.end());  // Resize to remove undefined values after unique

// Output sorted unique values
for (int num : data) {
    std::cout << num << " ";
}

return 0;

 */
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();