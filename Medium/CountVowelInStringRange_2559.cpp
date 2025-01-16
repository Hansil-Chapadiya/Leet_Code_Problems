#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class CountVowelInStringRange_2559
{
private:
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c)
    {
        return vowels.find(c) != vowels.end();
    }

    bool startEndVowel(std::string s)
    {
        return isVowel(s[0]) && isVowel(s[s.length() - 1]);
    }

public:
    std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> prefix_sum;
        std::vector<int> answer;
        int current_sum = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (startEndVowel(words[i]))
            {
                current_sum++;
            }
            prefix_sum.push_back(current_sum);
        }

        for (auto q : queries)
        {
            if (q[0] == 0)
            {
                answer.push_back(prefix_sum[q[1]]);
            }
            else
            {
                answer.push_back(prefix_sum[q[1]] - prefix_sum[q[0] - 1]);
            }
        }
        return answer;
    }
};

int main()
{
    std::vector<std::string> words = {"apple", "orange", "banana", "umbrella", "egg", "iguana", "onion"};
    std::vector<std::vector<int>> queries = {{0, 2}, {0, 3}, {1, 3}};
    CountVowelInStringRange_2559 c1;
    std::vector<int> answer = c1.vowelStrings(words, queries);
    for (auto i : answer)
    {
        std::cout << i << " ";
    }
    return 0;
}

static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
