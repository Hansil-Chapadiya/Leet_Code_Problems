#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class CountTheNumberOfConsistentString_1684
{
private:
    char findMissingChar(const string &allowed, const string &word)
    {
        // Convert string `allowed` to a set of characters
        unordered_set<char> charSet(allowed.begin(), allowed.end());

        // Iterate through `word` and find a character not in `allowed`
        for (char c : word)
        {
            // charset.end() because if char not found then it return last
            if (charSet.find(c) == charSet.end())
            {
                return c; // Return the first character that is not in `allowed`
            }
        }
        return '\0'; // If no such character is found, return null character
    }

public:
    int countConsistentStrings(const string &allowed, vector<string> &words)
    {
        int cnt = words.size(); // Start with the total number of words

        for (int i = 0; i < words.size(); i++)
        {
            if (findMissingChar(allowed, words[i]) != '\0') // Check if any inconsistent char is found
            {
                cnt--; // Decrease count for inconsistent words
            }
        }
        return cnt; // Return the number of consistent words
    }
};

int main()
{
    CountTheNumberOfConsistentString_1684 obj;

    vector<string> words = {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
    string allowed = "cad";

    int result = obj.countConsistentStrings(allowed, words);

    cout << "Number of consistent strings: " << result << endl; // Output should be 4

    return 0;
}
