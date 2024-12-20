#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

class ReverseOddLevelsOfBinaryTree_2415
{
public:
    std::vector<int> reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return {};

        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> levels; // Store each level as a vector
        q.push(root);

        int i = 0; // Track current level
        while (!q.empty())
        {
            int levelSize = q.size();
            std::vector<int> currentLevelNodes;

            for (int j = 0; j < levelSize; ++j)
            {
                TreeNode *current = q.front();
                q.pop();

                currentLevelNodes.push_back(current->val);

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            // Reverse nodes at odd levels
            if (i % 2 == 1)
            {
                std::reverse(currentLevelNodes.begin(), currentLevelNodes.end());
            }

            if (!currentLevelNodes.empty())
            {
                levels.push_back(currentLevelNodes);
            }
            i++;
        }

        // Flatten the level vector into a single result vector
        std::vector<int> result;
        for (auto &level : levels)
        {
            result.insert(result.end(), level.begin(), level.end());
        }

        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);

    ReverseOddLevelsOfBinaryTree_2415 r1;
    std::vector<int> res = r1.reverseOddLevels(root);
    for (auto i : res)
    {
        std::cout << i << " ";
    }

    return 0;
}
