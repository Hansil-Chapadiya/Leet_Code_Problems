#include <iostream>
#include <vector>
class CountTotalNumberofColoredCells_2579
{
public:
    long long coloredCells(int n)
    {
        if (n == 1)
            return 1;
        long long ans = 1;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            ans += (count * 4);
            count++;
        }
        return ans;
    }
};
int main()
{
    CountTotalNumberofColoredCells_2579 c1;
    std::cout << c1.coloredCells(4);
    return 0;
}