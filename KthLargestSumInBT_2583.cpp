#include <iostream>
#include <queue>
class TreeNode
{
    int val;
    TreeNode *root;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};
class KthLargestSumInBT_2583
{
private:
    /* data */
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
    }
};
int main()
{

    return 0;
}
