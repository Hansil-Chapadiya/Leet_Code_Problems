#include <iostream>
#include <cmath>
class MinimumAddTOMakeParentheses_921
{
private:
    /* data */
public:
    int minAddToMakeValid(std::string s)
    {
        int leftbraces = 0;
        int rightbraces = 0;
        int unbalanced = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                leftbraces++;
            }
            else
            {
               if (leftbraces > 0)
                    leftbraces--;  // Match ']' with a previous unmatched '['
                else
                    unbalanced++;  // Increment unbalanced count if there is no matching '['
            }
        }
        return leftbraces + unbalanced;
    }
};
int main()
{
    MinimumAddTOMakeParentheses_921 M1;
    std::cout << M1.minAddToMakeValid("()))((");
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
