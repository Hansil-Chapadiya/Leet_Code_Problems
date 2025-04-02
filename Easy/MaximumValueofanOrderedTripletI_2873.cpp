/* #include <iostream>
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
 */

 #include <iostream>
#include <vector>
#include <algorithm> // For std::max

class MaximumValueofanOrderedTripletI_2873 {
public:
    long long maximumTripletValue(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // Need at least 3 elements for a triplet

        long long maxTriplet = 0;
        long long maxValueSoFar = nums[0];  // Largest value seen so far
        long long maxDiffSoFar = LLONG_MIN; // Largest difference seen so far

        for (int i = 1; i < n; i++) {
            // Update maxTriplet using maxDiffSoFar and nums[i] (valid triplet condition)
            if (maxDiffSoFar != LLONG_MIN) {
                maxTriplet = std::max(maxTriplet, maxDiffSoFar * nums[i]);
            }

            // Update maxDiffSoFar using maxValueSoFar and nums[i] (valid difference condition)
            maxDiffSoFar = std::max(maxDiffSoFar, maxValueSoFar - 1LL * nums[i]);

            // Update maxValueSoFar to track the maximum value before index i
            maxValueSoFar = std::max(maxValueSoFar, 1LL * nums[i]);
        }
        return maxTriplet;
    }
};

int main() {
    MaximumValueofanOrderedTripletI_2873 m1;
    std::vector<int> nums = {12, 6, 1, 2, 7};
    std::cout << m1.maximumTripletValue(nums) << std::endl;

    return 0;
}
