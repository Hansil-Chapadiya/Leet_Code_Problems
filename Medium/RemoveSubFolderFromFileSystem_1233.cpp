/* #include <vector>
#include <iostream>
#include <string>
#include <algorithm>
class RemoveSubFolderFromFileSystem_1233
{
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
}(); */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<std::string, TrieNode*> children;  // To store subfolders
    bool isEndOfFolder;  // True if this node marks the end of a folder

    TrieNode() : isEndOfFolder(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a folder path into the Trie
    bool insert(const std::vector<std::string>& folderParts) {
        TrieNode* node = root;
        for (const auto& part : folderParts) {
            if (node->isEndOfFolder) {
                // If we reach an already completed folder, no need to insert subfolders
                return false;
            }
            if (node->children.find(part) == node->children.end()) {
                node->children[part] = new TrieNode();
            }
            node = node->children[part];
        }
        node->isEndOfFolder = true;  // Mark the end of this folder
        return true;
    }

    // Perform DFS to collect all valid folder paths
    void collectFolders(TrieNode* node, std::string currentPath, std::vector<std::string>& result) {
        if (node->isEndOfFolder) {
            result.push_back(currentPath);  // If it's a complete folder, add it to the result
            return;  // No need to go deeper since subfolders are not allowed
        }

        for (const auto& child : node->children) {
            collectFolders(child.second, currentPath + "/" + child.first, result);
        }
    }
};

std::vector<std::string> splitPath(const std::string& folder) {
    std::vector<std::string> parts;
    std::string part;
    for (char c : folder) {
        if (c == '/') {
            if (!part.empty()) {
                parts.push_back(part);
                part.clear();
            }
        } else {
            part += c;
        }
    }
    if (!part.empty()) {
        parts.push_back(part);
    }
    return parts;
}

std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
    Trie trie;
    for (const std::string& f : folder) {
        std::vector<std::string> folderParts = splitPath(f);
        trie.insert(folderParts);
    }

    // Collect all top-level folders (those without sub-folders) from the Trie
    std::vector<std::string> result;
    trie.collectFolders(trie.root, "", result);
    return result;
}

int main() {
    // Example folders
    std::vector<std::string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};

    // Remove subfolders
    std::vector<std::string> result = removeSubfolders(folder);

    // Output the result
    for (const std::string& f : result) {
        std::cout << f << std::endl;
    }

    return 0;
}
