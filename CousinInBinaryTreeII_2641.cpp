#include <iostream>
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
class CousinInBinaryTreeII_2641
{
private:
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
    }
};
int main()
{
    CousinInBinaryTreeII_2641 c1;
    TreeNode *root = new TreeNode(5);
    c1.replaceValueInTree(root);
    return 0;
}