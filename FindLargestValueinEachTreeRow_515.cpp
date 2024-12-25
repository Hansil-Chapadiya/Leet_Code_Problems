#include <iostream>
#include <vector>
#include <queue>

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

class FindLargestValueinEachTreeRow_515
{
public:
    std::vector<int> largestValues(TreeNode *root)
    {
        std::vector<int> max_at_level;
        if (!root)
            return max_at_level; // Return empty vector if tree is empty.

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int level_size = q.size(); // Number of nodes at the current level.
            int max_value = INT_MIN;

            for (int i = 0; i < level_size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // Update max_value for the current level.
                max_value = std::max(max_value, node->val);

                // Add child nodes to the queue.
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Add the largest value of this level to the result vector.
            max_at_level.push_back(max_value);
        }

        return max_at_level;
    }
};

int main()
{
    FindLargestValueinEachTreeRow_515 f1;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    std::vector<int> max_at_level = f1.largestValues(root);

    for (auto i : max_at_level)
    {
        std::cout << i << " ";
    }

    return 0;
}
