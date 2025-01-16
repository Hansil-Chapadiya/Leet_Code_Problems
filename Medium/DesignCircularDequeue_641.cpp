#include <iostream>
#include <vector>

class DesignCircularDequeue_641
{
private:
    int rear, front;
    std::vector<int> queue;

public:
    DesignCircularDequeue_641(int k)
    {
        queue.resize(k, 0);
        front = rear = -1;
    }

    // Inserts an element at the front of the deque
    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[front] = value;
        }
        else if (front == 0)
        {
            front = queue.size() - 1;
            queue[front] = value;
        }
        else
        {
            front -= 1;
            queue[front] = value;
        }
        return true;
    }

    // Inserts an element at the end of the deque
    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        else if (rear == -1 && front == -1)
        {
            rear = front = 0;
            queue[rear] = value;
        }
        else if (rear == queue.size() - 1)
        {
            rear = 0;
            queue[rear] = value;
        }
        else
        {
            rear += 1;
            queue[rear] = value;
        }
        return true;
    }

    // Deletes an element from the front of the deque
    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }
        else if (front == rear)
        {
            front = rear = -1; // Single element case
        }
        else if (front == queue.size() - 1)
        {
            front = 0; // Wrap around
        }
        else
        {
            front += 1;
        }
        return true;
    }

    // Deletes an element from the end of the deque
    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        else if (rear == front)
        {
            rear = front = -1; // Single element case
        }
        else if (rear == 0)
        {
            rear = queue.size() - 1; // Wrap around
        }
        else
        {
            rear -= 1;
        }
        return true;
    }

    // Returns the front element of the deque
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return queue[front];
    }

    // Returns the rear element of the deque
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return queue[rear];
    }

    // Checks whether the deque is empty
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    // Checks whether the deque is full
    bool isFull()
    {
        return (front == 0 && rear == queue.size() - 1) || (front == rear + 1);
    }

    // Display the deque contents for debugging
    void display()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty\n";
            return;
        }

        int i = front;
        std::cout << "Elements in the deque are: ";
        while (i != rear)
        {
            std::cout << queue[i] << " ";
            i = (i + 1) % queue.size();
        }
        std::cout << queue[rear] << "\n";
    }
};

int main()
{
    DesignCircularDequeue_641 d1(3);

    // Test cases
    std::cout << " " << d1.insertLast(1);
    std::cout << " " << d1.insertLast(2);
    std::cout << " " << d1.insertFront(3);
    std::cout << " " << d1.insertFront(4);
    std::cout << " " << "Rear Element: " << d1.getRear() << std::endl;            // Should return 3
    std::cout << " " << "Is Full: " << (d1.isFull() ? "Yes" : "No") << std::endl; // Should return No
    std::cout << " " << d1.deleteLast();
    std::cout << " " << d1.insertFront(4);
    std::cout << " " << "Front Element: " << d1.getFront() << std::endl; // Should return 4
    // d1.display(); // Should display: 4 1 2 3

    // d1.deleteFront();

    // d1.display(); // Should display: 1 2

    // std::cout << "Is Empty: " << (d1.isEmpty() ? "Yes" : "No") << std::endl; // Should return No

    return 0;
}
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();