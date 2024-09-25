#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26]; // Since we're dealing with lowercase letters 'a' to 'z'
    int prefixCount;     // Store the count of words that pass through this node

    TrieNode()
    {
        prefixCount = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

// Method to insert a word into the Trie and update prefix counts
void insertKey(TrieNode *root, const string &key)
{
    TrieNode *curr = root;
    for (char c : key)
    {
        int index = c - 'a'; // Get the index for the letter (0-25)
        if (curr->child[index] == nullptr)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
        curr->prefixCount++; // Increment the prefix count at this node
    }
}

// Method to calculate the prefix score for a word
int calculatePrefixScore(TrieNode *root, const string &key)
{
    TrieNode *curr = root;
    int score = 0;

    // Traverse the Trie and sum up the prefix counts
    for (char c : key)
    {
        int index = c - 'a'; // Get the index for the letter (0-25)
        if (curr->child[index] == nullptr)
        {
            break; // No more matching prefix
        }
        curr = curr->child[index];
        score += curr->prefixCount; // Add the prefix count at the current node
    }

    return score;
}

class SumOfPrefixScore_2416
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        vector<int> result;
        TrieNode *root = new TrieNode();

        // Step 1: Insert all words into the Trie
        for (string &word : words)
        {
            insertKey(root, word);
        }

        // Step 2: Calculate prefix score for each word
        for (string &word : words)
        {
            int prefixScore = calculatePrefixScore(root, word);
            result.push_back(prefixScore);
        }

        return result;
    }
};

int main()
{
    SumOfPrefixScore_2416 s1;
    vector<string> words = {"abc", "ab", "bc", "b"};
    vector<int> result = s1.sumPrefixScores(words);

    for (int score : result)
    {
        cout << score << " ";
    }
    return 0;
}
