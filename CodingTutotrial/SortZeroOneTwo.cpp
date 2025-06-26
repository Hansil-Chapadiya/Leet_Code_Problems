#include<iostream>
#include<vector>

class SortZeroOneTwo
{
    public:
    std::vector<int> sorting(std::vector<int> nums)
    {
        int zeroCnt = 0 , oneCnt = 0, twoCnt = 0,  n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                zeroCnt++;
            }
            else if(nums[i] == 1)
            {
                oneCnt++;
            }
            else
            {
                twoCnt++;
            }
        }

        int i = 0;
        while(zeroCnt > 0)
        {
            nums[i] = 0;
            zeroCnt--;
            i++;
        }

        while(oneCnt > 0)
        {
            nums[i] = 1;
            oneCnt--;
            i++;
        }
        while(twoCnt > 0)
        {
            nums[i] = 2;
            twoCnt--;
            i++;
        }
        return nums;
    }
};

int main()
{
    SortZeroOneTwo obj;

    std::vector<int> arr = {2,0,2,1,1,0};
    std::vector<int> answer = obj.sorting(arr);

    for (auto i : answer)
    {
        std::cout<<i<<" ";
    }

    return 0;
}

static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();