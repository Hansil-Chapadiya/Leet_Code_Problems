from typing import List
from collections import defaultdict


class MostProfitablePathinTree:
    def mostProfitablePath(
        self, edges: List[List[int]], bob: int, amount: List[int]
    ) -> int:
        # Step 1: Build the tree as an adjacency list
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Step 2: Find Bob's path to node 0
        bobPath = [-1] * len(amount)  # Stores when Bob reaches each node
        path = []  # Temporary path tracker

        def fillBobPath(node, parent):
            if node == 0:
                return True  # Found the root
            for neighbor in graph[node]:
                if neighbor != parent:
                    path.append(node)
                    if fillBobPath(neighbor, node):
                        return True
                    path.pop()
            return False

        fillBobPath(bob, -1)
        for i, node in enumerate(path):
            bobPath[node] = i  # Store timestamp when Bob reaches each node

        # Step 3: DFS for Alice to maximize profit
        def getAliceMaxScore(node, parent, currScore, timestamp):
            # Adjust Alice's earnings based on Bob's arrival time
            if bobPath[node] == -1 or bobPath[node] > timestamp:
                currScore += amount[node]  # Alice gets full value
            elif bobPath[node] == timestamp:
                currScore += amount[node] // 2  # Alice and Bob split

            # If leaf node (except root), return current score
            if len(graph[node]) == 1 and node != 0:
                return currScore

            # Recurse for child nodes
            return max(
                getAliceMaxScore(neighbor, node, currScore, timestamp + 1)
                for neighbor in graph[node]
                if neighbor != parent
            )

        return getAliceMaxScore(0, -1, 0, 0)  # Start DFS from node 0


# Example Test Case
obj = MostProfitablePathinTree()
print(
    obj.mostProfitablePath([[0, 1], [1, 2], [1, 3], [3, 4]], 3, [-2, 4, 2, -4, 6])
)  # Expected Output: 6
