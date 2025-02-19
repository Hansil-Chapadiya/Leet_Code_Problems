def getHappyString(n: int, k: int) -> str:
    happy_strings = []

    def backtrack(current):
        if len(current) == n:
            happy_strings.append(current)
            return
        for char in 'abc':
            if not current or current[-1] != char:
                backtrack(current + char)

    backtrack("")

    return happy_strings[k - 1] if k <= len(happy_strings) else ""

# Example usage
print(getHappyString(3, 9))  # Output: "cab"
