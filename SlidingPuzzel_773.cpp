#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
class SlidingPuzzle_773
{
private:
    // Possible moves for the empty tile (zero) in a 2x3 board,
    // represented as indices in a 1D flattened array.
    std::vector<std::vector<int>> possibleMoves = {
        {1, 3},    // Index 0 can move to indices 1 or 3
        {0, 2, 4}, // Index 1 can move to indices 0, 2, or 4
        {1, 5},    // Index 2 can move to indices 1 or 5
        {0, 4},    // Index 3 can move to indices 0 or 4
        {3, 5, 1}, // Index 4 can move to indices 3, 5, or 1
        {4, 2}     // Index 5 can move to indices 4 or 2
    };

public:
    int slidingPuzzle(std::vector<std::vector<int>> &board)
    {
        // Convert the 2D board into a single string representation
        // to use as the state during the DFS traversal.
        std::string initialState;
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                initialState += std::to_string(board[row][col]);
            }
        }

        // Map to store the minimum moves required to reach each visited state.
        std::unordered_map<std::string, int> visitedStates;

        // Perform a DFS search starting from the initial state.
        dfs(initialState, visitedStates, initialState.find('0'), 0);

        // Check if the target state "123450" was reached. If yes, return
        // the minimum moves required. If no, return -1.
        return visitedStates.count("123450") ? visitedStates["123450"] : -1;
    }

private:
    void dfs(std::string currentState, std::unordered_map<std::string, int> &visitedStates, int emptyTilePosition, int moveCount)
    {
        // If the current state has already been visited with fewer or equal moves, skip processing.
        if (visitedStates.count(currentState) && visitedStates[currentState] <= moveCount)
        {
            return;
        }

        // Record the current state with the minimum moves required to reach it.
        visitedStates[currentState] = moveCount;

        // Explore all possible moves for the empty tile (zero).
        for (int nextPosition : possibleMoves[emptyTilePosition])
        {
            // Swap the empty tile with the tile at the next position to generate a new state.
            std::swap(currentState[emptyTilePosition], currentState[nextPosition]);

            // Recursively call DFS with the new state, the updated empty tile position, and incremented move count.
            dfs(currentState, visitedStates, nextPosition, moveCount + 1);

            // Swap back to restore the original state (backtracking).
            std::swap(currentState[emptyTilePosition], currentState[nextPosition]);
        }
    }
};
int main()
{
    std::vector<std::vector<int>> board = {{1, 2, 3},
                                           {4, 0, 5}};
    SlidingPuzzle_773 s1;
    s1.slidingPuzzle(board);
    return 0;
}