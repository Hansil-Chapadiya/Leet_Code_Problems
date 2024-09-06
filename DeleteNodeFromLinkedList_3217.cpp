#include <iostream>
#include <vector>
#include <algorithm>
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
    //If the list is empty
    if (head == nullptr)
    {
        return nullptr;
    }

    //If the head node should be deleted first
    while (head != nullptr && find(nums.begin(), nums.end(), head->val) != nums.end())
    {
        head = head->next; // Move the head to the next node if it needs to be deleted
    }

    // If the list becomes empty after removing the head nodes
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode *prev = head;
    ListNode *temp = head->next;

    // Traverse the list and remove nodes that are in nums
    while (temp != nullptr)
    {
        if (find(nums.begin(), nums.end(), temp->val) != nums.end())
        {
            prev->next = temp->next; // Remove the node
        }
        else
        {
            prev = temp; // Move prev forward if no deletion occurs
        }
        temp = temp->next; // Always move temp forward
    }

    return head; // Return the modified list
}

int main()
{
    DeleteNodeFromLinkedList_3217 D1;
    vector<int> nums = {1, 2,3};

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


// ListNode *DeleteNodeFromLinkedList_3217::modifiedList(vector<int> &nums, ListNode *head)
// {
//     ListNode *temp_node = new ListNode(0); // Create a dummy node to simplify head deletion
//     temp_node->next = head;
//     ListNode *prev = temp_node;
//     ListNode *temp = head;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         while (temp != nullptr && temp->val != nums[i])
//         {
//             prev = temp;
//             temp = temp->next;
//         }

//         if (temp != nullptr)
//         {
//             // Remove the current node
//             prev->next = temp->next;
//             temp = temp->next; // Move to the next node
//         }
//     }

//     return temp_node->next; // Return the new head of the list
// }

// int main()
// {
//     DeleteNodeFromLinkedList_3217 D1;
//     vector<int> nums = {1,2,3};

//     // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
//     ListNode *head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);

//     // Deleting nodes
//     ListNode *result = D1.modifiedList(nums, head);

//     // Printing the modified list
//     while (result != nullptr)
//     {
//         cout << result->val << " ";
//         result = result->next;
//     }
//     cout << endl;

//     return 0;
// }