#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class Solution
{
private:
    std::string firstRow = "qwertyuiop";
    std::string secondRow = "asdfghjkl";
    std::string thirdRow = "zxcvbnm";
    std::vector<std::string> answer;

public:
    std::vector<std::string> findWords(std::vector<std::string> &words)
    {
        for (auto s : words)
        {
            int sLen = s.length();
            int cnt = 0;
            for (auto c : s)
            {
                if (firstRow.find(std::tolower(c)) != std::string::npos)
                {
                    cnt++;
                }
            }
            if (cnt == sLen)
            {
                answer.push_back(s);
                continue;
            }

            cnt = 0;
            for (auto c : s)
            {
                if (secondRow.find(std::tolower(c)) != std::string::npos)
                {
                    cnt++;
                }
            }
            if (cnt == sLen)
            {
                answer.push_back(s);
                continue;
            }

            cnt = 0;
            for (auto c : s)
            {
                if (thirdRow.find(std::tolower(c)) != std::string::npos)
                {
                    cnt++;
                }
            }
            if (cnt == sLen)
            {
                answer.push_back(s);
                continue;
            }
        }
        return answer;
    }
};
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();