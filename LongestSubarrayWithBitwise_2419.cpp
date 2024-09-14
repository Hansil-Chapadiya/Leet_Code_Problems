#include <iostream>
#include <vector>
using namespace std;
class LongestSubarrayWithBitwise_2419
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max, length, bitandop, k;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                bitandop = 1;
                for (k = i; k <= j; k++)
                {
                    bitandop = (bitandop & k);
                }
                if (bitandop >= max)
                {
                    max = bitandop;
                    return k;
                }
            }
        }
        return 0;
    }
};
int main()
{
    LongestSubarrayWithBitwise_2419 l1;
    vector<int>  nums = {1,2,3,3,2,2};
    cout<<l1.longestSubarray(nums);
}
