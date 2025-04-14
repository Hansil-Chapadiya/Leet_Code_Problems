#include <iostream>
#include <vector>
#include <cmath>

class CountGoodTripltes_1534
{
    public:

    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {

        int n = arr.size();

        int cnt = 0;

        for (int i = 0; i < n ; i++)
        {

            for (int j = i+1 ; j < n; j++)
            {

                for(int k = j+1; k < n; k++)
                {

                    int x = std::abs(arr[i] - arr[j]);

                    int y = std::abs(arr[j] - arr[k]);

                    int z = std::abs(arr[k] - arr[i]);

                    if(x <= a && y <= b && z <= c)
                    {
                        cnt++;
                    }

                }
            }
        }

        return cnt;
    }
};

int main()
{
    CountGoodTripltes_1534 c1;

    std::vector<int> arr = {3,0,1,1,9,7};
    int a = 7;
    int b = 2;
    int c = 3;

    std::cout<<c1.countGoodTriplets(arr, a, b, c);
}