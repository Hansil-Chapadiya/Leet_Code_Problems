#include <iostream>
#include <vector>
#include <string>

class AddingSpacingToAString_2109
{
private:
    /* data */
public:
    std::string addSpaces(std::string s, std::vector<int> &spaces)
    {
        std::string temp;
        int j = 0;
        for (int i = 0; i < spaces.size(); i++)
        {
            s.insert(spaces[i] + j, " ");
            j++;
        }
        return s;

        /*
        std::string result;
            result.reserve(s.size() + spaces.size()); // Pre-allocate memory to avoid reallocations

            int j = 0; // Index for spaces vector
            for (int i = 0; i < s.size(); i++) {
                if (j < spaces.size() && i == spaces[j]) {
                    result += ' '; // Insert space
                    j++;
                }
                result += s[i]; // Add current character
            }

            return result;
        */
    }
};
int main()
{
    AddingSpacingToAString_2109 a1;
    std::vector<int> spaces = {5, 9};
    std::string s = "EnjoyYourCoffee";
    std::cout << a1.addSpaces(s, spaces);
}

/*
std::string result;
    result.reserve(s.size() + spaces.size()); // Reserve memory for efficiency

    int prev = 0; // Tracks the start of the next substring
    for (int space : spaces) {
        // Append the substring from the previous position to the current space position
        result += s.substr(prev, space - prev);
        result += ' '; // Add the space
        prev = space; // Move the start position forward
    }

    // Append the remainder of the string
    result += s.substr(prev);
    return result;
*/