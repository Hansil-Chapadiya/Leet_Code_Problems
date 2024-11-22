#include <iostream>
#include <vector>
#include <algorithm>

class FlipColumnsForMaximumNumberOfEqualRow
{
public:
    /**
     * Calculate the maximum number of equal rows after flipping columns.
     * @param matrix - 2D vector representing the binary matrix.
     * @return Maximum number of rows that can be made identical.
     */
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>> &matrix)
    {
        int maxEqualRows = 0;           // Tracks the maximum number of identical rows
        int numCols = matrix[0].size(); // Number of columns in the matrix

        // Iterate through each row in the matrix
        for (const auto &currentRow : matrix)
        {
            std::vector<int> flippedRow(numCols); // Stores the flipped version of the current row
            int identicalRowCount = 0;            // Counts rows that match the current row or its flipped version

            // Create the flipped version of the current row
            for (int col = 0; col < numCols; ++col)
            {
                flippedRow[col] = 1 - currentRow[col];
            }

            // Compare the current row and its flipped version with all rows in the matrix
            for (const auto &compareRow : matrix)
            {
                if (compareRow == currentRow || compareRow == flippedRow)
                {
                    ++identicalRowCount;
                }
            }

            // Update the maximum number of identical rows found so far
            maxEqualRows = std::max(maxEqualRows, identicalRowCount);
        }

        return maxEqualRows;
    }
};

int main()
{
    FlipColumnsForMaximumNumberOfEqualRow solver;

    // Example matrix
    std::vector<std::vector<int>> matrix = {
        {0, 1},
        {1, 1}};

    // Output the result
    std::cout << "Maximum number of equal rows after flips: "
              << solver.maxEqualRowsAfterFlips(matrix) << std::endl;

    return 0;
}
