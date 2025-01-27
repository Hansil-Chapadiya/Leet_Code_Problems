from collections import defaultdict, deque

def checkIfPrerequisite(numCourses, prerequisites, queries):
    # Create a graph from prerequisites
    graph = defaultdict(list)
    for a, b in prerequisites:
        graph[a].append(b)

    # Floyd-Warshall approach to calculate transitive closure
    reachable = [[False] * numCourses for _ in range(numCourses)]
    for i in range(numCourses):
        reachable[i][i] = True  # A course is always reachable from itself

    for a, b in prerequisites:
        reachable[a][b] = True

    for k in range(numCourses):
        for i in range(numCourses):
            for j in range(numCourses):
                if reachable[i][k] and reachable[k][j]:
                    reachable[i][j] = True

    # Answer the queries
    return [reachable[u][v] for u, v in queries]

# Example usage
numCourses = 4
prerequisites = [[0, 1], [1, 2], [2, 3]]
queries = [[0, 1], [1, 3], [3, 0], [2, 3]]
print(checkIfPrerequisite(numCourses, prerequisites, queries))
