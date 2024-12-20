#include <iostream>
#include <vector>
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
private:
    /* data */
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
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
    return 0;
}