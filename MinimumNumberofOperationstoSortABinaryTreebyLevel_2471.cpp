#include <iostream>
#include <vector>
#include <deque>

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
class MinimumNumberofOperationstoSortABinaryTreebyLevel_2471
{
private:
    /* data */
public:
    int minimumOperations(TreeNode *root)
    {
    }
};
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
    std::cout << m1.minimumOperations(root);
    return 0;
}