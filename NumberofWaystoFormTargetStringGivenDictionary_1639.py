def numWays(words, target):
    MOD = 10**9 + 7
    m, n = len(words), len(words[0])
    t_len = len(target)

    # Precompute character counts at each column
    char_count = [[0] * 26 for _ in range(n)]
    for word in words:
        for j, char in enumerate(word):
            char_count[j][ord(char) - ord("a")] += 1

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
                char_index = ord(target[i]) - ord("a")
                # Use current column
                count = char_count[j][char_index]
                if count > 0:
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * count) % MOD

    return dp[t_len][n]


# Example Usage
words = ["acca", "bbbb", "caca"]
target = "aba"
print(numWays(words, target))  # Output: 6


"""
def numWays(words, target):
    MOD = 10**9 + 7
    num_words = len(words)
    word_length = len(words[0])
    target_length = len(target)

    # Precompute character counts at each column
    char_frequency = [[0] * 26 for _ in range(word_length)]
    for word in words:
        for column_index, char in enumerate(word):
            char_frequency[column_index][ord(char) - ord('a')] += 1

    # DP table
    dp = [[0] * (word_length + 1) for _ in range(target_length + 1)]
    dp[0][0] = 1  # Base case: 1 way to form an empty target string

    for target_index in range(target_length + 1):
        for column_index in range(word_length):
            if dp[target_index][column_index] == 0:
                continue

            # Skip current column
            dp[target_index][column_index + 1] = (dp[target_index][column_index + 1] + dp[target_index][column_index]) % MOD

            if target_index < target_length:
                target_char = target[target_index]
                char_index = ord(target_char) - ord('a')

                # Use current column
                count = char_frequency[column_index][char_index]
                if count > 0:
                    dp[target_index + 1][column_index + 1] = (
                        dp[target_index + 1][column_index + 1] + dp[target_index][column_index] * count
                    ) % MOD

    return dp[target_length][word_length]

# Example Usage
words = ["acca", "bbbb", "caca"]
target = "aba"
print(numWays(words, target))  # Output: 6

"""
