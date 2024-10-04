#include <iostream>
#include <vector>
#include <unordered_map>
class DividePlayerIntoTeamEqualSkill_2491
{
private:
public:
    long long dividePlayers(std::vector<int> &skill)
    {
        std::unordered_map<int, int> u_map;
        for (int i = 0; i < (skill.size() / 2); i++)
        {
            for (int j = (skill.size() / 2); j < skill.size(); j++)
            {
                u_map[i] = skill[i] + skill[j];
            }
        }

        for (auto &pair : u_map)
        {
            std::cout << pair.first << " -> " << pair.second << std::endl;
        }
    }
};
