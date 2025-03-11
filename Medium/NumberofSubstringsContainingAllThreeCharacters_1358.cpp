#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class NumberofSubstringsContainingAllThreeCharacters_1358
{
public:
    std::vector<std::string> substringSet;
    std::unordered_set<char> abcSet = {'a', 'b', 'c'};
    int numberOfSubstrings(std::string s)
    {
        int n = s.length();
        int subStrCnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 3; j <= n - i; j++)
            {
                substringSet.push_back(s.substr(i, j));
            }
        }

        for (auto &i : substringSet)
        {
            bool flag = true;
            std::unordered_set<char> strSet(i.begin(), i.end());
            for (char c : abcSet)
            {
                if (strSet.find(c) == strSet.end())
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                subStrCnt++;
            }
            // std::cout<<i <<" ";
        }
        return subStrCnt;
    }
};

int main()
{
    NumberofSubstringsContainingAllThreeCharacters_1358 n1;
    // std::cout<<n1.numberOfSubstrings("abcabc");
    // std::cout<<n1.numberOfSubstrings("aaacb");
    std::cout << n1.numberOfSubstrings("abc");

    return 0;
}