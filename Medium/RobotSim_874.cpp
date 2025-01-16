// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <algorithm> // for std::max

// using namespace std;

// enum Direction
// {
//     NORTH,
//     EAST,
//     SOUTH,
//     WEST
// };

// class RobotSim_874
// {
// private:
//     bool isObstacle(const tuple<int, int> &position, const vector<vector<int>> &obstacles)
//     {
//         for (const auto &obstacle : obstacles)
//         {
//             if (get<0>(position) == obstacle[0] && get<1>(position) == obstacle[1])
//             {
//                 return true;
//             }
//         }
//         return false;
//     }

// public:
//     RobotSim_874() {}
//     ~RobotSim_874() {}
//     int robotSim(vector<int> &commands, vector<vector<int>> &obstacles);
// };

// int RobotSim_874::robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
// {
//     tuple<int, int> start_pos = make_tuple(0, 0);
//     Direction current_direction = NORTH;
//     int max_distance_squared = 0;

//     for (int i = 0; i < commands.size(); i++)
//     {
//         if (commands[i] == -2) // Turn left
//         {
//             current_direction = static_cast<Direction>((current_direction + 3) % 4);
//         }
//         else if (commands[i] == -1) // Turn right
//         {
//             current_direction = static_cast<Direction>((current_direction + 1) % 4);
//         }
//         else // Move forward
//         {
//             for (int step = 0; step < commands[i]; ++step)
//             {
//                 int x = get<0>(start_pos);
//                 int y = get<1>(start_pos);

//                 switch (current_direction)
//                 {
//                 case NORTH:
//                     y += 1;
//                     break;
//                 case EAST:
//                     x += 1;
//                     break;
//                 case SOUTH:
//                     y -= 1;
//                     break;
//                 case WEST:
//                     x -= 1;
//                     break;
//                 }

//                 if (isObstacle(make_tuple(x, y), obstacles))
//                 {
//                     break;
//                 }

//                 start_pos = make_tuple(x, y);

//                 // Update maximum distance squared
//                 int distance_squared = get<0>(start_pos) * get<0>(start_pos) + get<1>(start_pos) * get<1>(start_pos);
//                 max_distance_squared = max(max_distance_squared, distance_squared);
//             }
//         }
//     }

//     return max_distance_squared;
// }

// int main()
// {
//     vector<int> commands = {1,-1,1,-1,1,-1,6};       // Example commands
//     vector<vector<int>> obstacles = {{0, 0}}; // Example obstacles
//     RobotSim_874 robosim;
//     int result = robosim.robotSim(commands, obstacles);
//     cout << "Max distance squared from origin: " << result << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <algorithm> // for std::max, std::binary_search

// using namespace std;

// enum Direction
// {
//     NORTH,
//     EAST,
//     SOUTH,
//     WEST
// };

// class RobotSim_874
// {
// private:
//     bool isObstacle(const tuple<int, int> &position, const vector<vector<int>> &obstacles)
//     {
//         vector<pair<int, int>> obstacle_pairs;
//         for (const auto &obs : obstacles)
//         {
//             obstacle_pairs.emplace_back(obs[0], obs[1]);
//         }

//         sort(obstacle_pairs.begin(), obstacle_pairs.end());

//         return binary_search(obstacle_pairs.begin(), obstacle_pairs.end(), make_pair(get<0>(position), get<1>(position)));
//     }

// public:
//     RobotSim_874() {}
//     ~RobotSim_874() {}
//     int robotSim(vector<int> &commands, vector<vector<int>> &obstacles);
// };

// int RobotSim_874::robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
// {
//     tuple<int, int> start_pos = make_tuple(0, 0);
//     Direction current_direction = NORTH;
//     int max_distance_squared = 0;

//     for (int i = 0; i < commands.size(); i++)
//     {
//         if (commands[i] == -2) // Turn left
//         {
//             current_direction = static_cast<Direction>((current_direction + 3) % 4);
//         }
//         else if (commands[i] == -1) // Turn right
//         {
//             current_direction = static_cast<Direction>((current_direction + 1) % 4);
//         }
//         else // Move forward
//         {
//             for (int step = 0; step < commands[i]; ++step)
//             {
//                 int x = get<0>(start_pos);
//                 int y = get<1>(start_pos);

//                 switch (current_direction)
//                 {
//                 case NORTH:
//                     y += 1;
//                     break;
//                 case EAST:
//                     x += 1;
//                     break;
//                 case SOUTH:
//                     y -= 1;
//                     break;
//                 case WEST:
//                     x -= 1;
//                     break;
//                 }

//                 if (isObstacle(make_tuple(x, y), obstacles))
//                 {
//                     break;
//                 }

//                 start_pos = make_tuple(x, y);

//                 // Update maximum distance squared
//                 int distance_squared = get<0>(start_pos) * get<0>(start_pos) + get<1>(start_pos) * get<1>(start_pos);
//                 max_distance_squared = max(max_distance_squared, distance_squared);
//             }
//         }
//     }

//     return max_distance_squared;
// }

// int main()
// {
//     vector<int> commands = {1, -1, 1, -1, 1, -1, 6}; // Example commands
//     vector<vector<int>> obstacles = {{0, 0}};        // Example obstacles
//     RobotSim_874 robosim;
//     int result = robosim.robotSim(commands, obstacles);
//     cout << "Max distance squared from origin: " << result << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <unordered_set>
// #include <algorithm> // for std::max

// using namespace std;

// enum Direction
// {
//     NORTH,
//     EAST,
//     SOUTH,
//     WEST
// };

// class RobotSim_874
// {
// private:
//     using Position = tuple<int, int>;

//     bool isObstacle(const Position &position, const unordered_set<Position> &obstacle_set)
//     {
//         return obstacle_set.find(position) != obstacle_set.end();
//     }

// public:
//     RobotSim_874() {}
//     ~RobotSim_874() {}
//     int robotSim(vector<int> &commands, vector<vector<int>> &obstacles);
// };

// int RobotSim_874::robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
// {
//     unordered_set<Position> obstacle_set;
//     for (const auto &obs : obstacles)
//     {
//         obstacle_set.emplace(obs[0], obs[1]);
//     }

//     Position start_pos = make_tuple(0, 0);
//     Direction current_direction = NORTH;
//     int max_distance_squared = 0;

//     for (int i = 0; i < commands.size(); i++)
//     {
//         if (commands[i] == -2) // Turn left
//         {
//             current_direction = static_cast<Direction>((current_direction + 3) % 4);
//         }
//         else if (commands[i] == -1) // Turn right
//         {
//             current_direction = static_cast<Direction>((current_direction + 1) % 4);
//         }
//         else // Move forward
//         {
//             for (int step = 0; step < commands[i]; ++step)
//             {
//                 int x = get<0>(start_pos);
//                 int y = get<1>(start_pos);

//                 switch (current_direction)
//                 {
//                 case NORTH:
//                     y += 1;
//                     break;
//                 case EAST:
//                     x += 1;
//                     break;
//                 case SOUTH:
//                     y -= 1;
//                     break;
//                 case WEST:
//                     x -= 1;
//                     break;
//                 }

//                 Position new_pos = make_tuple(x, y);
//                 if (isObstacle(new_pos, obstacle_set))
//                 {
//                     break;
//                 }

//                 start_pos = new_pos;

//                 // Update maximum distance squared
//                 int distance_squared = get<0>(start_pos) * get<0>(start_pos) + get<1>(start_pos) * get<1>(start_pos);
//                 max_distance_squared = max(max_distance_squared, distance_squared);
//             }
//         }
//     }

//     return max_distance_squared;
// }

// int main()
// {
//     vector<int> commands = {1, -1, 1, -1, 1, -1, 6}; // Example commands
//     vector<vector<int>> obstacles = {{0, 0}}; // Example obstacles
//     RobotSim_874 robosim;
//     int result = robosim.robotSim(commands, obstacles);
//     cout << "Max distance squared from origin: " << result << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // for std::max

using namespace std;

enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class RobotSim_874
{
private:
    using Position = tuple<int, int>;

    // Function to check if a position is an obstacle
    bool isObstacle(const Position &position, const vector<Position> &obstacles)
    {
        for (const auto &obstacle : obstacles)
        {
            if (position == obstacle)
            {
                return true;
            }
        }
        return false;
    }

public:
    RobotSim_874() {}
    ~RobotSim_874() {}
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles);
};

int RobotSim_874::robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    // Convert vector of vectors to vector of tuples for obstacles
    vector<Position> obstacle_positions;
    for (const auto &obs : obstacles)
    {
        obstacle_positions.emplace_back(obs[0], obs[1]);
    }

    Position start_pos = make_tuple(0, 0);
    Direction current_direction = NORTH;
    int max_distance_squared = 0;

    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == -2) // Turn left
        {
            current_direction = static_cast<Direction>((current_direction + 3) % 4);
        }
        else if (commands[i] == -1) // Turn right
        {
            current_direction = static_cast<Direction>((current_direction + 1) % 4);
        }
        else // Move forward
        {
            for (int step = 0; step < commands[i]; ++step)
            {
                int x = get<0>(start_pos);
                int y = get<1>(start_pos);

                switch (current_direction)
                {
                case NORTH:
                    y += 1;
                    break;
                case EAST:
                    x += 1;
                    break;
                case SOUTH:
                    y -= 1;
                    break;
                case WEST:
                    x -= 1;
                    break;
                }

                Position new_pos = make_tuple(x, y);
                if (isObstacle(new_pos, obstacle_positions))
                {
                    break;
                }

                start_pos = new_pos;

                // Update maximum distance squared
                int distance_squared = get<0>(start_pos) * get<0>(start_pos) + get<1>(start_pos) * get<1>(start_pos);
                max_distance_squared = max(max_distance_squared, distance_squared);
            }
        }
    }

    return max_distance_squared;
}

int main()
{
    vector<int> commands = {1, -1, 1, -1, 1, -1, 6}; // Example commands
    vector<vector<int>> obstacles = {{0, 0}};        // Example obstacles
    RobotSim_874 robosim;
    int result = robosim.robotSim(commands, obstacles);
    cout << "Max distance squared from origin: " << result << endl;
    return 0;
}
