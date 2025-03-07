#include <iostream>
#include <vector>
class ClosestPrimeNumbersInRange
{
public:
    std::vector<int> closestPrimes(int left, int right)
    {
        return {};
    }
};
int main()
{
    ClosestPrimeNumbersInRange c1;
    std::vector<int> answer = c1.closestPrimes(2, 3);
    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}