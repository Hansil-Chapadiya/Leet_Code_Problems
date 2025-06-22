#include <iostream>
#include <string>
#include <vector>

class DivideStringIntoGroupsOfSizeK
{
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> answer;
        int len = s.length();
        int i = 0;

        while (i < len) {
            int cnt = 0;
            std::string temp = "";
            while ((cnt < k) && (i < len)) {
                temp += s[i];
                i++;
                cnt++;
            }
            answer.push_back(temp);
        }

        std::string last = answer.back();
        if (last.length() < k) {
            last.append(k - last.length(), fill);
            answer.pop_back();
            answer.push_back(last);
        }

        return answer;
    }
};

int main()
{
    DivideStringIntoGroupsOfSizeK d1;
    std::vector<std::string> answer = d1.divideString("abcdefghij", 3, 'x');

    for (std::string str : answer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}