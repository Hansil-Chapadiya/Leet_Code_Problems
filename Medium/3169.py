def countAvailableDays(days, meetings):
    if not meetings:
        return days  # If there are no meetings, all days are free

    # Step 1: Sort meetings based on start day
    meetings.sort()

    # Step 2: Merge overlapping meetings
    merged = []
    prev_start, prev_end = meetings[0]

    for start, end in meetings[1:]:
        if start <= prev_end + 1:  # Overlapping or consecutive
            prev_end = max(prev_end, end)  # Extend the current merged interval
        else:
            merged.append((prev_start, prev_end))  # Save previous interval
            prev_start, prev_end = start, end  # Start a new interval

    # Add the last merged interval
    merged.append((prev_start, prev_end))

    # Step 3: Calculate free days
    busy_days = sum(end - start + 1 for start, end in merged)
    return days - busy_days

# Example Usage:
print(countAvailableDays(10, [[1, 2], [5, 6], [7, 8]]))  # Output: 5
print(countAvailableDays(5, [[1, 2], [2, 3], [4, 5]]))   # Output: 1
print(countAvailableDays(1000000000, [[1, 100], [200, 300], [250, 400]]))  # Large input case
