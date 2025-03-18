def longestNiceSubarray(nums):
    left = 0
    bitmask = 0
    max_length = 0

    for right in range(len(nums)):
        while (bitmask & nums[right]) != 0:
            bitmask ^= nums[left]
            left += 1

        bitmask |= nums[right]
        max_length = max(max_length, right - left + 1)

    return max_length

# Example usage:
nums = [1, 3, 8, 48, 10]
print(longestNiceSubarray(nums))  # Output: 3
