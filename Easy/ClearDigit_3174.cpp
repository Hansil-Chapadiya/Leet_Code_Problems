#include <iostream>
#include <string>
#include <vector>

class ClearDigit_3174
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

/*  int count_char = 0;
for (char c : s)
{
if (!std::isdigit(c))
{
count_char++;
}

stk.push(c);
marked.push_back({c, false});
}

if (count_char == s.length())
{
return s;
}

std::stack<char> temp; // 4
while (!stk.empty())
{
char c = stk.top();
stk.pop();

if (std::isdigit(c))
{
char temp_top = stk.top();
while (!stk.empty() && std::isdigit(temp_top))
{
    stk.pop();
    temp.push(temp_top);
}
marked[temp_top].second = true;
}
}
std::string answer;
for (auto i : s)
{
if (!std::isdigit(i) && marked[i].second == false)
{
answer.push_back(i);
}
} */