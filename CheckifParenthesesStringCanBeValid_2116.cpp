/* #include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

class CheckifParenthesesStringCanBeValid_2116
{
private:
public:
    bool canBeValid(std::string s, std::string locked)
    {
        if (s.length() % 2 == 1)
        {
            return false;
        }

        std::unordered_map<char, int> bracket_track;
        for (auto c : s)
        {
            bracket_track[c]++;
        }
        if (bracket_track['('] == bracket_track[')'])
        {
            return true;
        }

        auto max = *std::max_element(bracket_track.begin(), bracket_track.end());
        auto min = *std::min_element(bracket_track.begin(), bracket_track.end());
        std::cout << max.first << " " << max.second;
        std::cout << min.first << " " << min.second;

        for (int i = 0; i < locked.size(); i++)
        {
            if (s[i] == max.first && locked[i] != 1)
            {
                // s[i] = min.first;
                max.second--;
                min.second++;
            }
            if (max.second == min.second)
            {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    CheckifParenthesesStringCanBeValid_2116 c1;
    // std::cout << c1.canBeValid("))()))", "010100");
    // std::cout << c1.canBeValid("()()", "0000");
    // std::cout << c1.canBeValid(")", "0");
    std::cout << c1.canBeValid("))()()()((()))", "10000000000001");
    return 0;
} */

#include <iostream>
#include <vector>
#include <unordered_map>

class CheckifParenthesesStringCanBeValid_2116
{
public:
    bool canBeValid(std::string s, std::string locked)
    {
        if (s.length() % 2 == 1)
        {
            return false; // Odd-length strings cannot be valid
        }

        int openCount = 0, closeCount = 0;
        int freeCount = 0;

        // First Pass: Validate from Left to Right
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (locked[i] == '1')
            {
                if (s[i] == '(')
                {
                    openCount++;
                }
                else
                {
                    closeCount++;
                }
            }
            else
            {
                freeCount++;
            }

            // At any point, ')' must not exceed '(' + freeCount
            if (closeCount > openCount + freeCount)
            {
                return false;
            }
        }

        // Reset counts for second pass
        openCount = 0;
        closeCount = 0;
        freeCount = 0;

        // Second Pass: Validate from Right to Left
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (locked[i] == '1')
            {
                if (s[i] == '(')
                {
                    openCount++;
                }
                else
                {
                    closeCount++;
                }
            }
            else
            {
                freeCount++;
            }

            // At any point, '(' must not exceed ')' + freeCount
            if (openCount > closeCount + freeCount)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckifParenthesesStringCanBeValid_2116 c1;
    std::cout << std::boolalpha;
    std::cout << c1.canBeValid("))()))", "010100") << std::endl;                 // true
    std::cout << c1.canBeValid("()()", "0000") << std::endl;                     // true
    std::cout << c1.canBeValid(")", "0") << std::endl;                           // false
    std::cout << c1.canBeValid("))()()()((()))", "10000000000001") << std::endl; // true
    return 0;
}
