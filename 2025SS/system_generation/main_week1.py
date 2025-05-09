import os

import numpy as np

from maze_handler import make_reversed_maze
from visualizer import plot_maze

if __name__ == "__main__":
    file = "maze_data/sample_maze.txt"
    save_directory = "output_mazes"

    if input("この迷路を保存しますか? (y/n) >> ") == "y":
        os.makedirs(save_directory, exist_ok=True)

        base_filename = os.path.basename(file)  # sample.txt
        base_name = os.path.splitext(base_filename)[0]  # sample
        name = f"reversed_{base_name}"
        maze = np.loadtxt(file)
        reversed_maze = make_reversed_maze(maze)

        # 保存パスを作成
        txt_save_path = os.path.join(save_directory, f"{name}.txt")
        png_save_path = os.path.join(save_directory, f"{name}.png")

        np.savetxt(txt_save_path, reversed_maze, fmt="%d")
        plot_maze(
            reversed_maze, save_file=png_save_path
        )  # Save plot with .png extension
        print(f"作成した迷路を{png_save_path}と{txt_save_path}に保存しました")
    print()
