#include <vector>
#include <iostream>
class TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class ConstructBinaryTreefromPreorderandPostorderTraversal_889
{
private:
public:
    TreeNode *constructFromPrePost(std::vector<int> &preorder, std::vector<int> &postorder)
    {
    }
};
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();