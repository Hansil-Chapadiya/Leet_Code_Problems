#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
class RemoveSubFolderFromFileSystem_1233
{
private:
    /* data */
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string> &folder)
    {
        std::sort(folder.begin(), folder.end());

        std::vector<std::string> result = {folder[0]};

        for (int i = 1; i < folder.size(); i++)
        {
            std::string lastelement = result.back();
            lastelement.push_back('/');

            if (folder[i].compare(0, lastelement.size(), lastelement) != 0)
            {
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};
int main()
{
    RemoveSubFolderFromFileSystem_1233 r1;
    std::vector<std::string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    std::vector<std::string> result = r1.removeSubfolders(folder);
    for (std::string str : result)
    {
        std::cout << str << " ";
    }

    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();