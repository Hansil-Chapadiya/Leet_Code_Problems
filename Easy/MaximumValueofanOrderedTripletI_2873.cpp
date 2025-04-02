#include <iostream>
#include <vector>
#include <algorithm> // For std::max

class MaximumValueofanOrderedTripletI_2873
{
  public:
  long long maximumTripletValue(std::vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++ )
            {
                for(int k = j+1; k < n ; k++)
                {
                    // Convert one operand to long long before multiplication
                    long long tempValue = (1LL * (nums[i] - nums[j])) * nums[k];
                    maxValue = std::max(maxValue, tempValue);
                }
            }
        }
        return maxValue;
    }
};

int main()
{
    MaximumValueofanOrderedTripletI_2873 m1;
    std::vector<int> nums = {12,6,1,2,7};
    std::cout << m1.maximumTripletValue(nums) << std::endl;

    return 0;
}
