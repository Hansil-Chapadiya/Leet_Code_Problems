#include <iostream>
#include <vector>
#include <utility>
using namespace std;

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

class LowestCommonAncestorofDeepestLeaves_1123
{
public:
    // Returns pair of <depth, LCA node>
    pair<int, TreeNode *> dfs(TreeNode *node)
    {
        if (!node)
            return {0, nullptr};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.first > right.first)
            return {left.first + 1, left.second};
        if (right.first > left.first)
            return {right.first + 1, right.second};

        return {left.first + 1, node}; // equal depth, this node is LCA
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).second;
    }
};

int main()
{
    LowestCommonAncestorofDeepestLeaves_1123 l1;

    // Level 1
    TreeNode *root = new TreeNode(3);

    // Level 2
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    // Level 3
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8); // Fixed typo

    // Level 4
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *ansRoot = l1.lcaDeepestLeaves(root);
    if (ansRoot)
        cout << "LCA of Deepest Leaves: " << ansRoot->val << endl;
    else
        cout << "Tree is empty." << endl;

    return 0;
}
