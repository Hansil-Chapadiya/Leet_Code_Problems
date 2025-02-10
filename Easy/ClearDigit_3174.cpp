#include <iostream>
#include <string>
#include <vector>

/* class ClearDigit_3174
{
public:
    std::string clearDigits(const std::string &s)
    {
        std::vector<bool> marked(s.size(), false); // To track which characters to remove
        int lastLetterIdx = -1; // To track the last unmarked letter index

        // First pass: Mark letters that should be removed
        for (size_t i = 0; i < s.length(); i++)
        {
            if (std::isdigit(s[i]) && lastLetterIdx != -1)
            {
                marked[lastLetterIdx] = true; // Remove the last unmarked letter
                lastLetterIdx = -1; // Reset last letter index
                for (int j = i - 1; j >= 0; j--) // Find next valid unmarked letter
                {
                    if (!marked[j] && std::isalpha(s[j]))
                    {
                        lastLetterIdx = j;
                        break;
                    }
                }
            }
            else if (std::isalpha(s[i]))
            {
                lastLetterIdx = i; // Update last letter index
            }
        }

        // Second pass: Construct result string
        std::string result;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (!marked[i] && !std::isdigit(s[i]))
            {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};

int main()
{
    ClearDigit_3174 c1;
    std::cout << c1.clearDigits("cb34") << std::endl;      // Expected: ""
    std::cout << c1.clearDigits("a1b2c3") << std::endl;    // Expected: ""
    std::cout << c1.clearDigits("abc") << std::endl;       // Expected: "abc"
    std::cout << c1.clearDigits("a1bcd23") << std::endl;   // Expected: "d"

    return 0;
}
 */
#include <iostream>
#include <stack>
#include <string>

class ClearDigit_3174
{
public:
    std::string clearDigits(const std::string &s)
    {
        std::stack<char> stk;  // Stack to process characters
        std::stack<char> temp; // Temp stack for backtracking

        for (char c : s)
        {
            if (std::isdigit(c))
            {
                if (!stk.empty() && std::isalpha(stk.top()))
                {
                    stk.pop(); // Remove the last letter before digit
                }
            }
            else
            {
                stk.push(c); // Push letters normally
            }
        }

        // Reconstruct the final string from the stack
        std::string result;
        while (!stk.empty())
        {
            temp.push(stk.top());
            stk.pop();
        }

        while (!temp.empty())
        {
            result.push_back(temp.top());
            temp.pop();
        }

        return result;
    }
};

int main()
{
    ClearDigit_3174 c1;
    std::cout << c1.clearDigits("cb34") << std::endl;    // Expected: ""
    std::cout << c1.clearDigits("a1b2c3") << std::endl;  // Expected: ""
    std::cout << c1.clearDigits("abc") << std::endl;     // Expected: "abc"
    std::cout << c1.clearDigits("a1bcd23") << std::endl; // Expected: "d"

    return 0;
}
