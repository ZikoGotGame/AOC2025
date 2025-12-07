#include <bits/stdc++.h>

using namespace std;

long solve_hw(const vector<vector<int>> &values, const vector<char> &operations) {
    long grand_total = 0;
    for (int i = 0; i < values[0].size(); ++i) {
        long problem = (operations[i] == '*');
        for (int j = 0; j < values.size(); ++j) {
            switch (operations[i]) {
            case '+':
                problem += values[j][i];
                break;
            default:
                problem *= values[j][i];
            }
        }
        grand_total += problem;
    }
    return grand_total;
}

long solve_hw_p2(const vector<string> &values, const vector<char> &operations) {
    long grand_total = 0;
    int idx = operations.size() - 1;
    long problem = (operations[idx] == '*');
    for (int i = values[0].length() - 1; i >= 0; --i) {
        string num = "";
        for (int j = 0; j < values.size(); ++j)
            if (!isspace(values[j][i]))
                num += values[j][i];
        if (num == "") {
            grand_total += problem;
            --idx;
            problem = (operations[idx] == '*');
            continue;
        }
        long val = stol(num);
        switch (operations[idx]) {
        case '+':
            problem += val;
            break;
        default:
            problem *= val;
        }
    }
    grand_total += problem;
    return grand_total;
}

int main() {
    ifstream file("../input/day06.txt");
    vector<vector<int>> values;
    vector<string> values_wspace;
    for (int i = 0; i < 4; ++i) {
        string line;
        vector<int> line_vals;
        getline(file, line);
        values_wspace.push_back(line);
        istringstream stream(line);
        int num;
        while (stream >> num)
            line_vals.push_back(num);
        values.push_back(line_vals);
    }
    vector<char> operations(values[0].size());
    for (char &c : operations)
        file >> c;
    printf("Part 1: %ld\nPart 2: %ld\n", solve_hw(values, operations), solve_hw_p2(values_wspace, operations));
    return EXIT_SUCCESS;
}
