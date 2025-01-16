#include <iostream>
#include <unordered_map>
#include <string>

class PermutationInString_567 {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) return false;

        std::unordered_map<char, int> s1_count, s2_count;

        // Initialize the character count for s1 and the first window in s2
        for (char c : s1) {
            s1_count[c]++;
        }

        for (int i = 0; i < s1.length(); i++) {
            s2_count[s2[i]]++;
        }

        // Compare the maps
        if (s1_count == s2_count) {
            return true; // The first window is a permutation
        }

        // Slide the window over s2
        for (int i = s1.length(); i < s2.length(); i++) {
            s2_count[s2[i]]++; // Add the next character to the window
            s2_count[s2[i - s1.length()]]--; // Remove the character going out of the window

            // Clean up the map to prevent it from growing indefinitely
            if (s2_count[s2[i - s1.length()]] == 0) {
                s2_count.erase(s2[i - s1.length()]);
            }

            // Compare the frequency maps
            if (s1_count == s2_count) {
                return true; // Found a permutation
            }
        }

        return false; // No permutation found
    }
};

int main() {
    PermutationInString_567 p1;
    std::cout << p1.checkInclusion("ab", "eidboaoo"); // Output: 1 (true)
}
