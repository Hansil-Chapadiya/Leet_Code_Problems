#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
class LongestConsequtiveSequence_128
{
private:
    /* data */
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::set<int> unique_elements(nums.begin(), nums.end());
        int diff = 1;
        int cnt = 1;
        auto iterator = unique_elements.begin();
        auto next_iterator = std::next(iterator);

        while (next_iterator != unique_elements.end())
        {
            diff = *next_iterator - *iterator;
            if (diff == 1)
            {
                cnt++;
            }

            ++iterator;
            ++next_iterator;
        }

        return cnt;
    }
};
int main()
{
    LongestConsequtiveSequence_128 l1;
    // std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
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