#include <iostream>
#include <vector>
#include <string>

class ShiftingLettersII_2381
{
private:
    /* data */
public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>> &shifts)
    {
    }
};
int main()
{
    ShiftingLettersII_2381 s1;
    std::vector<std::vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    s1.shiftingLetters("abc", shifts);
    return 0;
}
