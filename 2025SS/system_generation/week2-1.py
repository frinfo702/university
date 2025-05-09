# DFS
import matplotlib.pyplot as plt
import numpy as np


def LinkableCheck(checkState):
    state_right = ((checkState[0],checkState[1]+1))
    state_left = ((checkState[0],checkState[1]-1))
    state_up = ((checkState[0]-1,checkState[1]))
    state_down = ((checkState[0]+1,checkState[1]))
    states = [state_right, state_left, state_up, state_down]
    
    for s in states:
        # avoid to check state in closedList
        if not s in closedList:
            # if linked then insert into openList (at the 'first' or 'last' element place)
            if not maze[s]:
                openList.insert(0, s)

maze = np.loadtxt('/Users/gotokenichiro/university/2025SS/system_generation/sample/data/maze_15x15.txt')
maze_new = maze.copy()

start = (1, 1)
height, width = maze.shape
goal = (height-2, width-2)

openList = [start]
closedList = []

while not openList == []: #if openList is not null => loop
    print("openList:", openList)
    state = openList[0]
    openList.pop(0)
    closedList.append(state)
    
    if state == goal:
        print("find goal")
        break
    
    val = input()
    LinkableCheck(state)
    
    
print("closedList:", closedList)

for i in closedList:
    maze_new[i] = .5
    
plt.imshow(maze_new, cmap='binary')
plt.show()
