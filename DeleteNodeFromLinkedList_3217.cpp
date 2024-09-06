#include <iostream>
#include <vector>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class DeleteNodeFromLinkedList_3217
{
private:
    /* data */
public:
    DeleteNodeFromLinkedList_3217(/* args */);
    ~DeleteNodeFromLinkedList_3217();
    ListNode *modifiedList(vector<int> &, ListNode *);
};
DeleteNodeFromLinkedList_3217::DeleteNodeFromLinkedList_3217(/* args */)
{
}

DeleteNodeFromLinkedList_3217::~DeleteNodeFromLinkedList_3217()
{
}
ListNode *DeleteNodeFromLinkedList_3217::modifiedList(vector<int> &nums, ListNode *head)
{
    ListNode *dummy = new ListNode(0); // Create a dummy node to simplify head deletion
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *temp = head;

    for (int i = 0; i < nums.size(); i++)
    {
        while (temp != nullptr && temp->val != nums[i])
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            // Remove the current node
            prev->next = temp->next;
            temp = temp->next; // Move to the next node
        }
    }

    return dummy->next; // Return the new head of the list
}

int main()
{
    DeleteNodeFromLinkedList_3217 D1;
    vector<int> nums = {1,2,3};

    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Deleting nodes
    ListNode *result = D1.modifiedList(nums, head);

    // Printing the modified list
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}