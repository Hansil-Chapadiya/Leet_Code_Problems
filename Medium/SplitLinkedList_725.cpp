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

class SplitLinkedList_725
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // Step 1: Calculate the total length of the linked list
        int length = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            length += 1;
            temp = temp->next;
        }

        // Step 2: Calculate the size of each part
        int partSize = length / k;   // Minimum size of each part
        int extraNodes = length % k; // Extra nodes to distribute

        vector<ListNode *> result(k, nullptr); // Result vector to store the parts
        ListNode *current = head;

        for (int i = 0; i < k && current != nullptr; i++)
        {
            result[i] = current;                                       // Set the start of the current part
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0); // Distribute extra nodes if any
            extraNodes--;

            // Move to the end of the current part
            for (int j = 1; j < currentPartSize; j++)
            {
                current = current->next;
            }

            // Break the link to form the part
            ListNode *nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }

        return result;
    }
};

int main()
{
    SplitLinkedList_725 s1;
    int k = 5;

    // Create a linked list: 12 -> 14 -> 16 -> 10
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(10);

    // Split the list into k parts
    vector<ListNode *> parts = s1.splitListToParts(head, k);

    // Print the parts
    for (int i = 0; i < parts.size(); i++)
    {
        ListNode *part = parts[i];
        cout << "Part " << i + 1 << ": ";
        while (part != nullptr)
        {
            cout << part->val << " ";
            part = part->next;
        }
        cout << endl;
    }

    return 0;
}
static const int hansil = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();