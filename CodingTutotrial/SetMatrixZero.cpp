#include <vector>
#include <iostream>

class SetMatrixZero
{
private:
    std::vector<std::vector<int>> answer;

public:
    void helperfunction(int Iindex, int Jindex)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            answer[Iindex][i] = 0;
        }

        for (int j = 0; j < answer[0].size(); j++)
        {
            answer[j][Jindex] = 0;
        }
    }
    std::vector<std::vector<int>> setZeroMatrix(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int Iindex = 0;
        int Jindex = 0;
        answer.clear();
        answer.resize(row, std::vector<int>(col, 0));
        answer = matrix;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    Iindex = i;
                    Jindex = j;
                    helperfunction(i, j);
                }
            }
        }
        return answer;
    }
};
int main()
{
    SetMatrixZero obj;
    // std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {0, 1, 1}};

    std::vector<std::vector<int>> answer = obj.setZeroMatrix(matrix);

    for (auto subarr : answer)
    {
        for (auto element : subarr)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}


/*


#include <vector>
#include <iostream>

class SetMatrixZero
{
private:
    std::vector<std::vector<int>> answer;

public:
    void helperfunction(int Iindex, int Jindex)
    {
        for (int i = 0; i < answer[0].size(); i++)
        {
            answer[Iindex][i] = 0;
        }

        for (int j = 0; j < answer.size(); j++)
        {
            answer[j][Jindex] = 0;
        }
    }

    std::vector<std::vector<int>> setZeroMatrix(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        answer = matrix;

        std::vector<std::pair<int, int>> zeros;

        // Step 1: Collect all positions with zero
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeros.push_back({i, j});
                }
            }
        }

        // Step 2: Apply zeroing for each zero position
        for (auto [i, j] : zeros)
        {
            helperfunction(i, j);
        }

        return answer;
    }
};

int main()
{
    SetMatrixZero obj;
    std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> answer = obj.setZeroMatrix(matrix);

    for (auto subarr : answer)
    {
        for (auto element : subarr)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }

    return 0;
}


*/