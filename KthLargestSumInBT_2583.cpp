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

class KthLargestSumInBT_2583
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        if (root == nullptr)
            return -1; // Handle empty tree case

        std::queue<TreeNode *> q;
        q.push(root);
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> min_heap;

        // BFS to traverse each level and compute the sum
        while (!q.empty())
        {
            int level_size = q.size();
            long long level_sum = 0;

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                level_sum += current->val;

                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }

            // Maintain a min-heap to track the top k largest sums
            min_heap.push(level_sum);
            if (min_heap.size() > k)
            {
                min_heap.pop(); // Remove the smallest sum if heap size exceeds k
            }
        }

        // If there are fewer levels than k, return -1 (error case)
        return min_heap.size() == k ? min_heap.top() : -1;
    }
};

int main()
{
    KthLargestSumInBT_2583 K1;

    // Creating a sample tree:
    //            1
    //           /
    //          2
    //         /
    //        3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    // Find the 1st largest level sum
    std::cout << "1st Largest Level Sum: " << K1.kthLargestLevelSum(root, 1) << std::endl;

    return 0;
}

static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();