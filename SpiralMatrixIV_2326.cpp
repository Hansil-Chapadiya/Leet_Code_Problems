#include <iostream>
#include <vector>
using namespace std;

// Definition for the ListNode
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Class to handle spiral matrix formation
class SpiralMatrixIV_2326
{
public:
    vector<vector<int>> spiralMatrix(int rows, int cols, ListNode *head)
    {
        // Initialize matrix with zeros
        vector<vector<int>> matrix(rows, vector<int>(cols, -1));
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));

        // Direction arrays for moving: right, down, left, up
        int rowDirs[] = {0, 1, 0, -1};
        int colDirs[] = {1, 0, -1, 0};

        int row = 0, col = 0, direction = 0; // start by moving right
        ListNode *current = head;            // start from the linked list head

        for (int i = 0; i < rows * cols; i++)
        {
            // Assign the current list node value to the matrix
            if (current != nullptr)
            {
                matrix[row][col] = current->val;
                current = current->next; // move to the next node
            }

            // Mark the current position as visited
            seen[row][col] = true;

            // Calculate the next row and column
            int nextRow = row + rowDirs[direction];
            int nextCol = col + colDirs[direction];

            // Check if the next move is within bounds and not visited
            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && !seen[nextRow][nextCol])
            {
                row = nextRow;
                col = nextCol;
            }
            else
            {
                // Change direction (turn clockwise)
                direction = (direction + 1) % 4;
                row = row + rowDirs[direction];
                col = col + colDirs[direction];
            }
        }

        return matrix; // return the filled spiral matrix
    }
};

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    // head->next->next->next = new ListNode(6);
    // head->next->next->next->next = new ListNode(8);
    // head->next->next->next->next->next = new ListNode(1);
    // head->next->next->next->next->next->next = new ListNode(7);
    // head->next->next->next->next->next->next->next = new ListNode(9);
    // head->next->next->next->next->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next->next->next->next->next = new ListNode(2);
    // head->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);

    SpiralMatrixIV_2326 s;
    int rows = 1, cols = 4; // Example: 3x4 matrix
    vector<vector<int>> result = s.spiralMatrix(rows, cols, head);

    // Print the resulting matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
