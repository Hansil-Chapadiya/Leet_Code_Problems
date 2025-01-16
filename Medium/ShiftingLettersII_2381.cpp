#include <iostream>
#include <vector>
#include <string>

class ShiftingLettersII_2381
{
public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>> &shifts)
    {
        std::vector<int> delta(s.length() + 1, 0);

        // Populate the delta array using shifts
        for (auto shift : shifts)
        {
            if (shift[2] == 0)
            {
                delta[shift[0]] -= 1;
                delta[shift[1] + 1] += 1;
            }
            else
            {
                delta[shift[0]] += 1;
                delta[shift[1] + 1] -= 1;
            }
        }

        // Compute prefix sum for the delta array
        int current_sum = 0;
        std::vector<int> prefix_sum(s.length(), 0);
        for (int i = 0; i < s.length(); ++i)
        {
            current_sum += delta[i];
            prefix_sum[i] = current_sum;
        }

        // Apply the shifts to the string
        for (int i = 0; i < s.length(); ++i)
        {
            s[i] = ((s[i] - 'a' + prefix_sum[i]) % 26 + 26) % 26 + 'a';
        }

        return s;
    }
};

int main()
{
    ShiftingLettersII_2381 s1;

    std::vector<std::vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    std::cout << s1.shiftingLetters("abc", shifts) << std::endl;

    return 0;
}
