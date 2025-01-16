#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class RotateString_796
{
private:
    std::vector<std::string> str;
    void shift_operation(std::string s, std::string goal)
    {
        for (int i = 0; i < s.length(); i++)
        {
            str.push_back(s.substr(i, s.length()) + s.substr(0, i));
        }
    }

public:
    bool rotateString(std::string s, std::string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }

        shift_operation(s, goal);
        for (const auto &s_ : str)
        {
            if (s_.find(goal) != std::string::npos)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    RotateString_796 r1;
    // std::cout<<r1.rotateString("abcde", "cdeab");
    // std::cout<<r1.rotateString("abcde", "abced");
    // std::cout<<r1.rotateString("a", "a");
    // std::cout<<r1.rotateString("bcad", "cdba");
    // std::cout<<r1.rotateString("abcd", "abcd");
    std::cout<<r1.rotateString("aa", "a");
    return 0;
}