#include <iostream>
#include <vector>

class PascalTriangle
{
    public:
    std::vector<std::vector<int>> pascalTriangleConstruct(int nthRow, int row, int col)
    {
        std::vector<std::vector<int>> answer(nthRow);

        for(int i = 0; i < nthRow; i++)
        {
            answer[i].resize(i+1);
            answer[i][0] = 1;
            answer[i][i] = 1;
            for(int j = 1; j < i; j++)
            {
                answer[i][j] = answer[i-1][j-1] + answer[i-1][j];
            }
        }
        return answer;
    }
};


int main()
{
    PascalTriangle p1;
    int n = 5;
    std::vector<std::vector<int>> answer = p1.pascalTriangleConstruct(n,6,7);

    for (int i = 0; i < n; ++i)
    {
        // Print leading spaces
        std::cout << std::string((n - i - 1) * 2, ' ');

        for (int num : answer[i])
        {
            std::cout << num << "   ";  // 3 spaces between numbers for symmetry
        }

        std::cout << "\n";
    }

    return 0;
}
