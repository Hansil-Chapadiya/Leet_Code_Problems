from collections import defaultdict

def maximum_beauty(nums, k):
    """
    Returns the maximum possible beauty of the array nums after applying the
    described operation to each element at most once.
    """
    # Dictionary to keep track of the start and end of range changes
    events = defaultdict(int)

    for num in nums:
        events[num - k] += 1  # Start of the range
        events[num + k + 1] -= 1  # End of the range (non-inclusive)

    max_beauty = 0
    active_ranges = 0

    # Sort the events by key (value on the number line)
    for position in sorted(events):
        active_ranges += events[position]  # Update the count of active ranges
        max_beauty = max(max_beauty, active_ranges)  # Track the maximum

    return max_beauty

# Example usage
nums = [4, 6, 1, 3]
k = 2
print(maximum_beauty(nums, k))  # Output the maximum possible beauty
