#include <iostream>
#include <vector>
#include <algorithm>

class HouseRobberIV
{
public:
    std::vector<int> nums;
    int k;

    bool isPossible(int mid)
    {
        int localK = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                localK++;
                i++; // Skip the NEXT house ONLY after robbing
            }
        }
        return localK >= k;
    }

    int minCapability(std::vector<int> &nums, int k)
    {
        this->nums = nums;
        this->k = k;
        int highElement = *std::max_element(nums.begin(), nums.end());
        int lowElement = *std::min_element(nums.begin(), nums.end());

        while (lowElement <= highElement)
        {
            int mid = (lowElement + highElement) / 2;
            if (isPossible(mid))
            {
                highElement = mid - 1;
            }
            else
            {
                lowElement = mid + 1;
            }
        }
        return lowElement;
    }
};

int main()
{
    HouseRobberIV h1;
    std::vector<int> nums = {2, 3, 5, 9};
    std::cout << h1.minCapability(nums, 2);
    return 0;
}
