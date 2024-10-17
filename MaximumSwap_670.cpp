#include <iostream>
#include <string>
class MaximumSwap_670
{
private:
    /* data */
public:
    int maximumSwap(int num)
    {
        int rem;
        int temp = num;
        int max = 0;
        while (temp > 0)
        {
            rem = temp % 10;
            if (rem > max)
            {
                max = rem;
            }

            temp /= 10;
        }
    }
};
int main()
{
    MaximumSwap_670 m1;
    m1.maximumSwap(2736);
    return 0;
}
