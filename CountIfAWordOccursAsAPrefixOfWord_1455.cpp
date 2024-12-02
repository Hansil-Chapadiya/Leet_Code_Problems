#include <iostream>
#include <sstream>
#include <vector>
#include <string>
class CountIfAWordOccursAsAPrefixOfWord_1455
{
private:
    std::vector<std::string> getExtractedWord(std::string sentence)
    {
        std::stringstream ss(sentence);
        std::vector<std::string> vec_str;
        std::string word;
        while (ss >> word)
        {
            vec_str.push_back(word);
        }

        return vec_str;
    }

public:
    int isPrefixOfWord(std::string sentence, std::string searchWord)
    {
        int flag = 0;
        int i = 0;
        std::vector<std::string> extracted_string = getExtractedWord(sentence);
        for (i = 0; i < extracted_string.size(); i++)
        {
            if (extracted_string[i].find(searchWord) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            return i + 1;
        }
    }
};
int main()
{
    // std::string sentence = "i love eating burger";
    std::string sentence = "this problem is an easy problem";
    // std::string searchword = "burg";
    std::string searchword = "pro";
    CountIfAWordOccursAsAPrefixOfWord_1455 c1;
    std::cout << c1.isPrefixOfWord(sentence, searchword);
    return 0;
}