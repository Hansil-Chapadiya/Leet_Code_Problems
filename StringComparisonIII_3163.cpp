#include <iostream>
#include <string>
class StringComparisonIII_3163
{
private:
    /* data */
public:
    std::string compressedString(std::string word)
    {
        if (word.length() == 1)
        {
            return "1" + word;
        }

        std::string comp;
        comp = "";
        int cnt = 1;
        for (int i = 1; i <= word.length(); i++)
        {
            while (word[i] == word[i - 1] && cnt < 9)
            {
                cnt++;
                if (i < word.length())
                {
                    i++;
                }
            }
            comp += std::to_string(cnt);
            comp += word[i - 1];
            cnt = 1;
        }
        return comp;
    }
};
int main()
{
    StringComparisonIII_3163 s1;
    std::string word = "abcde";
    // std::string word = "aaaaaaaaaaaaaabb";
    // std::string word = "o";
    // std::string word = "vvv";
    std::cout << s1.compressedString(word);
    return 0;
}

/*
#include <iostream>
#include <string>

class StringComparisonIII_3163
{
public:
    std::string compressedString(std::string word)
    {
        // Handle edge case of a single character string
        if (word.length() == 1)
        {
            return "1" + word;
        }

        std::string comp = ""; // Initialize compressed result string
        int cnt = 1;           // Initialize character count

        for (int i = 1; i < word.length(); i++) // Iterate from the second character
        {
            if (word[i] == word[i - 1] && cnt < 9) // Check if current char is same as previous and cnt < 9
            {
                cnt++; // Increment count if characters match
            }
            else
            {
                // Append count and character to result string when sequence ends
                comp += std::to_string(cnt) + word[i - 1];
                cnt = 1; // Reset count
            }
        }

        // Append the last counted sequence
        comp += std::to_string(cnt) + word[word.length() - 1];

        return comp; // Return the compressed string
    }
};

// Example usage
int main()
{
    StringComparisonIII_3163 compressor;
    std::string input = "aaabbccccd";
    std::string result = compressor.compressedString(input);
    std::cout << "Compressed string: " << result << std::endl;
    return 0;
}

*/