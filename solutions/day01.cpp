#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("../input/day01.txt");
    int dial = 50;
    int passDial = 50;
    int zeroCount = 0;
    int passZeroCount = 0;
    string line;
    while (file >> line) {
        char dir = line[0];
        int mag = stoi(line.substr(1));
        dial = (dial + (dir == 'R' ? mag : -mag)) % 100;
        zeroCount += (dial == 0);
        while (mag > 0) {
            passDial += dir == 'R' ? 1 : -1;
            if (passDial == 0 || passDial % 100 == 0)
                ++passZeroCount;
            --mag;
        }
    }
    cout << "Phase 1 ans: " << zeroCount << "\n";
    cout << "Phase 2 ans: " << passZeroCount << "\n";
    return 0;
}
