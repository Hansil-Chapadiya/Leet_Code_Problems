def findMaxFish(grid):
    def dfs(r, c):
        # Base cases: Out of bounds or not a water cell
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0:
            return 0
        # Catch fish in the current cell and mark it as visited
        fish = grid[r][c]
        grid[r][c] = 0
        # Explore adjacent cells
        for dr, dc in directions:
            fish += dfs(r + dr, c + dc)
        return fish

    m, n = len(grid), len(grid[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right
    max_fish = 0

    for r in range(m):
        for c in range(n):
            if grid[r][c] > 0:  # Water cell with fish
                max_fish = max(max_fish, dfs(r, c))

    return max_fish
