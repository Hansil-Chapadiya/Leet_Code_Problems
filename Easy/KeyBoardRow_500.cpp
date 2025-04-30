/* #include <iostream>
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
}(); */


#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class KeyBoardRow_500
{
  private:
    std::unordered_set<char> firstRow=  {'q','w','e','r','t','y','u','i','o','p'};
    std::unordered_set<char> secondRow = {'a','s','d','f','g','h','j','k','l'};
    std::unordered_set<char> thirdRow = {'x','c','v','b','m','n','z'};
    std::vector<std::string> answer;
  public:
    std::vector<std::string> findWords(std::vector<std::string>& words)
    {
        for(auto s : words)
        {
            int sLen = s.length();
            int cnt = 0;
            for (auto c : s)
            {
                if(firstRow.find(std::tolower(c)) != firstRow.end())
                {
                    cnt++;
                }

            }
            if(cnt == sLen)
            {
                answer.push_back(s);
                continue;
            }

            cnt = 0;
            for (auto c : s)
            {
                if(secondRow.find(std::tolower(c)) != secondRow.end())
                {
                    cnt++;
                }

            }
            if(cnt == sLen)
            {
                answer.push_back(s);
                continue;
            }

            cnt = 0;
            for (auto c : s)
            {
                if(thirdRow.find(std::tolower(c)) != thirdRow.end())
                {
                    cnt++;
                }

            }
            if(cnt == sLen)
            {
                answer.push_back(s);
                continue;
            }
        }
        return answer;
    }
};


int main()
{
    std::vector<std::string> words = {"Hello","Alaska","Dad","Peace"};

    KeyBoardRow_500 k1;
    std::vector<std::string> answer = k1.findWords(words);

    for(auto s : answer)
    {
        std::cout<<s<<" ";
    }

    return 0;
}