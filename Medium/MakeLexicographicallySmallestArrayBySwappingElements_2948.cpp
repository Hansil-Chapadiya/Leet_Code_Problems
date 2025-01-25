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


/* #include <iostream>
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
 */

#include <iostream>
#include <vector>
#include <algorithm>

class MakeLexicographicallySmallestArrayBySwappingElements_2948
{
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int> &nums, int limit)
    {
        std::vector<std::pair<int, int>> valueIndexPairs;
        int size = nums.size();

        // Step 1: Create pairs of (value, index)
        for (int i = 0; i < size; ++i)
        {
            valueIndexPairs.push_back({nums[i], i});
        }

        // Step 2: Sort pairs based on values
        std::sort(valueIndexPairs.begin(), valueIndexPairs.end());

        // Step 3: Group adjacent pairs based on the threshold
        std::vector<std::vector<std::pair<int, int>>> groupedPairs;
        groupedPairs.push_back({valueIndexPairs[0]});

        for (int i = 1; i < size; ++i)
        {
            if (valueIndexPairs[i].first - valueIndexPairs[i - 1].first <= limit)
            {
                groupedPairs.back().push_back(valueIndexPairs[i]);
            }
            else
            {
                groupedPairs.push_back({valueIndexPairs[i]});
            }
        }

        // Step 4: Process each group to sort indices and reassign values
        for (const auto &group : groupedPairs)
        {
            std::vector<int> indices;
            for (const auto &[value, index] : group)
            {
                indices.push_back(index);
            }

            // Sort indices in ascending order
            std::sort(indices.begin(), indices.end());

            // Assign sorted values back to nums at the sorted indices
            for (size_t i = 0; i < indices.size(); ++i)
            {
                nums[indices[i]] = group[i].first;
            }
        }

        return nums;
    }
};

int main()
{
    std::vector<int> nums = {1, 60, 34, 84, 62, 56, 39, 76, 49, 38};
    int limit = 4;

    MakeLexicographicallySmallestArrayBySwappingElements_2948 solver;
    std::vector<int> result = solver.lexicographicallySmallestArray(nums, limit);

    for (int num : result)
    {
        std::cout << num << " ";
    }
    return 0;
}
