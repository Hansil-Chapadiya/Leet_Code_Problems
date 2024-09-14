#include <iostream>
#include <vector>
using namespace std;

class LongestSubarrayWithBitwise_2419
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxBitwiseAND = 0;  // To store the maximum bitwise AND found
        int longestLength = 0;  // To store the length of the longest subarray with maximum AND

        // Traverse through each subarray starting at index i
        for (int i = 0; i < nums.size(); i++)
        {
            int bitandop = nums[i];  // Initialize bitandop with the first element in the subarray

            // Traverse all subarrays starting at i and ending at j
            for (int j = i; j < nums.size(); j++)
            {
                bitandop = bitandop & nums[j];  // Update bitwise AND for subarray nums[i...j]
                cout << "Subarray (" << i << ", " << j << ") AND: " << bitandop << endl;

                // If the bitwise AND is greater than the current maxBitwiseAND
                if (bitandop > maxBitwiseAND)
                {
                    maxBitwiseAND = bitandop;  // Update the maximum bitwise AND
                    longestLength = j - i + 1;  // Update the length of the current subarray
                }
                // If the bitwise AND equals the maxBitwiseAND, check for the longest subarray
                else if (bitandop == maxBitwiseAND)
                {
                    longestLength = max(longestLength, j - i + 1);  // Take the maximum length
                }
            }
        }

        return longestLength;
    }
};

// int main()
// {
//     LongestSubarrayWithBitwise_2419 l1;
//     vector<int> nums = {1, 2, 3, 3, 2, 2};
//     cout << "Longest Subarray Length with Maximum Bitwise AND: " << l1.longestSubarray(nums) << endl;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>  // Needed for max_element
// using namespace std;

// class LongestSubarrayWithBitwise_2419
// {
// public:
//     int longestSubarray(vector<int> &nums)
//     {
//         // Find the maximum value in the array
//         int maxVal = *max_element(nums.begin(), nums.end());

//         int length = 0, currentLength = 0;

//         // Iterate through the array and find the longest subarray where every element equals maxVal
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == maxVal)
//             {
//                 // If the element equals the max value, extend the current subarray
//                 currentLength++;
//             }
//             else
//             {
//                 // If it's not equal, reset the current length counter
//                 currentLength = 0;
//             }
//             // Track the longest subarray found so far
//             length = max(length, currentLength);
//         }

//         return length;
//     }
// };

// int main()
// {
//     LongestSubarrayWithBitwise_2419 l1;
//     vector<int> nums = {1, 2, 3, 3, 2, 2};  // Test case

//     cout << "Longest subarray length with maximum bitwise AND: " << l1.longestSubarray(nums) << endl;

//     return 0;
// }

static const int hansil = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();