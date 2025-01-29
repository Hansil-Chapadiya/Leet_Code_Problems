class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))  # Use 1-based indexing for nodes

        def find(i):
            if parent[i] == i:
                return i
            return find(parent[i])

        def union(i, j):
            root_i = find(i)
            root_j = find(j)
            if root_i != root_j:
                parent[root_i] = root_j
                return True  # No cycle formed
            return False  # Cycle formed

        for u, v in edges:
            if not union(u, v):  # If adding this edge creates a cycle
                return [u, v]  # This is the redundant edge