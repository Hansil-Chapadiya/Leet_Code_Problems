#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

class StringMatchingInArray
{
public:
    std::vector<std::string> stringMatching(std::vector<std::string> &words)
    {
        std::set<std::string> set_;
        for (size_t i = 0; i < words.size(); i++)
        {
            for (size_t j = 0; j < words.size(); j++)
            {
                if (i != j && words[i].find(words[j]) != std::string::npos)
                {
                    set_.insert(words[j]); // Store the substring
                }
            }
        }
        // Convert set to vector and return
        return std::vector<std::string>(set_.begin(), set_.end());
    }
};

int main()
{
    std::vector<std::string> words = {"mass", "as", "hero", "superhero"};
    StringMatchingInArray s1;
    std::vector<std::string> result = s1.stringMatching(words);

    // Print the result
    for (const auto &word : result)
    {
        std::cout << word << " ";
    }
    return 0;
}
