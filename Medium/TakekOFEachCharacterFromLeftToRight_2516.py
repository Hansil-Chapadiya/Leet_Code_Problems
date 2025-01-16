class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        # Initialize count array to track the frequency of 'a', 'b', and 'c' in the entire string
        total_count = [0, 0, 0]
        n = len(s)

        # Count the occurrences of each character ('a', 'b', and 'c')
        for char in s:
            total_count[ord(char) - ord("a")] += 1

        # Check if there are enough occurrences of each character ('a', 'b', and 'c') to satisfy the requirement
        for count in total_count:
            if count < k:
                return -1

        # Initialize window array to track the characters within the sliding window
        window_count = [0, 0, 0]
        left = 0
        max_valid_window_length = 0

        # Sliding window approach
        for right in range(n):
            # Add the character at 'right' to the window
            window_count[ord(s[right]) - ord("a")] += 1

            # Shrink the window from the left if it contains too many characters
            while left <= right and (
                total_count[0] - window_count[0] < k
                or total_count[1] - window_count[1] < k
                or total_count[2] - window_count[2] < k
            ):
                window_count[ord(s[left]) - ord("a")] -= 1
                left += 1

            # Update the maximum valid window length
            max_valid_window_length = max(max_valid_window_length, right - left + 1)

        # The result is the number of characters to remove to achieve the goal
        return n - max_valid_window_length
