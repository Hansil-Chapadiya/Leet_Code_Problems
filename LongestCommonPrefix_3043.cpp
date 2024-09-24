#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class LongestPrefixFinder
{
public:
    // Function to store all prefixes in hashmap
    void insertPrefixes(const std::vector<int> &arr1, std::unordered_map<std::string, int> &prefixMap)
    {
        for (int num : arr1)
        {
            std::string numStr = std::to_string(num);
            // Insert all possible prefixes into hashmap
            for (int i = 1; i <= numStr.length(); i++)
            {
                std::string prefix = numStr.substr(0, i);
                prefixMap[prefix] = num; // store the original number corresponding to the prefix
            }
        }
    }

    // Function to find the longest common prefix in arr2
    int findLongestPrefix(const std::vector<int> &arr2, std::unordered_map<std::string, int> &prefixMap)
    {
        int longestPrefix = -1;
        for (int num : arr2)
        {
            std::string numStr = std::to_string(num);
            for (int i = numStr.length(); i > 0; i--)
            {
                std::string prefix = numStr.substr(0, i);
                if (prefixMap.find(prefix) != prefixMap.end())
                {
                    return prefixMap[prefix]; // Return the longest prefix match
                }
            }
        }
        return longestPrefix; // No match found
    }
};

int main()
{
    LongestPrefixFinder lpf;
    std::unordered_map<std::string, int> prefixMap;

    std::vector<int> arr1 = {100, 10, 1}; // First array
    std::vector<int> arr2 = {10, 101, 5}; // Second array

    // Insert all prefixes from arr1 into hashmap
    lpf.insertPrefixes(arr1, prefixMap);

    // Find the longest prefix from arr2
    int result = lpf.findLongestPrefix(arr2, prefixMap);

    std::cout << "Longest common prefix is: " << result << std::endl;

    return 0;
}

/* */
