#include <iostream>
#include <vector>
#include <algorithm>

class MaxLoot
{
  public:
  int rob(std::vector<int> nums)
  {
      int n = nums.size();
      if (n == 0) return 0;
      if (n == 1) return nums[0];

      std::vector<int> dp(nums.size(), 0);

      dp[0] = nums[0];
      dp[1] = std::max(nums[0],nums[1]);

      for(int i = 2; i < n; i++)
      {
          dp[i] = std::max(dp[i-1], nums[i]+dp[i-2]);
      }
      return dp[n-1];
  }
};


int main()
{
    MaxLoot m1;
    std::vector<int> nums = {2, 7, 9, 3, 1};
    std::cout<<m1.rob(nums);

    return 0;
}