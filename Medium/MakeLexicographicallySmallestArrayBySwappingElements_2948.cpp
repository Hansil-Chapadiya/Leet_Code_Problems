/* #include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class MakeLexicographicallySmallestArrayBySwappingElements_2948
{
private:
    // Helper function to compare two arrays lexicographically
    std::vector<int> getSmallLexo(std::vector<int> arr1, std::vector<int> arr2)
    {
        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] > arr2[i])
            {
                return arr2;
            }
            else if (arr2[i] > arr1[i])
            {
                return arr1;
            }
        }
        return arr1; // If both arrays are equal
    }

public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int> &nums, int limit)
    {
        std::vector<int> answer(nums.begin(), nums.end());
        int n = nums.size();

        // Brute-force: Try every possible swap
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && std::abs(nums[i] - nums[j]) <= limit)
                {
                    // Create a copy of the array and swap
                    std::vector<int> temp(nums.begin(), nums.end());
                    std::swap(temp[i], temp[j]);

                    // Compare the new array with the current smallest
                    answer = getSmallLexo(temp, answer);
                }
            }
        }

        // Print the result
        for (int i = 0; i < answer.size(); i++)
        {
            std::cout << answer[i] << " ";
        }
        return answer;
    }
};

int main()
{
    std::vector<int> nums = {1, 5, 3, 9, 8};
    MakeLexicographicallySmallestArrayBySwappingElements_2948 m1;
    m1.lexicographicallySmallestArray(nums, 2);
    return 0;
}*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class MakeLexicographicallySmallestArrayBySwappingElements_2948
{
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int> &nums, int limit)
    {
        bool swapped;
        do
        {
            swapped = false;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    // Check if a swap is beneficial and within the limit
                    if (nums[i] > nums[j] && std::abs(nums[i] - nums[j]) <= limit)
                    {
                        std::swap(nums[i], nums[j]);
                        swapped = true; // Mark that a swap occurred
                    }
                }
            }
        } while (swapped); // Repeat until no swaps are made

        // Print the result
        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i] << " ";
        }
        return nums;
    }
};

int main()
{
    std::vector<int> nums = {1, 60, 34, 84, 62, 56, 39, 76, 49, 38};
    MakeLexicographicallySmallestArrayBySwappingElements_2948 m1;
    m1.lexicographicallySmallestArray(nums, 4);
    return 0;
}
