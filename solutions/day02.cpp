#include <bits/stdc++.h>

using namespace std;

long find_invalids(long start, long end) {
    long invalid = 0;
    for (long i = start; i <= end; ++i) {
        string rep = to_string(i);
        int n = rep.length();
        if (n % 2 != 0)
            continue;
        string left = rep.substr(0, n / 2), right = rep.substr(n / 2);
        if (left == right)
            invalid += i;
    }
    return invalid;
}

int main() {
    ifstream file("../input/day02.txt");
    string input;
    file >> input;
    long invalid = 0;
    while (true) {
        int idx = input.find(",");
        string range = idx == string::npos ? input : input.substr(0, idx);
        int split = range.find("-");
        long start = stol(range.substr(0, split));
        long end = stol(range.substr(split + 1));
        invalid += find_invalids(start, end);
        if (idx == string::npos)
            break;
        input = input.substr(idx + 1);
    }
    printf("Phase 1: %ld\n", invalid);
    return EXIT_SUCCESS;
}
