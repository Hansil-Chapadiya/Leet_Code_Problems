#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
class TakeGiftFromRichestPile_2558
{
private:
    int findSquareRoot(int x)
    {
        if (x < 0)
        {
            return -1;
        }
        if (x == 0 || x == 1)
        {
            return x;
        }

        double floorApprox = std::exp(log(x) / 2);
        int floorResult = static_cast<int>(std::floor(floorApprox));

        if (floorResult * floorResult == x)
        {
            return floorResult;
        }

        if ((floorResult + 1) * (floorResult + 1) == x)
        {
            return floorResult + 1;
        }

        return floorResult;
    }

public:
    long long pickGifts(std::vector<int> &gifts, int k)
    {
        }
};
int main()
{
    std::vector<int> gifts = {25, 64, 9, 4, 100};
    TakeGiftFromRichestPile_2558 t1;
    t1.pickGifts(gifts, 4);
    return 0;
}