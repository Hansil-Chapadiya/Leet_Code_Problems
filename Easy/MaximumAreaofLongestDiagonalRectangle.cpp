#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class MaximumAreaofLongestDiagonalRectangle
{
public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>> &dimensions)
    {
        //   int m = dimensions.length();
        //   int n = 2;

        float dgl = 0.0f;
        int maxArea = 0;

        for (auto dimension : dimensions)
        {
            float digonallength = std::sqrt(std::pow(dimension[0], 2) + std::pow(dimension[1], 2));
            int area = dimension[0] * dimension[1];

            if (digonallength > dgl)
            {
                dgl = digonallength;
                maxArea = area;
            }
            else if (std::fabs(digonallength - dgl) && area > maxArea)
            {
                maxArea = area;
            }
        }

        return maxArea;
    }
};

int main()
{
    MaximumAreaofLongestDiagonalRectangle m1;

    // std::vector<std::vector<int>> dimensions = {{9,3},{8,6}};
    std::vector<std::vector<int>> dimensions = {{3, 4}, {4, 3}};
    std::cout << m1.areaOfMaxDiagonal(dimensions);

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class MaximumAreaofLongestDiagonalRectangle
{
public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>> &dimensions)
    {
        //   int m = dimensions.length();
        //   int n = 2;

        int dgl = 0;
        int maxArea = 0;

        for (auto dimension : dimensions)
        {
            int sq = (dimension[0] * dimension[0]) + (dimension[1] * dimension[1]);
            int area = dimension[0] * dimension[1];

            if ((area > maxArea && sq == dgl) || sq > dgl)
            {
                maxArea = area;
                dgl = sq;
            }
        }

        return maxArea;
    }
};

int main()
{
    MaximumAreaofLongestDiagonalRectangle m1;

    std::vector<std::vector<int>> dimensions = {{9,3},{8,6}};
    // std::vector<std::vector<int>> dimensions = {{3, 4}, {4, 3}};
    std::cout << m1.areaOfMaxDiagonal(dimensions);

    return 0;
}

*/