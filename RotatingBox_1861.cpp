#include <iostream>
#include <vector>
using namespace std;

class RotatingBox_1861
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();

        // Step 1: Rotate the box 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotatedBox[i][j] = box[m - 1 - j][i];
            }
        }

        // Step 2: Apply gravity to each column in the rotated box
        for (int col = 0; col < m; col++)
        {
            int emptyRow = n - 1; // Start at the bottom of the column
            for (int row = n - 1; row >= 0; row--)
            {
                if (rotatedBox[row][col] == '#')
                {
                    // Move stone down to the lowest available empty space
                    swap(rotatedBox[row][col], rotatedBox[emptyRow][col]);
                    emptyRow--;
                }
                else if (rotatedBox[row][col] == '*')
                {
                    // Obstacle blocks further movement; reset emptyRow
                    emptyRow = row - 1;
                }
            }
        }

        return rotatedBox;
    }
};

int main()
{
    RotatingBox_1861 r1;
    // vector<vector<char>> box = {
    //     {'#', '.', '*', '.'},
    //     {'#', '#', '*', '.'}};
    // vector<vector<char>> box = {
    //     {'#', '.', '#'}};
    vector<vector<char>> box = {{'#', '#', '*', '.', '*', '.'},
                                {'#', '#', '#', '*', '.', '.'},
                                {'#', '#', '#', '.', '#', '.'}};

    vector<vector<char>> result = r1.rotateTheBox(box);

    // Print the result
    for (const auto &row : result)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
