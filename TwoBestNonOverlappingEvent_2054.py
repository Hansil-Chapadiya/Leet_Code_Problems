from typing import List
from bisect import bisect_right


def maxTwoEvents(events: List[List[int]]) -> int:
    # Step 1: Sort events by their end times
    events.sort(key=lambda x: x[1])  # Sort by endTime

    # Step 2: Create arrays to store end times and the maximum value up to each point
    n = len(events)
    end_times = [event[1] for event in events]
    max_value_up_to = [0] * n  # Maximum event value up to and including i-th event

    # Fill the max_value_up_to array
    max_value = 0
    for i in range(n):
        max_value = max(max_value, events[i][2])  # Update the max value seen so far
        max_value_up_to[i] = max_value  # Store it in the array

    # Step 3: Compute the maximum sum of at most two non-overlapping events
    max_sum = 0
    for i in range(n):
        # Option 1: Attend only the current event
        max_sum = max(max_sum, events[i][2])

        # Option 2: Attend the current event and one non-overlapping event before it
        start_time_i = events[i][0]  # Start time of current event
        # Use binary search to find the rightmost event that ends before start_time_i
        j = (
            bisect_right(end_times, start_time_i - 1) - 1
        )  # Find index of last event that ends before start_time_i
        if j >= 0:  # If such an event exists
            max_sum = max(max_sum, events[i][2] + max_value_up_to[j])

    return max_sum


# Test case
# events = [[1, 3, 3], [3, 4, 4], [2, 5, 2], [6, 7, 4]]
events = [[1,3,2],[4,5,2],[2,4,3]]
max_sum = maxTwoEvents(events)
print(max_sum)
