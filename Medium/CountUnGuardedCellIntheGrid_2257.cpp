#include <iostream>
#include <vector>

class CountUnGuardedCellIntheGrid_2257
{
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards, std::vector<std::vector<int>> &walls)
    {
        int unguarded = m * n;
        std::vector<std::vector<int>> temp(m, std::vector<int>(n, 0));

        // Mark walls (119) and guards (104) in the grid
        for (const auto &wall : walls)
        {
            temp[wall[0]][wall[1]] = 119;
        }

        for (const auto &guard : guards)
        {
            temp[guard[0]][guard[1]] = 104;
        }

        // Directions for guard visibility: right, down, left, up
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Mark guarded cells
        for (const auto &guard : guards)
        {
            for (const auto &[dx, dy] : directions)
            {
                int x = guard[0];
                int y = guard[1];

                while (true)
                {
                    x += dx;
                    y += dy;

                    // Check if out of bounds
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        break;

                    // Stop at walls or other guards
                    if (temp[x][y] == 119 || temp[x][y] == 104)
                        break;

                    // Mark as guarded
                    if (temp[x][y] == 0)
                    {
                        temp[x][y] = -1; // -1 indicates guarded cell
                    }
                }
            }
        }

        // Count unguarded cells
        int guarded = 0;
        for (const auto &row : temp)
        {
            for (int cell : row)
            {
                if (cell == -1 || cell == 104 || cell == 119)
                    guarded++;
            }
        }

        return unguarded - guarded;
    }
};

int main()
{
    CountUnGuardedCellIntheGrid_2257 c1;
    int m = 4, n = 6;
    std::vector<std::vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    std::vector<std::vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

    std::cout << c1.countUnguarded(m, n, guards, walls) << std::endl;
    return 0;
}
