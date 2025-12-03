#include <bits/stdc++.h>

using namespace std;

long part_2_sum(string bank) {
    long sum = 0;
    long place = 100000000000;
    vector<int> digits(12, -1);
    int prevIndex = -1;
    for (int i = 0; i < 12; ++i) {
        for (int j = prevIndex + 1; j < bank.length() - (11 - i); ++j) {
            int rep = bank[j] - '0';
            if (rep > digits[i]) {
                digits[i] = rep;
                prevIndex = j;
            }
        }
    }
    for (int i = 0; i < 12; ++i) {
        assert(digits[i] != -1);
        assert(place > 0);
        sum += digits[i] * place;
        place /= 10;
    }
    return sum;
}

int main() {
    ifstream file("../input/day03.txt");
    string bank;
    long sum = 0;
    long sum_p2 = 0;
    while (file >> bank) {
        int dig1 = -1;
        int dig1Index = -1;
        for (int i = 0; i < bank.length() - 1; ++i) {
            int rep = bank[i] - '0';
            if (rep > dig1) {
                dig1 = rep;
                dig1Index = i;
            }
        }
        assert(dig1 != -1);
        assert(dig1Index != -1);
        int dig2 = -1;
        for (int i = dig1Index + 1; i < bank.length(); ++i)
            dig2 = max(dig2, bank[i] - '0');
        sum += dig1 * 10 + dig2;
        sum_p2 += part_2_sum(bank);
    }
    printf("Part 1: %ld\nPart 2: %ld", sum, sum_p2);
    return EXIT_SUCCESS;
}
