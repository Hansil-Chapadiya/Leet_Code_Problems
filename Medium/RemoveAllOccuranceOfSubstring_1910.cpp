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
        int m = part.size();

        while (s.size() >= m)
        { // Only process if 's' is at least as long as 'part'
            bool found = false;
            for (size_t i = 0; i <= s.size() - m; i++)
            { // Ensure valid substring bounds
                if (s.compare(i, m, part) == 0)
                {                  // Compare 'm' chars from index 'i'
                    s.erase(i, m); // Remove 'part' from 's'
                    found = true;
                    break; // Restart loop after removal
                }
            }
            if (!found)
                break; // Stop when no more occurrences of 'part'
        }

        return s;
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

/*
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

*/