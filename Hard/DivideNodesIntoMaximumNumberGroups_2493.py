from collections import deque


class Solution:
    def magnificentSets(self, num_nodes, edges):
        # Helper function to check if the component is bipartite and collect nodes
        def check_bipartite(node, color_code, current_component):
            node_colors[node] = color_code
            current_component.append(node)
            for neighbor in adjacency_list[node]:
                if node_colors[neighbor] == color_code:
                    return False  # Odd cycle detected
                if node_colors[neighbor] == -1 and not check_bipartite(
                    neighbor, 1 - color_code, current_component
                ):
                    return False
            return True

        # Helper function to compute max distance (groups) for a component
        def calculate_groups_in_component(component):
            max_distance = 0
            for start_node in component:
                distances = [-1] * num_nodes
                queue = deque([start_node])
                distances[start_node] = 0
                while queue:
                    node = queue.popleft()
                    for neighbor in adjacency_list[node]:
                        if distances[neighbor] == -1:
                            distances[neighbor] = distances[node] + 1
                            max_distance = max(max_distance, distances[neighbor])
                            queue.append(neighbor)
            return max_distance + 1  # Convert depth to group count

        # Initialize adjacency list and color array
        adjacency_list = [[] for _ in range(num_nodes)]
        for u, v in edges:
            adjacency_list[u - 1].append(v - 1)
            adjacency_list[v - 1].append(u - 1)

        node_colors = [-1] * num_nodes  # To track node colors (0/1)
        components = []

        # Check bipartiteness and collect components
        for i in range(num_nodes):
            if node_colors[i] == -1:
                component = []
                if not check_bipartite(i, 0, component):
                    return -1  # Non-bipartite component
                components.append(component)

        # Calculate total groups
        total_groups = 0
        for component in components:
            total_groups += calculate_groups_in_component(component)

        return total_groups
