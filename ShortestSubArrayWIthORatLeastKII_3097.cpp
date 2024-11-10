#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class ShortestSubArrayWithORAtLeastK
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        vector<int> bitCount(32, 0); // Track count of each bit set across the current window
        int start = 0, end = 0;      // Window pointers
        int minLength = INT_MAX;     // Store the minimum length of the special subarray

        // Expand the window by moving `end` to the right
        while (end < nums.size())
        {
            // Update bit counts for the element at `end` by adding its bits to `bitCount`
            updateBits(bitCount, nums[end], 1);

            // Shrink the window from the left as long as the OR condition is satisfied
            while (start <= end && getVal(bitCount) >= k)
            {
                // Update the minimum length if the current window meets the condition
                minLength = min(minLength, end - start + 1);

                // Remove the bits of `nums[start]` from `bitCount` as we move `start` right
                updateBits(bitCount, nums[start], -1);
                start++; // Move start to shrink the window
            }
            end++; // Move end to expand the window
        }

        // If minLength remains `INT_MAX`, no valid subarray was found; return -1
        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    // Updates `bitCount` for each bit position based on the `num` being added or removed.
    void updateBits(vector<int> &bitCount, int num, int delta)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) & 1)
            {                         // Check if the i-th bit is set in `num`
                bitCount[i] += delta; // Add or subtract from bitCount[i]
            }
        }
    }

    // Calculates the OR value of the current window based on `bitCount`.
    int getVal(const vector<int> &bitCount)
    {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bitCount[i] > 0)
            {                       // If any number in the window has the i-th bit set
                result |= (1 << i); // Set the i-th bit in the result
            }
        }
        return result;
    }
};
int main()
{
    ShortestSubArrayWithORAtLeastK solution;
    std::vector<int> nums = {1, 2, 3};
    int k = 2;
    cout << solution.minimumSubarrayLength(nums, k) << endl; // Output: 1
    return 0;
}