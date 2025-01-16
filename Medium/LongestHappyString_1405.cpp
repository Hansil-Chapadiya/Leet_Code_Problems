#include <iostream>
#include <queue>
#include <string>

struct Node {
    char label;
    int count;

    // For max-heap behavior
    bool operator<(const Node& other) const {
        return count < other.count;
    }
};

class LongestHappyString {
public:
    std::string longestDiverseString(int a, int b, int c) {
        std::priority_queue<Node> occurance;
        if (a > 0) occurance.push(Node{'a', a});
        if (b > 0) occurance.push(Node{'b', b});
        if (c > 0) occurance.push(Node{'c', c});

        std::string longesthappystring;

        while (!occurance.empty()) {
            // Get the most frequent character
            Node first = occurance.top();
            occurance.pop();

            // Check if we can add this character without violating the no "aaa", "bbb", or "ccc" rule
            if (longesthappystring.size() >= 2 && longesthappystring[longesthappystring.size() - 1] == first.label && longesthappystring[longesthappystring.size() - 2] == first.label) {
                // If we can't add the first character, try the second most frequent character
                if (occurance.empty()) {
                    break; // No more valid characters to add
                }

                Node second = occurance.top();
                occurance.pop();

                // Add the second most frequent character
                longesthappystring += second.label;
                second.count--;

                // Push it back to the heap if it still has occurrences
                if (second.count > 0) {
                    occurance.push(second);
                }

                // Push the first character back into the heap to try again later
                occurance.push(first);
            } else {
                // Add the most frequent character
                longesthappystring += first.label;
                first.count--;

                // Push it back to the heap if it still has occurrences
                if (first.count > 0) {
                    occurance.push(first);
                }
            }
        }

        return longesthappystring;
    }
};

int main() {
    LongestHappyString happyString;

    std::cout << happyString.longestDiverseString(1, 1, 7) << std::endl; // Example output: "ccbccacc"
    std::cout << happyString.longestDiverseString(2, 2, 1) << std::endl; // Example output: "abbac"
    std::cout << happyString.longestDiverseString(0, 0, 0) << std::endl; // Example output: ""

    return 0;
}
