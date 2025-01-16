#include <iostream>
#include <vector>
class MaxChunkToMakeSorted_769
{
private:
    /* data */
public:
    int maxChunksToSorted(std::vector<int> &arr)
    {
        int sum_series = 0;
        int max_chunk = 0;
        int ith_sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum_series += arr[i];
            ith_sum = i * (i + 1) / 2;
            if (ith_sum == sum_series)
            {
                max_chunk++;
            }
        }
        return max_chunk;
    }
};
int main()
{
    MaxChunkToMakeSorted_769 m1;
    // std::vector<int> arr = {4, 3, 2, 1, 0};
    std::vector<int> arr = {1,0,2,3,4};
    std::cout << m1.maxChunksToSorted(arr);
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();