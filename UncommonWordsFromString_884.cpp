#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class UncommonWordsFromString_884
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        // Vector to store the uncommon words
        vector<string> result;

        // Map to store the frequency of each word
        unordered_map<string, int> wordCount;

        // Tokenizing and counting the words in the first string
        stringstream sstream1(s1);
        string token;
        while (sstream1 >> token) // This extracts words from the sstream1 stream, one by one, into the token variable.
        {
            wordCount[token]++;
        }

        // Tokenizing and counting the words in the second string
        stringstream sstream2(s2);
        while (sstream2 >> token)
        {
            /*
            It accesses the value associated with the word (or initializes it to 0 if the word has not been encountered before).
            It increments that value by 1, thereby counting the occurrence of the word.
            */
            wordCount[token]++;
        }

        // Find the words that appear exactly once
        for (auto &entry : wordCount)
        {
            if (entry.second == 1)
            {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};

int main()
{
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    UncommonWordsFromString_884 u1;
    vector<string> uncommonWords = u1.uncommonFromSentences(s1, s2);

    // Print the uncommon words
    for (const string &word : uncommonWords)
    {
        cout << word << " ";
    }

    return 0;
}

static const int hansil = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();