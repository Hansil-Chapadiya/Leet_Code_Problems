from collections import defaultdict, deque

def validArrangement(pairs):
    # Step 1: Build the graph and track in-degrees and out-degrees
    graph = defaultdict(list)
    in_degree = defaultdict(int)
    out_degree = defaultdict(int)

    for start, end in pairs:
        graph[start].append(end)
        out_degree[start] += 1
        in_degree[end] += 1

    # Step 2: Find the starting node for the Eulerian path
    start_node = pairs[0][0]  # Default start node
    for node in graph:
        if out_degree[node] - in_degree[node] == 1:
            start_node = node
            break

    # Step 3: Perform DFS to find the Eulerian path
    stack = [start_node]
    path = deque()

    while stack:
        node = stack[-1]
        if graph[node]:
            next_node = graph[node].pop()
            stack.append(next_node)
        else:
            path.appendleft(stack.pop())

    # Step 4: Convert the path into pairs
    result = []
    path = list(path)
    for i in range(len(path) - 1):
        result.append([path[i], path[i + 1]])

    return result

pairs = [[5,1],[4,5],[11,9],[9,4]]