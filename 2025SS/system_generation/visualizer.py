import matplotlib.pyplot as plt
import numpy as np


def plot_maze(maze: np.ndarray, save_file=None):
    height, width = maze.shape
    plt.imshow(maze, cmap="binary")
    plt.gca().set_aspect("equal")
    plt.xticks(rotation=90)
    plt.xticks(np.arange(width), np.arange(width))
    plt.yticks(np.arange(height), np.arange(height))
    if save_file is not None:
        plt.savefig(save_file)
    plt.show()
