from collections import deque

def get_neighbors(state):
    neighbors = []
    x, y = None, None
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                x, y = i, j
                break

    moves = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]

    for nx, ny in moves:
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = [row[:] for row in state]
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            neighbors.append(new_state)

    return neighbors

def dfs(start, goal):
    stack = [start]
    visited = set()

    while stack:
        current = stack.pop()
        current_tuple = tuple(map(tuple, current))

        if current_tuple in visited:
            continue

        visited.add(current_tuple)

        if current == goal:
            return True

        for neighbor in get_neighbors(current):
            neighbor_tuple = tuple(map(tuple, neighbor))
            if neighbor_tuple not in visited:
                stack.append(neighbor)

    return False

goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
start_state = [[1, 2, 3], [4, 0, 6], [7, 5, 8]]
print(dfs(start_state, goal_state))