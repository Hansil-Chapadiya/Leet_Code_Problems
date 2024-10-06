#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
class SentenceSimilarityIII_1813
{
private:
    /* not working when string is partioned in two parts */
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2)
    {
        std::vector<std::string> s1_arr, s2_arr;
        std::stringstream ss1(sentence1);
        std::stringstream ss2(sentence2);
        std::string word;
        while (ss1 >> word)
        {
            s1_arr.push_back(word);
        }
        word = '\0';
        while (ss2 >> word)
        {
            s2_arr.push_back(word);
        }

        if (s1_arr.size() > s2_arr.size())
        {
            for (int i = 0; i < s1_arr.size(); i++)
            {
                if (std::find(s2_arr.begin(), s2_arr.end(), s1_arr.at(i)) == s2_arr.end())
                {
                    s2_arr.push_back(s1_arr.at(i));
                }
            }
        }
        else
        {
            for (int i = 0; i < s2_arr.size(); i++)
            {
                if (std::find(s1_arr.begin(), s1_arr.end(), s2_arr.at(i)) == s1_arr.end())
                {
                    s1_arr.push_back(s2_arr.at(i));
                }
            }
        }
        if (s1_arr.size() == s2_arr.size())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    SentenceSimilarityIII_1813 s1;
    std::cout << s1.areSentencesSimilar("Hello Jane", "Hello my name is Jane");
    std::cout << s1.areSentencesSimilar("of", "A lot of words");
    return 0;
}
