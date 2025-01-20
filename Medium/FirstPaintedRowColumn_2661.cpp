#include <iostream>
#include <vector>
#include <unordered_map>
class FirstPaintedRowColumn_2661
{
private:
    /* data */
public:
    int firstCompleteIndex(std::vector<int> &arr, std::vector<std::vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        std::unordered_map<int, std::pair<int, int>> map;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[mat[i][j]] = {i, j};
            }
        }

        std::vector<int> row_cnt(m, 0);
        std::vector<int> col_cnt(n, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            auto [row, col] = map[arr[i]];
            row_cnt[row]++;
            col_cnt[col]++;
            if (row_cnt[row] == n || col_cnt[col] == m)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    FirstPaintedRowColumn_2661 f1;
    std::vector<int> arr = {1, 3, 4, 2};
    std::vector<std::vector<int>> mat = {{1, 4}, {2, 3}};
    std::cout << f1.firstCompleteIndex(arr, mat);
    return 0;
}