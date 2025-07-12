#include <iostream>
#include <vector>
#include <iomanip>

class PlusMinus
{
public:
    void plusMinus(std::vector<int> arr)
    {
        double positiveCount = 0;
        double negativeCount = 0;
        double zeroCount = 0;
        double n = arr.size();

        for (int i : arr)
        {
            if (i > 0)
                positiveCount++;
            else if (i < 0)
                negativeCount++;
            else
                zeroCount++;
        }

        std::cout << "PositiveCount = " << std::fixed << std::setprecision(6) << positiveCount / n << std::endl;
        std::cout << "NegativeCount = " << std::fixed << std::setprecision(6) << negativeCount / n << std::endl;
        std::cout << "ZeroCount = " << std::fixed << std::setprecision(6) << zeroCount / n << std::endl;
    }
};
int main()
{
    std::vector<int> arr = {-4, 3, -9, 0, 4, 1};
    PlusMinus p1;
    p1.plusMinus(arr);
    return 0;
}