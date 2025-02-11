#include <iostream>
#include <vector>
#include <string>
#include <stack>
class RemoveAllOccuranceOfSubstring_1910
{
private:
    std::stack<char> stk;

public:
    std::string removeOccurrences(std::string s, std::string part)
    {
        std::string stack;  // Use a string as a stack
        int partLen = part.size();

        for (char c : s) {
            stack.push_back(c);  // Push character to stack

            // Check if the last 'partLen' characters in stack match 'part'
            if (stack.size() >= partLen && stack.substr(stack.size() - partLen) == part) {
                stack.erase(stack.end() - partLen, stack.end());  // Remove last 'partLen' characters
            }
        }
        return stack;
    }
};
int main()
{
    RemoveAllOccuranceOfSubstring_1910 r1;
    std::cout << r1.removeOccurrences("daabcbaabcbc", "abc");
}
/*
int i;
        while (true)
        {
            if ((i = s.find(part)) != std::string::npos)
            {
                s = s.erase(i, part.size());
            }
            else
            {
                return s;
            }
        }

*/