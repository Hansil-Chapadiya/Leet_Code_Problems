from typing import List
import heapq


class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # If both initial moves require more than 1 second, it's impossible to proceed
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        rows, cols = len(grid), len(grid[0])
        # Possible movements: down, up, right, left
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = set()

        # Priority queue stores (time_taken, current_row, current_col)
        # Ordered by minimum time to reach each cell
        min_heap = [(grid[0][0], 0, 0)]  # Start at the top-left corner

        while min_heap:
            time_taken, curr_row, curr_col = heapq.heappop(min_heap)

            # Check if we reached the bottom-right corner
            if (curr_row, curr_col) == (rows - 1, cols - 1):
                return time_taken

            # Skip if the cell has already been visited
            if (curr_row, curr_col) in visited:
                continue
            visited.add((curr_row, curr_col))

            # Explore all possible directions
            for dx, dy in directions:
                next_row, next_col = curr_row + dx, curr_col + dy

                if not self.is_valid_cell(visited, next_row, next_col, rows, cols):
                    continue

                # Calculate the wait time needed to move to the next cell
                wait_time = 1 if (grid[next_row][next_col] - time_taken) % 2 == 0 else 0
                next_time = max(grid[next_row][next_col] + wait_time, time_taken + 1)
                heapq.heappush(min_heap, (next_time, next_row, next_col))

        return -1

    # Checks if the given cell coordinates are valid and unvisited
    def is_valid_cell(self, visited, row, col, rows, cols):
        return 0 <= row < rows and 0 <= col < cols and (row, col) not in visited


grid = [
    [0, 2, 3],
    [1, 2, 4],
    [2, 3, 5]
]
solution = Solution()
print(solution.minimumTime(grid))
