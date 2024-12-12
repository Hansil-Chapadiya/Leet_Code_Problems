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
        for (int i = 0; i < k; i++)
        {
            auto it = std::max_element(gifts.begin(), gifts.end()); // Find max element
            *it = findSquareRoot(*it);                              // Update it with its square root
        }

        // Calculate the total sum of all elements in the gifts array
        long long sum = 0;
        for (int j = 0; j < gifts.size(); j++)
        {
            sum += gifts[j];
        }

        return sum;
    }
};
int main()
{
    // std::vector<int> gifts = {25, 64, 9, 4, 100};
    // std::vector<int> gifts = {1, 1, 1, 1};
    std::vector<int> gifts = {8,21,21,44,68,33,16,57,23,2,61,53,73,66,40,46,50,33,20,72,2,59,11,43,6,70,13,51,26,34,46,61,73,22,27,36,18,31,62};
    TakeGiftFromRichestPile_2558 t1;
    std::cout << t1.pickGifts(gifts, 24);
    return 0;
}