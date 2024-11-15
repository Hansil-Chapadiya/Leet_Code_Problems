#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int findLengthOfShortestSubarray(std::vector<int> &arr)
    {
        int endOfRight = arr.size() - 1;

        // Move `endOfRight` leftward to find the beginning of the longest non-decreasing suffix.
        while (endOfRight > 0 && arr[endOfRight] >= arr[endOfRight - 1])
        {
            endOfRight--;
        }

        // Initialize the answer with the size of the subarray from the start to `endOfRight`.
        int minLengthToRemove = endOfRight;

        int startOfLeft = 0;
        // Extend the non-decreasing prefix by moving `startOfLeft` rightward.
        while (startOfLeft < endOfRight && (startOfLeft == 0 || arr[startOfLeft - 1] <= arr[startOfLeft]))
        {

            // Move `endOfRight` rightward to find the next valid position for merging.
            while (endOfRight < arr.size() && arr[startOfLeft] > arr[endOfRight])
            {
                endOfRight++;
            }

            // Calculate and update the minimal subarray length to remove.
            minLengthToRemove = std::min(minLengthToRemove, endOfRight - startOfLeft - 1);
            startOfLeft++;
        }

        return minLengthToRemove;
    }
};
int main()
{
    Solution s1;
    std::vector<int> nums = {1, 2, 3, 10, 4, 2, 3, 5};

    std::cout << s1.findLengthOfShortestSubarray(nums);
    return 0;
}