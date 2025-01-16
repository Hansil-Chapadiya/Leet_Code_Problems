#include <iostream>
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
class FlipEquivalentBT_951
{
private:
    /* data */
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        else if (!root1 || !root2 || root1->val != root2->val)
        {
            return false;
        }
        else
        {
            return (flipEquiv(root1->left, root2->left) || flipEquiv(root1->left, root2->right)) && (flipEquiv(root1->right, root2->right) || flipEquiv(root1->right, root2->left));
        }
    }
};
int main()
{
    FlipEquivalentBT_951 f1;
    TreeNode *root1 = new TreeNode(20);
    TreeNode *root2 = new TreeNode(20);
    std::cout << f1.flipEquiv(root1, root2);
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();