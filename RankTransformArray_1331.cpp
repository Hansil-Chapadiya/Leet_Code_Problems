#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class RankTransformArray_1331
{
public:
    std::vector<int> arrayRankTransform(std::vector<int> &arr)
    {
        std::vector<int> tmp_arr = arr;

        // Sort the copied array to get the ranking order
        std::sort(tmp_arr.begin(), tmp_arr.end());

        // Map to store the rank of each element
        std::unordered_map<int, int> rank_map;
        int rank = 1;

        // Assign rank to each unique element
        for (int num : tmp_arr)
        {
            if (rank_map.find(num) == rank_map.end())
            {
                rank_map[num] = rank;
                rank++;
            }
        }

        // Replace each element in the original array with its rank
        std::vector<int> res;
        for (int num : arr)
        {
            res.push_back(rank_map[num]);
        }
        for (const auto &pair : rank_map)
        {
            std::cout << pair.first << " -> " << pair.second << "\n";
        }

        return res;
    }
};

int main()
{
    RankTransformArray_1331 r1;
    std::vector<int> arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    std::vector<int> res = r1.arrayRankTransform(arr);

    // for (int i = 0; i < res.size(); i++)
    // {
    //     std::cout << res[i] << " ";
    // }
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();