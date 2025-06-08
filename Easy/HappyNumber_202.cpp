#include <iostream>
#include <vector>
#include <cmath>
class HappyNumber_202
{
    public:
    int sosd(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int  rem  = n % 10;
            sum += std::pow(rem,2);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int temp = n;
        while (temp > 9)
        {
            temp = sosd(temp);
            // std::cout<<temp<<" ";
        }

        if(temp == 1 || temp == 7)
        {
            return true;
        }


        return false;
    }
};


int main()
{

    HappyNumber_202 h1;
    // std::cout<<h1.isHappy(19);
    std::cout<<h1.isHappy(2);

    return 0;
}