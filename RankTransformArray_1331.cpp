#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class RankTransformArray_1331
{
private:
    /* data */
public:
    std::vector<int> arrayRankTransform(std::vector<int> &arr)
    {
        std::vector<int> tmp_arr = arr;
        auto first = tmp_arr.begin();
        auto last = tmp_arr.begin() + arr.size();

        std::sort(first, last);
        std::vector<int> res;
        for (int i = 0; i < arr.size(); i++)
        {
            auto it = std::find(tmp_arr.begin(), tmp_arr.end(), arr[i]);
            if (it != tmp_arr.end())
            {
                int index = std::distance(tmp_arr.begin(), it);
                res.push_back(index+1);
            }
        }

        return res;
    }
};
int main()
{
    RankTransformArray_1331 r1;
    std::vector<int> arr = {37,12,28,9,100,56,80,5,12};
    std::vector<int> res = r1.arrayRankTransform(arr);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << " ";
    }
}
