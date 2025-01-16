#include <iostream>
#include <algorithm>

class SegmentTreeNode
{
public:
    int start, end;
    int count;    // The number of times this segment is booked
    int maxCount; // Maximum count in this segment
    SegmentTreeNode *left;
    SegmentTreeNode *right;

    SegmentTreeNode(int start, int end)
        : start(start), end(end), count(0), maxCount(0), left(nullptr), right(nullptr) {}
};

class MyCalendarII
{
private:
    SegmentTreeNode *root;

    // Helper function to update the segment tree for a new booking
    void update(SegmentTreeNode *node, int start, int end, int value)
    {
        if (start > node->end || end < node->start)
        {
            return;
        }

        if (start <= node->start && end >= node->end)
        {
            node->count += value;
            node->maxCount += value;
        }
        else
        {
            int mid = node->start + (node->end - node->start) / 2;

            if (!node->left)
            {
                node->left = new SegmentTreeNode(node->start, mid);
                node->right = new SegmentTreeNode(mid + 1, node->end);
            }

            update(node->left, start, end, value);
            update(node->right, start, end, value);

            node->maxCount = node->count + std::max(node->left ? node->left->maxCount : 0,
                                               node->right ? node->right->maxCount : 0);
        }
    }

    // Helper function to check if the new booking causes a triple booking
    int query(SegmentTreeNode *node, int start, int end)
    {
        if (!node || start > node->end || end < node->start)
        {
            return 0;
        }

        if (start <= node->start && end >= node->end)
        {
            return node->maxCount;
        }
        else
        {
            int leftMax = query(node->left, start, end);
            int rightMax = query(node->right, start, end);
            return node->count + std::max(leftMax, rightMax);
        }
    }

public:
    MyCalendarII()
    {
        root = new SegmentTreeNode(0, 1e9); // Initialize with a very large range to cover all possible bookings.
    }

    bool book(int start, int end)
    {
        // Check if adding this booking will result in a triple booking
        if (query(root, start, end - 1) >= 2)
        {
            return false;
        }

        // If no triple booking, update the segment tree
        update(root, start, end - 1, 1);
        return true;
    }
};

// Driver code to test the implementation
int main()
{
    MyCalendarII myCalendar;

    std::cout << (myCalendar.book(10, 20) ? "True" : "False") << std::endl; // Should return True
    std::cout << (myCalendar.book(50, 60) ? "True" : "False") << std::endl; // Should return True
    std::cout << (myCalendar.book(10, 40) ? "True" : "False") << std::endl; // Should return True
    std::cout << (myCalendar.book(5, 15) ? "True" : "False") << std::endl;  // Should return False
    std::cout << (myCalendar.book(5, 10) ? "True" : "False") << std::endl;  // Should return True
    std::cout << (myCalendar.book(25, 55) ? "True" : "False") << std::endl; // Should return True

    return 0;
}
