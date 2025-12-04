#include <bits/stdc++.h>

using namespace std;

const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int remove_rolls(vector<string> &grid) {
    int rolls = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '.')
                continue;
            int adj = 0;
            for (const auto &d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (0 <= ni && ni < rows && 0 <= nj && nj < cols && grid[ni][nj] == '@')
                    ++adj;
            }
            if (adj < 4) {
                ++rolls;
                grid[i][j] = '.';
            }
        }
    }
    return rolls;
}

int count_accessable_rolls(const vector<string> &grid) {
    int rolls = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '.')
                continue;
            int adj = 0;
            for (const auto &d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (0 <= ni && ni < rows && 0 <= nj && nj < cols && grid[ni][nj] == '@')
                    ++adj;
            }
            if (adj < 4)
                ++rolls;
        }
    }
    return rolls;
}

int main() {
    ifstream file("../input/day04.txt");
    vector<string> grid;
    string line;
    while (file >> line)
        grid.push_back(line);
    int accessable_rolls = count_accessable_rolls(grid);
    int removed = 0;
    for (int i = remove_rolls(grid); i != 0; i = remove_rolls(grid))
        removed += i;
    printf("Part 1: %d\nPart 2: %d\n", accessable_rolls, removed);
    return EXIT_SUCCESS;
}
