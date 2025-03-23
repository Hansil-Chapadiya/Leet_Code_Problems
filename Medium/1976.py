import heapq

class Solution:
    def countPaths(self, n: int, roads: list[list[int]]) -> int:
        MODULO = 1_000_000_007

        # Graph represented as an adjacency list
        adjacency_list = [[] for _ in range(n)]
        for start, end, time in roads:
            adjacency_list[start].append((end, time))
            adjacency_list[end].append((start, time))

        # Min-Heap (priority queue) for Dijkstra's algorithm
        priority_queue = [(0, 0)]  # (travel_time, node)

        # Store the shortest travel time to each node
        shortest_travel_time = [float("inf")] * n
        # Store the number of ways to reach each node in the shortest travel time
        shortest_path_count = [0] * n

        shortest_travel_time[0] = 0  # Source node distance is 0
        shortest_path_count[0] = 1  # There's one way to reach the source node

        while priority_queue:
            current_travel_time, current_node = heapq.heappop(priority_queue)

            # Skip outdated distances
            if current_travel_time > shortest_travel_time[current_node]:
                continue

            for neighbor, travel_time in adjacency_list[current_node]:
                total_travel_time = current_travel_time + travel_time

                # Found a new shortest path → Update shortest time and reset path count
                if total_travel_time < shortest_travel_time[neighbor]:
                    shortest_travel_time[neighbor] = total_travel_time
                    shortest_path_count[neighbor] = shortest_path_count[current_node]
                    heapq.heappush(priority_queue, (total_travel_time, neighbor))

                # Found another way with the same shortest time → Add to path count
                elif total_travel_time == shortest_travel_time[neighbor]:
                    shortest_path_count[neighbor] = (
                        shortest_path_count[neighbor] + shortest_path_count[current_node]
                    ) % MODULO

        return shortest_path_count[n - 1]
