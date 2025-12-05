#include <bits/stdc++.h>

using namespace std;

long count_unique(vector<pair<long, long>> &ranges) {
    long count = 0;
    sort(ranges.begin(), ranges.end());
    long currS = ranges[0].first;
    long currE = ranges[0].second;
    for (int i = 1; i < ranges.size(); ++i) {
        pair<long, long> p = ranges[i];
        if (p.first <= currE)
            currE = max(currE, p.second);
        else {
            count += currE - currS + 1;
            currS = p.first;
            currE = p.second;
        }
    }
    count += currE - currS + 1; // This part was killing me XD
    return count;
}

int main() {
    ifstream file("../input/day05.txt");
    string line;
    long freshIngred = 0;
    int split = 0;
    vector<pair<long, long>> ranges;
    while (getline(file, line) && (split = line.find("-")) != string::npos) {
        long start = stol(line.substr(0, split));
        long end = stol(line.substr(split + 1));
        ranges.push_back(make_pair(start, end));
    }
    while (file >> line) {
        long id = stol(line);
        for (const auto &p : ranges) {
            if (p.first <= id && id <= p.second) {
                ++freshIngred;
                break;
            }
        }
    }
    printf("Part 1: %ld\nPart 2: %ld\n", freshIngred, count_unique(ranges));
    return EXIT_SUCCESS;
}
