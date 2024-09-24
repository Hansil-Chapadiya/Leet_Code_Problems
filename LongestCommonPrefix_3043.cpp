#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    // Array for child nodes of each node
    TrieNode *child[26];

    // for end of word
    bool wordEnd;

    TrieNode()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

// Method to insert a key into the Trie
void insertKey(TrieNode *root, const string &key)
{

    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c : key)
    {

        // Check if the node exists for the
        // current character in the Trie
        if (curr->child[c - 'a'] == nullptr)
        {

            // If node for current character does
            // not exist then make a new node
            TrieNode *newNode = new TrieNode();

            // Keep the reference for the newly
            // created node
            curr->child[c - 'a'] = newNode;
        }

        // Move the curr pointer to the
        // newly created node
        curr = curr->child[c - 'a'];
    }

    // Mark the end of the word
    curr->wordEnd = true;
}

// Method to search a key in the Trie
bool searchKey(TrieNode *root, const string &key)
{

    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c : key)
    {

        // Check if the node exists for the
        // current character in the Trie
        if (curr->child[c - 'a'] == nullptr)
            return false;

        // Move the curr pointer to the
        // already existing node for the
        // current character
        curr = curr->child[c - 'a'];
    }

    // Return true if the word exists
    // and is marked as ending
    return curr->wordEnd;
}

int main()
{

    // Create am example Trie
    TrieNode *root = new TrieNode();
    vector<string> arr =
        {"and", "ant", "do", "geek", "dad", "ball"};
    for (const string &s : arr)
    {
        insertKey(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys)
    {
        cout << "Key : " << s << "\n";
        if (searchKey(root, s))
            cout << "Present\n";
        else
            cout << "Not Present\n";
    }

    return 0;
}


// class LongestCommonPrefix_3043
// {
// private:
//     /* data */
// public:
//     LongestCommonPrefix_3043(/* args */);
//     ~LongestCommonPrefix_3043();
// };

// LongestCommonPrefix_3043::LongestCommonPrefix_3043(/* args */)
// {
// }

// LongestCommonPrefix_3043::~LongestCommonPrefix_3043()
// {
// }
