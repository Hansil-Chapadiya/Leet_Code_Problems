def numWays(words, target):
    MOD = 10**9 + 7
    m, n = len(words), len(words[0])
    t_len = len(target)

    # Precompute character counts at each column
    char_count = [[0] * 26 for _ in range(n)]
    for word in words:
        for j, char in enumerate(word):
            char_count[j][ord(char) - ord('a')] += 1

    # DP table
    dp = [[0] * (n + 1) for _ in range(t_len + 1)]
    dp[0][0] = 1

    for i in range(t_len + 1):
        for j in range(n):
            if dp[i][j] == 0:
                continue
            # Skip current column
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD
            if i < t_len:
                char_index = ord(target[i]) - ord('a')
                # Use current column
                count = char_count[j][char_index]
                if count > 0:
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * count) % MOD

    return dp[t_len][n]

# Example Usage
words = ["acca","bbbb","caca"]
target = "aba"
print(numWays(words, target))  # Output: 6
