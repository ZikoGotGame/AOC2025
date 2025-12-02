#include <bits/stdc++.h>

using namespace std;

int floor(int a, int b) {
    if (a >= 0)
        return a / b;
    return -((-a + b - 1) / b);
}

int get_passes(int dial, int mag) {
    int sum = dial + mag;
    if (mag > 0)
        return floor(sum, 100) - floor(dial, 100);
    else if (mag < 0)
        return floor(dial - 1, 100) - floor(sum - 1, 100);
    return 0;
}

int main() {
    ifstream file("../input/day01.txt");
    int dial = 50;
    int zeroCount = 0;
    int passZeroCount = 0;
    string line;
    while (file >> line) {
        int mag = (line[0] == 'R' ? 1 : -1) * stoi(line.substr(1));
        passZeroCount += get_passes(dial, mag);
        dial = (mag + dial) % 100;
        zeroCount += (dial == 0);
    }
    cout << "Phase 1 ans: " << zeroCount << "\n";
    cout << "Phase 2 ans: " << passZeroCount << "\n";
    return EXIT_SUCCESS;
}
