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
class FindElementsinContaminatedBinaryTree_1261
{
private:
    /* data */
public:
    FindElementsinContaminatedBinaryTree_1261(TreeNode *root)
    {
    }

    bool find(int target)
    {
    }
};
int main()
{
    TreeNode *root = new TreeNode(12);
    FindElementsinContaminatedBinaryTree_1261 *f1 = new FindElementsinContaminatedBinaryTree_1261(root);
    f1->find(12);
    return 0;
}
