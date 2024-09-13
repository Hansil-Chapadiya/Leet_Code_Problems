#include <iostream>
#include <vector>
using namespace std;

class XorQueriesOfSubArray_1310
{
private:
    /* data */
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> result;
        int xor_ = 0, k = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            xor_ = 0;
            for (int j = queries[i][k]; j <= queries[i][k + 1]; j++)
            {
                xor_ ^= arr.at(j);
            }
            cout << xor_ << endl;
            // result.insert(result.begin() + i, xor_);
            result.push_back(xor_);
        }
        return result;
    }
};
int main()
{
    XorQueriesOfSubArray_1310 x1;
    // vector<int> arr = {1, 3, 4, 8};
    vector<int> arr = {4, 8, 2, 10};
    // vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<vector<int>> queries = {{2,3},{1,3},{0,0},{0,3}};
    vector<int> result = x1.xorQueries(arr, queries);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout<<result.at(i)<<endl;
    // }
}