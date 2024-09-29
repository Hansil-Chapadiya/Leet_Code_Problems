#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>

// Doubly linked list node structure
class ListNode_
{
public:
    int count;                            // Frequency count
    std::unordered_set<std::string> keys; // Set of keys with this count
    ListNode_ *prev, *next;                // Pointers to previous and next nodes in the list

    ListNode_(int cnt) : count(cnt), prev(nullptr), next(nullptr) {}
};

class AllOOneDataStructure
{
private:
    std::unordered_map<std::string, int> keyCount; // Maps key -> frequency count
    std::unordered_map<int, ListNode_ *> countNode; // Maps frequency count -> list node
    ListNode_ *head, *tail;                         // Dummy head and tail for the doubly linked list

    // Inserts a new node with a given count after a specified node
    ListNode_ *insertNodeAfter(ListNode_ *node, int count)
    {
        ListNode_ *newNode = new ListNode_(count);
        newNode->next = node->next;
        newNode->prev = node;
        if (node->next)
            node->next->prev = newNode;
        node->next = newNode;
        return newNode;
    }

    // Removes a node from the doubly linked list
    void removeNode(ListNode_ *node)
    {
        node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        countNode.erase(node->count);
        delete node;
    }

public:
    AllOOneDataStructure()
    {
        // Initialize the doubly linked list with dummy head and tail nodes
        head = new ListNode_(0); // Dummy head node
        tail = new ListNode_(0); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    void inc(std::string key)
    {
        int count = keyCount[key]; // Get current count of key
        keyCount[key] = count + 1; // Increment key's count

        ListNode_ *curNode = (count == 0) ? head : countNode[count];
        ListNode_ *nextNode = curNode->next;

        // If there is no node for count + 1, create a new one
        if (nextNode == tail || nextNode->count > count + 1)
        {
            nextNode = insertNodeAfter(curNode, count + 1);
            countNode[count + 1] = nextNode;
        }

        // Move the key to the next node
        nextNode->keys.insert(key);
        if (count != 0)
        { // Remove the key from the current node
            curNode->keys.erase(key);
            if (curNode->keys.empty())
                removeNode(curNode);
        }
    }

    void dec(std::string key)
    {
        int count = keyCount[key]; // Get current count of key
        if (count == 0)
            return;

        ListNode_ *curNode = countNode[count];
        keyCount[key] = count - 1;

        if (count == 1)
        {
            keyCount.erase(key); // Remove key if its count is 0
        }
        else
        {
            ListNode_ *prevNode = curNode->prev;
            // If there is no node for count - 1, create a new one
            if (prevNode == head || prevNode->count < count - 1)
            {
                prevNode = insertNodeAfter(curNode->prev, count - 1);
                countNode[count - 1] = prevNode;
            }
            prevNode->keys.insert(key);
        }

        // Remove the key from the current node
        curNode->keys.erase(key);
        if (curNode->keys.empty())
            removeNode(curNode);
    }

    std::string getMaxKey()
    {
        // Get one of the keys with the maximum count
        return head->next == tail ? "" : *(tail->prev->keys.begin());
    }

    std::string getMinKey()
    {
        // Get one of the keys with the minimum count
        return head->next == tail ? "" : *(head->next->keys.begin());
    }
};
int main()
{
    AllOOneDataStructure *obj = new AllOOneDataStructure();
    obj->inc("hello");
    obj->inc("hello");
    std::cout << obj->getMaxKey(); // return "hello"
    std::cout << obj->getMinKey(); // return "hello"
    obj->inc("leet");
    std::cout << obj->getMaxKey(); // return "hello"
    std::cout << obj->getMinKey(); // return "leet"
    std::string param_3 = obj->getMaxKey();
    std::string param_4 = obj->getMinKey();
    return 0;
}