from collections import deque, defaultdict

def findAllRecipes(recipes, ingredients, supplies):
    # Step 1: Build the graph and in-degree array
    recipe_set = set(recipes)  # Quick lookup for recipes
    in_degree = {recipe: 0 for recipe in recipes}
    graph = defaultdict(list)  # ingredient -> list of recipes it helps create

    for i, recipe in enumerate(recipes):
        for ingredient in ingredients[i]:
            if ingredient in recipe_set:  # If ingredient is itself a recipe
                graph[ingredient].append(recipe)
                in_degree[recipe] += 1
            # If ingredient is in supplies, no action needed

    # Step 2: Initialize queue with recipes that can be made immediately
    queue = deque()
    for recipe in recipes:
        if in_degree[recipe] == 0:  # No missing ingredients
            queue.append(recipe)

    available = set(supplies)  # Convert supplies to a set for quick lookup
    result = []

    # Step 3: Process queue (Topological Sort)
    while queue:
        recipe = queue.popleft()
        if all(ingredient in available for ingredient in ingredients[recipes.index(recipe)]):
            result.append(recipe)
            available.add(recipe)  # Now this recipe is available as an ingredient

            # Reduce in-degree for dependent recipes
            for dependent in graph[recipe]:
                in_degree[dependent] -= 1
                if in_degree[dependent] == 0:
                    queue.append(dependent)

    return result
