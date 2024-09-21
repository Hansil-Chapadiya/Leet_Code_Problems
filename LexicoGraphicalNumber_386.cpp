#include <iostream>
#include <vector>
#include <map>
#include <string>

// //produce wrong output
class LexicoGraphicalNumber_wrong
{
private:
    // Helper function to check if a number starts with a given prefix
    bool matchesPrefix(int number, int prefix)
    {
        // Convert both number and prefix to string to compare their starting characters
        std::string strNumber = std::to_string(number);
        std::string strPrefix = std::to_string(prefix);

        // Check if the number starts with the prefix
        return strNumber.substr(0, strPrefix.length()) == strPrefix;
    }

public:
    std::vector<int> lexicalOrder(int n)
    {
        // Step 1: Create a map to store numbers based on their prefix (1 to 9)
        std::map<int, std::vector<int>> map_arr;

        // Step 2: Loop through numbers from 1 to n
        for (int i = 1; i <= n; i++) // Start from 1, not 0
        {
            // Check if the number starts with each prefix from 1 to 9
            for (int key = 1; key <= 9; key++)
            {
                if (matchesPrefix(i, key))
                {
                    // Store the number in the corresponding vector based on prefix
                    map_arr[key].push_back(i);
                }
            }
        }

        // Step 3: Merge all vectors in the map into a single vector in lexicographical order
        std::vector<int> mergedVector;
        for (auto &pair : map_arr)
        {
            mergedVector.insert(mergedVector.end(), pair.second.begin(), pair.second.end());
        }

        // Return the merged vector
        return mergedVector;
    }
};

// // int main()
// // {
// //     LexicoGraphicalNumber l1;
// //     std::vector<int> result = l1.lexicalOrder(25);

// //     // Output the result
// //     std::cout << "Lexicographical order: ";
// //     for (int num : result)
// //     {
// //         std::cout << num << " ";
// //     }
// //     std::cout << std::endl;

// //     return 0;
// // }
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
