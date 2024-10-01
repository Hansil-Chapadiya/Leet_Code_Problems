#include <iostream>
#include <vector>
#include <unordered_map>

/* Produce wrong result */
class CheckIfArrayPairsDivisibleByk_1497
{
private:
    /* data */
public:
    bool canArrange(std::vector<int> &arr, int k)
    {
        std::unordered_map<int, int> h_map;
        for (int i = 0; i < (arr.size()/2); i++)
        {
            for (int j = (arr.size()/2); j < arr.size(); j++)
            {
                if ((arr[i] + arr[j]) % k == 0)
                {
                    h_map.insert({arr[i], arr[j]});
                    break;
                }
            }
        }
        if (h_map.size() == (arr.size()/2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    CheckIfArrayPairsDivisibleByk_1497 C1;
    std::vector<int> arr = {1,2,3,4,5,10,6,7,8,9};
    std::cout << C1.canArrange(arr, 5);
    return 0;
}