#include <bits/stdc++.h>

using namespace std;

int passes(int start, int end) { return abs((end / 100) - (start / 100)); }

int main() {
    ifstream file("../input/day01.txt");
    int dial = 50;
    int passDial = 50;
    int zeroCount = 0;
    int passZeroCount = 0;
    string line;
    while (file >> line) {
        char dir = line[0];
        int mag = (dir == 'R' ? 1 : -1) * stoi(line.substr(1));
        passZeroCount += passes(passDial, passDial + mag);
        passDial += mag;
        dial = (mag + dial) % 100;
        zeroCount += (dial == 0);
    }
    cout << "Phase 1 ans: " << zeroCount << "\n";
    cout << "Phase 2 ans: " << passZeroCount - 1 << "\n";
    return 0;
}
