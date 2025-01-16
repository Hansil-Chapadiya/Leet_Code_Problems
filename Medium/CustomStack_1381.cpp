#include <iostream>
#include <stack>

// Class representing a custom stack with additional features
class CustomStack
{
private:
    int top;                 // Keeps track of the current top index (not used in this implementation)
    std::stack<int> stk;     // Main stack to hold elements
    std::stack<int> tmp_stk; // Temporary stack used for intermediate operations
    int maxSize;             // Maximum size of the stack

public:
    // Constructor to initialize stack with given maximum size
    CustomStack(int maxSize) : maxSize(maxSize) {}

    // Function to push an element onto the stack if it is not full
    void push(int x)
    {
        if (stk.size() < maxSize) // Check if stack has space for more elements
        {
            stk.push(x); // Push the element onto the stack
        }
    }

    // Function to pop an element from the stack and return its value
    int pop()
    {
        if (stk.empty()) // Check if the stack is empty
            return -1;   // Return -1 if stack is empty

        int pop_val = stk.top(); // Get the top element of the stack
        stk.pop();               // Remove the top element
        return pop_val;          // Return the popped value
    }

    // Function to increment the bottom `k` elements by a specified value `val`
    void increment(int k, int val)
    {
        if (k >= stk.size()) // If k is greater than or equal to the number of elements in the stack
        {
            // Increment all elements in the stack by `val`
            while (!stk.empty())
            {
                tmp_stk.push(stk.top() + val); // Push incremented value onto the temporary stack
                stk.pop();                     // Remove the original element from the main stack
            }
        }
        else
        {
            // If `k` is less than the stack size, only increment the bottom `k` elements
            while (stk.size() > k) // Move elements from the main stack to temporary stack until only `k` remain
            {
                tmp_stk.push(stk.top()); // Preserve elements not to be incremented
                stk.pop();               // Remove from the main stack
            }

            // Increment the remaining `k` elements
            while (!stk.empty())
            {
                tmp_stk.push(stk.top() + val); // Push incremented values onto temporary stack
                stk.pop();                     // Remove from the main stack
            }
        }

        // Restore all elements from the temporary stack back to the main stack
        while (!tmp_stk.empty())
        {
            stk.push(tmp_stk.top()); // Push elements back to main stack
            tmp_stk.pop();           // Remove from temporary stack
        }
    }

    // Function to display all elements in the stack (from top to bottom)
    void display()
    {
        while (!stk.empty())
        {
            std::cout << stk.top() << " "; // Print the top element
            stk.pop();                     // Remove the top element
        }
    }

    // Helper function to get the value at the top of the stack (if needed)
    int top_()
    {
        return stk.top();
    }
};

// Main driver code to test the custom stack functionality
int main()
{
    CustomStack stk1(4); // Create a custom stack with maximum size 4

    stk1.push(1); // Push elements onto the stack
    stk1.push(2);
    stk1.push(3);

    stk1.increment(5, 100); // Increment all elements by 100 (since `k` > current size)
    stk1.increment(2, 100); // Increment bottom 2 elements by 100

    stk1.display(); // Display the final elements in the stack
}
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();