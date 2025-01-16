#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// Definition of TreeNode
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Class to calculate minimum number of operations
class MinimumNumberofOperationstoSortABinaryTreebyLevel_2471
{
private:
    // Helper function to calculate minimum swaps needed to sort a level
    int minSwap(std::vector<int> level)
    {
        int n = level.size();
        std::vector<std::pair<int, int>> sorted_array;

        // Pair each value with its original index
        for (int i = 0; i < n; i++)
        {
            sorted_array.push_back({level[i], i});
        }

        // Sort based on the values
        std::sort(sorted_array.begin(), sorted_array.end());

        // Visited array to mark processed indices
        std::vector<bool> visited(n, false);
        int swaps = 0;

        // Cycle detection
        for (int i = 0; i < n; i++)
        {
            if (visited[i] || sorted_array[i].second == i)
            {
                continue; // Skip if already in the correct position
            }

            // Find the size of the cycle
            int cycle_size = 0;
            int x = i;

            while (!visited[x])
            {
                visited[x] = true;
                x = sorted_array[x].second; // Move to the next index in the cycle
                cycle_size++;
            }

            // Add the number of swaps required for this cycle
            if (cycle_size > 1)
            {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }

public:
    // Function to calculate minimum operations
    int minimumOperations(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        std::deque<TreeNode *> q;
        q.push_back(root);

        std::vector<std::vector<int>> levels;

        // Perform level-order traversal
        while (!q.empty())
        {
            int level_size = q.size(); // Correct size of the current level
            std::vector<int> current_level;
            for (int i = 0; i < level_size; i++)
            {
                TreeNode *node = q.front();
                q.pop_front();
                current_level.push_back(node->val);
                if (node->left)
                {
                    q.push_back(node->left);
                }
                if (node->right)
                {
                    q.push_back(node->right);
                }
            }
            levels.push_back(current_level);
        }

        // Calculate total swaps for all levels
        int total_swap = 0;
        for (auto level : levels)
        {
            total_swap += minSwap(level);
        }
        return total_swap;
    }
};

// Main function to test the solution
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    MinimumNumberofOperationstoSortABinaryTreebyLevel_2471 m1;
    std::cout << "Minimum Operations: " << m1.minimumOperations(root) << std::endl;
    return 0;
}
