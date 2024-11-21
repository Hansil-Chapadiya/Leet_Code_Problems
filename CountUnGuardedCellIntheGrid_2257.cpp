#include <iostream>
#include <vector>
class CountUnGuardedCellIntheGrid_2257
{
private:
    /* data */
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards, std::vector<std::vector<int>> &walls)
    {
    }
};
int main()
{
    CountUnGuardedCellIntheGrid_2257 c1;
    int m = 4;
    int n = 6;
    std::vector<std::vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    std::vector<std::vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
    c1.countUnguarded(m, n, guards, walls);
    return 0;
}