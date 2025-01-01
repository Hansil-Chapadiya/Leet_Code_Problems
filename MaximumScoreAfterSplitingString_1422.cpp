#include <iostream>
#include <vector>
#include <string>
class MaximumScoreAfterSplitingString_1422
{
private:
    /* data */
public:
    int maxScore(std::string s)
    {
        std::vector<int> prefixsum_of_ones;
        int sum_of_ones = 0;
        for (int i = 1; i < s.length(); i++)
        {
        }
    }
};
int main()
{
    MaximumScoreAfterSplitingString_1422 m1;
    std::string s = "011101";
    std::cout << m1.maxScore(s);
    return 0;
}