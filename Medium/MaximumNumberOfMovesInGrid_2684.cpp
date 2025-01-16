#include <iostream>
#include <vector>
#include <algorithm>

class MaximumNumberOfMovesInGrid_2684 {
public:
    int maxMoves(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int maxColumnReached = 0;
        std::vector<int> maxMovesAtRow(numRows, 0); // Tracks maximum moves for each row

        // Start from the second column, as the first column is the starting point
        for (int col = 1; col < numCols; ++col) {
            int prevLeftTop = 0;
            bool movePossibleInColumn = false;

            // Traverse each row in the current column
            for (int row = 0; row < numRows; ++row) {
                int maxMovesHere = -1; // Default to -1 (no move possible)
                int newPrevLeftTop = maxMovesAtRow[row]; // Track previous max moves at this row

                // Check if a move from the upper-left cell is possible
                if (row > 0 && prevLeftTop != -1 && grid[row][col] > grid[row - 1][col - 1]) {
                    maxMovesHere = std::max(maxMovesHere, prevLeftTop + 1);
                }

                // Check if a move from the left cell is possible
                if (maxMovesAtRow[row] != -1 && grid[row][col] > grid[row][col - 1]) {
                    maxMovesHere = std::max(maxMovesHere, maxMovesAtRow[row] + 1);
                }

                // Check if a move from the lower-left cell is possible
                if (row + 1 < numRows && maxMovesAtRow[row + 1] != -1 && grid[row][col] > grid[row + 1][col - 1]) {
                    maxMovesHere = std::max(maxMovesHere, maxMovesAtRow[row + 1] + 1);
                }

                maxMovesAtRow[row] = maxMovesHere; // Update the max moves at the current row
                movePossibleInColumn = movePossibleInColumn || (maxMovesAtRow[row] != -1);
                prevLeftTop = newPrevLeftTop; // Update prevLeftTop for the next row
            }

            if (!movePossibleInColumn) break; // Exit if no moves are possible in this column
            maxColumnReached = col; // Update max column reached if moves are found
        }

        return maxColumnReached; // Return the farthest column index reached
    }
};

int main() {
    MaximumNumberOfMovesInGrid_2684 solver;
    std::vector<std::vector<int>> grid = {
        {56, 137, 288, 177, 252, 297, 63, 107, 252, 37},
        {102, 89, 50, 276, 41, 176, 105, 242, 282, 259},
        {276, 187, 262, 117, 92, 57, 13, 224, 80, 167},
        {246, 263, 277, 223, 115, 156, 231, 294, 8, 253},
        {70, 195, 78, 101, 136, 256, 59, 213, 120, 42},
        {186, 74, 265, 258, 285, 181, 21, 193, 53, 278},
        {132, 283, 229, 154, 183, 299, 6, 16, 144, 61},
        {186, 99, 123, 245, 41, 140, 295, 111, 289, 230},
        {285, 242, 278, 146, 286, 128, 180, 54, 245, 239},
        {281, 166, 159, 51, 148, 113, 287, 44, 133, 214},
        {112, 74, 149, 67, 167, 232, 5, 115, 279, 27},
        {16, 288, 77, 159, 288, 62, 4, 71, 221, 195}
    };

    std::cout << "Maximum moves: " << solver.maxMoves(grid) << std::endl;
    return 0;
}
