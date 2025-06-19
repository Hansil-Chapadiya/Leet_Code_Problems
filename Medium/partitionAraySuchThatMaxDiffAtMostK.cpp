#include <iostream>
#include <vector>
#include <algorithm>

class partitionAraySuchThatMaxDiffAtMostK
{

  public:
    // int partitionArray(std::vector<int>& nums, int k) {
    //     std::sort(nums.begin(),nums.end());

    //     int  i = 1;
    //     int cnt = 0;
    //     int n = nums.size();

    //     while (i < n)
    //     {
    //         int min = nums[i-1];
    //         while(((i+1) < n ) && (nums[i] - min) <= k)
    //         {
    //             i += 1;
    //         }
    //         cnt++;
    //         // i += 1;
    //     }

    //     return cnt;
    // }

    int partitionArray(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());

    int cnt = 0;
    int n = nums.size();
    int i = 0;

    while (i < n) {
        int start = i;

        // Extend the current group as long as max diff ≤ k
        while (i < n && nums[i] - nums[start] <= k) {
            i++;
        }

        cnt++;  // One group formed
    }

    return cnt;
}

};


int main()
{
    partitionAraySuchThatMaxDiffAtMostK p1;
    // std::vector<int> nums = {3,6,1,2,5};
    std::vector<int> nums = {1,2,3};
    // std::cout<<p1.partitionArray(nums, 2);
    std::cout<<p1.partitionArray(nums, 1);

    return 0;
}