#include<iostream>
#include<vector>

class CountSubMatricWithAllOnes_1277
{
private:
    /* data */
public:
    int countSquare(std::vector<std::vector<int>>& matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        std::vector<std::vector<int>> dp(r+1,std::vector<int>(c+1,0));
    }
};
int main()
{
    CountSubMatricWithAllOnes_1277 c1;
    return 0;
}
