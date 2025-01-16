#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
class WordSubSet_916
{
private:
    /* data */
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
        std::unordered_map<char, int> max_freq_word2;
        for (const auto &word : words2)
        {
            std::unordered_map<char, int> temp_freq;
            for (char c : word)
            {
                temp_freq[c]++;
                max_freq_word2[c] = std::max(max_freq_word2[c], temp_freq[c]);
            }
        }

        std::vector<std::string> answer;
        for (auto word : words1)
        {
            int flag = 1;
            std::unordered_map<char, int> freq_cnt;
            for (auto c : word)
            {
                freq_cnt[c]++;
            }
            for (auto c : max_freq_word2)
            {
                if (freq_cnt[c.first] < c.second)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                answer.push_back(word);
            }

            freq_cnt.clear();
        }
        return answer;
    }
};
int main()
{
    std::vector<std::string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> words2 = {"e", "o"};
    WordSubSet_916 w1;
    std::vector<std::string> answer = w1.wordSubsets(words1, words2);
    for (auto word : answer)
    {
        std::cout << word << " ";
    }

    return 0;
}