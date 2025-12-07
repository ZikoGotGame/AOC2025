#include <bits/stdc++.h>

using namespace std;

vector<vector<long>> dp;

int count_splits(vector<string> &grid, int row, int col) {
    int splits = 0;
    for (int i = row; i < grid.size(); ++i) {
        switch (grid[i][col]) {
        case 'S':
        case '.':
            grid[i][col] = '|';
            break;
        case '^':
            ++splits;
            splits += count_splits(grid, i, col + 1);
            splits += count_splits(grid, i, col - 1);
            return splits;
        default:
            return splits;
        }
    }
    return splits;
}

long count_timelines(const vector<string> &grid, int row, int col, long timelines) {
    if (dp[row][col] != -1)
        return dp[row][col];
    unordered_set<int> indexes;
    for (int i = row; i < grid.size(); ++i) {
        indexes.insert(i);
        if (grid[i][col] == '^') {
            ++timelines;
            timelines += count_timelines(grid, i, col + 1, 0);
            timelines += count_timelines(grid, i, col - 1, 0);
            for (int j : indexes)
                dp[j][col] = timelines;
            return timelines;
        }
    }
    return timelines;
}

int main() {
    ifstream file("../input/day07.txt");
    string line;
    vector<string> grid;
    while (getline(file, line))
        grid.push_back(line);
    dp.resize(grid.size(), vector<long>(grid[0].length(), -1));
    int start = grid[0].find("S");
    long timelines = count_timelines(grid, 0, start, 1);
    printf("Part 1: %d\nPart 2: %ld\n", count_splits(grid, 0, start), timelines);
    return EXIT_SUCCESS;
}
