from queue import PriorityQueue
from typing import List

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        row_count, col_count = len(grid), len(grid[0])
        result = [0] * len(queries)
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Right, Down, Left, Up

        # Sort queries along with their indices to restore order later
        sorted_queries = sorted([(value, index) for index, value in enumerate(queries)])

        # Min-heap (priority queue) to process cells in increasing order of value
        min_heap = PriorityQueue()
        visited = [[False] * col_count for _ in range(row_count)]
        accessible_cells = 0  # Keeps track of the number of accessible cells

        # Start from the top-left cell
        min_heap.put((grid[0][0], 0, 0))
        visited[0][0] = True

        # Process queries in sorted order
        for threshold, query_index in sorted_queries:
            # Expand cells that are smaller than the current query value
            while not min_heap.empty() and min_heap.queue[0][0] < threshold:
                cell_value, row, col = min_heap.get()
                accessible_cells += 1  # Increment count of accessible cells

                for row_offset, col_offset in DIRECTIONS:
                    new_row, new_col = row + row_offset, col + col_offset

                    if (
                        0 <= new_row < row_count
                        and 0 <= new_col < col_count
                        and not visited[new_row][new_col]
                    ):
                        min_heap.put((grid[new_row][new_col], new_row, new_col))
                        visited[new_row][new_col] = True  # Mark as visited

            result[query_index] = accessible_cells  # Store result for this query

        return result
