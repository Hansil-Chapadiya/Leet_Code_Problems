#include <iostream>
#include <vector>
#include <algorithm>

class MaximumNumberOfMovesInGrid_2684
{
public:
    int maxMoves(std::vector<std::vector<int>> &grid)
    {
        int row = grid.size();
        int column = grid[0].size();
        int max_move_count = 0; // Initialize the maximum move counter

        // Traverse from each row in the first column to maximize the move count
        for (int start_row = 0; start_row < row; ++start_row)
        {
            int i = start_row;  // Set starting row index
            int j = 0;          // Starting column index
            int move_count = 0; // Reset move counter for each start row

            while (j < column - 1) // Traverse until the last column
            {
                // Current cell value
                int current_value = grid[i][j];

                // Variables to hold the next cell with the maximum strictly greater value
                int max_val = current_value; // Initial value for comparison
                int next_i = -1, next_j = -1;

                // Check each allowed direction for a strictly greater value
                if (i > 0 && j + 1 < column && grid[i - 1][j + 1] > current_value && grid[i - 1][j + 1] > max_val)
                {
                    max_val = grid[i - 1][j + 1];
                    next_i = i - 1;
                    next_j = j + 1;
                }
                if (j + 1 < column && grid[i][j + 1] > current_value && grid[i][j + 1] > max_val)
                {
                    max_val = grid[i][j + 1];
                    next_i = i;
                    next_j = j + 1;
                }
                if (i + 1 < row && j + 1 < column && grid[i + 1][j + 1] > current_value && grid[i + 1][j + 1] > max_val)
                {
                    max_val = grid[i + 1][j + 1];
                    next_i = i + 1;
                    next_j = j + 1;
                }

                // Move to the position with the maximum strictly greater value if found
                if (next_j == -1)
                    break; // No valid move; stop if no strictly greater adjacent element found

                // Move to the next cell and increment move count
                i = next_i;
                j = next_j;
                move_count++;
            }

            // Update the maximum move count if the current path yielded more moves
            max_move_count = std::max(max_move_count, move_count);
        }

        return max_move_count; // Return the maximum number of moves taken from any starting row
    }
};

int main()
{
    MaximumNumberOfMovesInGrid_2684 m1;
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

    std::cout << "Maximum moves: " << m1.maxMoves(grid) << std::endl;
    return 0;
}
