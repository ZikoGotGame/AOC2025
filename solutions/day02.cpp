#include <bits/stdc++.h>

using namespace std;

bool is_invalid(string rep) {
    int n = rep.length();
    for (int i = 1; i < n; ++i) {
        if (n % i != 0)
            continue;
        string first = rep.substr(0, i);
        bool match = true;
        for (int j = i; j + i <= n; j += i)
            if (first != rep.substr(j, i))
                match = false;
        if (match)
            return true;
    }
    return false;
}

long find_intervals_p2(long start, long end) {
    long invalid = 0;
    for (long i = start; i <= end; ++i) {
        string rep = to_string(i);
        if (is_invalid(rep))
            invalid += i;
    }
    return invalid;
}

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
    long invalid = 0, all_invalids = 0;
    while (true) {
        int idx = input.find(",");
        string range = idx == string::npos ? input : input.substr(0, idx);
        int split = range.find("-");
        long start = stol(range.substr(0, split));
        long end = stol(range.substr(split + 1));
        invalid += find_invalids(start, end);
        all_invalids += find_intervals_p2(start, end);
        if (idx == string::npos)
            break;
        input = input.substr(idx + 1);
    }
    printf("Phase 1: %ld\nPhase 2: %ld\n", invalid, all_invalids);
    return EXIT_SUCCESS;
}
