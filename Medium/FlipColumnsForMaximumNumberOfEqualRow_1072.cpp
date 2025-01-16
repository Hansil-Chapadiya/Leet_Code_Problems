#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class FlipColumnsForMaximumNumberOfEqualRow
{
public:
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>> &matrix)
    {
        std::unordered_map<std::string, int> patternfreq;
        for (auto &current_row : matrix)
        {
            std::string pattern = "";
            // Convert row to pattern relative to its first element
            for (int col = 0; col < current_row.size(); col++)
            {
                // 'T' if current element matches first element, 'F' otherwise
                if (current_row[0] == current_row[col])
                {
                    pattern += "T";
                }
                else
                {
                    pattern += "F";
                }
            }
            patternfreq[pattern]++;
        }

        // Find the pattern with maximum frequency
        int maxFrequency = 0;
        for (auto &entry : patternfreq)
        {
            maxFrequency = std::max(entry.second, maxFrequency);
        }
        return maxFrequency;
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

/*

 int maxEqualRows = 0;           // Tracks the maximum number of identical rows
        int numCols = matrix[0].size(); // Number of columns in the matrix

        // Iterate through each row in the matrix
        for (const auto &current_row : matrix)
        {
            std::vector<int> flippedRow(numCols); // Stores the flipped version of the current row
            int identicalRowCount = 0;            // Counts rows that match the current row or its flipped version

            // Create the flipped version of the current row
            for (int col = 0; col < numCols; ++col)
            {
                flippedRow[col] = 1 - current_row[col];
            }

            // Compare the current row and its flipped version with all rows in the matrix
            for (const auto &compareRow : matrix)
            {
                if (compareRow == current_row || compareRow == flippedRow)
                {
                    ++identicalRowCount;
                }
            }

            // Update the maximum number of identical rows found so far
            maxEqualRows = std::max(maxEqualRows, identicalRowCount);
        }

        return maxEqualRows;
*/
