#include <iostream>
#include <vector>
#include <string>
#include <stack>

class ConstructSmallestNumberFromDIString_2375
{
private:
    std::stack<int> stk;
    std::string result;

public:
    std::string smallestNumber(std::string pattern)
    {
        result.clear(); // Reset result for each call

        for (int i = 0; i <= pattern.size(); i++) // Ensure we push all needed numbers
        {
            stk.push(i + 1); // Always push `i+1`

            if (i == pattern.size() || pattern[i] == 'I') // Process when 'I' or at the end
            {
                while (!stk.empty())
                {
                    result += std::to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return result;
    }
};

int main()
{
    ConstructSmallestNumberFromDIString_2375 c1;
    std::cout << c1.smallestNumber("DDD") << std::endl;      // Output: "4321"
    std::cout << c1.smallestNumber("IIIDIDDD") << std::endl; // Output: "123549876"
}
