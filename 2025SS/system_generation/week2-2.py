# BFS
import matplotlib.pyplot as plt
import numpy as np


def LinkableCheck(checkState):
    state_right = ((checkState[0],checkState[1]+1))
    state_left = ((checkState[0],checkState[1]-1))
    state_up = ((checkState[0]-1,checkState[1]))
    state_down = ((checkState[0]+1,checkState[1]))
    states = [state_right, state_left, state_up, state_down]
    
    for s in states:
        # closedListの探索は避ける
        if s not in closedList:
            # もし繋がっていたらopenList(キュー)に追加
            if not maze[s]:
                openList.append(s)

maze = np.loadtxt('/Users/gotokenichiro/university/2025SS/system_generation/sample/data/maze_15x15.txt')
maze_new = maze.copy()

start = (1, 1)
height, width = maze.shape
goal = (height-2, width-2)

openList = [start]  # キューとして使用
closedList = [] # 探索済みリスト

while not openList == []: 
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
