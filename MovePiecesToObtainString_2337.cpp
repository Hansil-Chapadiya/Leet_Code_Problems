#include <iostream>
#include <string>

class MovePiecesToObtainString_2337
{
public:
    bool canChange(const std::string &start, const std::string &target)
    {
        if (start.length() != target.length())
        {
            return false;
        }

        int i = 0, j = 0;
        while (i < start.length() || j < target.length())
        {
            // Skip spaces in both strings
            while (i < start.length() && start[i] == '_')
            {
                ++i;
            }
            while (j < target.length() && target[j] == '_')
            {
                ++j;
            }

            // Check if both strings have the same number of 'L' and 'R'
            if (i < start.length() && j < target.length())
            {
                if (start[i] != target[j])
                {
                    return false;
                }
                // 'L' can only move left (j <= i)
                if (start[i] == 'L' && j > i)
                {
                    return false;
                }
                // 'R' can only move right (i <= j)
                if (start[i] == 'R' && i > j)
                {
                    return false;
                }
            }

            // Check if one string is exhausted before the other
            if ((i < start.length()) != (j < target.length()))
            {
                return false;
            }

            ++i;
            ++j;
        }

        return true;
    }
};

int main()
{
    MovePiecesToObtainString_2337 m1;
    std::cout << std::boolalpha << m1.canChange("_L__R__R_", "L______RR") << "\n"; // Output: true
    std::cout << std::boolalpha << m1.canChange("_R", "R_") << "\n";               // Output: false
    return 0;
}
