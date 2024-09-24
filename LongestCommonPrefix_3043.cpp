#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

/* class LongestPrefixFinder
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

    std::vector<int> arr1 = {5655359, 1223, 789, 12345};
    std::vector<int> arr2 = {56554, 122, 783};
    // std::vector<int> arr1 = {100, 10, 1}; // First array
    // std::vector<int> arr2 = {10, 101, 5}; // Second array

    // Insert all prefixes from arr1 into hashmap
    lpf.insertPrefixes(arr1, prefixMap);

    // Find the longest prefix from arr2
    int result = lpf.findLongestPrefix(arr2, prefixMap);

    std::cout << "Longest common prefix is: " << result << std::endl;

    return 0;
} */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    // Array for child nodes of each node
    TrieNode *child[10]; // Since we're dealing with digits 0-9, we only need 10 children

    // for end of word
    bool wordEnd;

    TrieNode()
    {
        wordEnd = false;
        for (int i = 0; i < 10; i++)
        {
            child[i] = nullptr;
        }
    }
};

// Method to insert a key into the Trie
void insertKey(TrieNode *root, const string &key)
{
    TrieNode *curr = root;
    for (char c : key)
    {
        int index = c - '0'; // Get the digit's index (0-9)
        if (curr->child[index] == nullptr)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->wordEnd = true; // Mark the end of the word
}

// Method to search for the longest common prefix
int findLongestPrefix(TrieNode *root, const string &key)
{
    TrieNode *curr = root;
    int prefixLength = 0;

    // Traverse the Trie and match characters as long as they exist
    for (char c : key)
    {
        int index = c - '0'; // Get the digit's index (0-9)
        if (curr->child[index] == nullptr)
        {
            break; // No more matching prefix
        }
        curr = curr->child[index];
        prefixLength++; // Increase the common prefix length
    }
    return prefixLength;
}

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    TrieNode *root = new TrieNode();

    // Step 1: Insert all numbers from arr1 into the Trie
    for (int num : arr1)
    {
        string numStr = to_string(num);
        insertKey(root, numStr);
    }

    // Step 2: Find the longest common prefix for each number in arr2
    int maxLength = 0;
    for (int num : arr2)
    {
        string numStr = to_string(num);
        int prefixLength = findLongestPrefix(root, numStr);
        maxLength = max(maxLength, prefixLength);
    }

    // Step 3: Return the maximum length of the longest common prefix found
    return maxLength;
}

int main()
{
    vector<int> arr1 = {5655359, 1223, 789, 12345};
    vector<int> arr2 = {56554, 122, 783};

    int result = longestCommonPrefix(arr1, arr2);
    cout << "Longest common prefix length: " << result << endl; // Expected: 3 (for prefix "565")

    return 0;
}

/* */
static const int hansil = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();