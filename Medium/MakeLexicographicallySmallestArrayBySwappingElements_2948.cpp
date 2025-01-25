#include <iostream>
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
}


