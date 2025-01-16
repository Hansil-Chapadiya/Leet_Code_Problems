#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class SentenceSimilarityIII_1813
{
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2)
    {
        // Step 1: Split both sentences into word vectors
        std::vector<std::string> s1_arr = splitSentence(sentence1);
        std::vector<std::string> s2_arr = splitSentence(sentence2);

        // Make sure s1_arr is always the smaller or equal sized sentence
        if (s1_arr.size() > s2_arr.size())
            std::swap(s1_arr, s2_arr);

        int left = 0, right = 0;
        int n = s1_arr.size(), m = s2_arr.size();
        // Step 2: Match from the left side
        while (left < n && s1_arr[left] == s2_arr[left])
            left++;
        // Step 3: Match from the right side
        while (right < n && s1_arr[n - right - 1] == s2_arr[m - right - 1])
            right++;
        // Step 4: Check if the matched prefix and suffix cover the entire s1_arr
        return left + right >= n;
    }

private:
    // Helper function to split the sentence into words
    std::vector<std::string> splitSentence(const std::string &sentence)
    {
        std::vector<std::string> words;
        std::stringstream ss(sentence);
        std::string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        return words;
    }
};

int main()
{
    SentenceSimilarityIII_1813 s1;
    std::cout << std::boolalpha;
    // std::cout << s1.areSentencesSimilar("Hello Jane", "Hello my name is Jane") << std::endl; // Should return true
    std::cout << s1.areSentencesSimilar("My name is Haley", "My Haley") << std::endl; // Should return true
    // std::cout << s1.areSentencesSimilar("of", "A lot of words") << std::endl;                // Should return false
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();