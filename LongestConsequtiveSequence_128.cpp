#include <iostream>
#include <unordered_set>
#include <vector>
class LongestConsequtiveSequence_128
{
private:
    /* data */
public:
    int longestConsecutive(const std::vector<int> &nums)
    {
        // Insert elements into an unordered_set to remove duplicates
        std::unordered_set<int> unique_elements(nums.begin(), nums.end());
        int max_count = 0;

        // Iterate through each element to find consecutive sequences
        for (int num : unique_elements)
        {
            // Check if the number is the start of a sequence
            if (unique_elements.find(num - 1) == unique_elements.end())
            {
                int current_num = num;
                int count = 1;

                // Count the length of the sequence
                while (unique_elements.find(current_num + 1) != unique_elements.end())
                {
                    current_num += 1;
                    count += 1;
                }

                // Update maximum count of consecutive elements
                max_count = std::max(max_count, count);
            }
        }

        return max_count;
    }
};
int main()
{
    LongestConsequtiveSequence_128 l1;
    // std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    std::cout << l1.longestConsecutive(nums);
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