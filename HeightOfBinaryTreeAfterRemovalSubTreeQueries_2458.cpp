#include <iostream>
#include <vector>
class TreeNode
{
public:
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class HeightOfBinaryTreeAfterRemovalSubTreeQueries_2458
{
private:
    /* data */
public:
    std::vector<int> treeQueries(TreeNode *root, std::vector<int> &queries)
    {
    }
};
int main()
{
    HeightOfBinaryTreeAfterRemovalSubTreeQueries_2458 h1;
    TreeNode *root = new TreeNode(20);
    std::vector<int> queries = {2};
    h1.treeQueries(root, queries);
    return 0;
}