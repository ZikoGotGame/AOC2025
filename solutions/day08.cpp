#include <bits/stdc++.h>

using namespace std;

struct Junc {
    long x, y, z;
    int id;
    Junc(long a, long b, long c, int s) : x(a), y(b), z(c), id(s) {}
};

Junc find(Junc junc, const vector<Junc> &juncs, const vector<int> &par) {
    while (par[junc.id] != junc.id)
        junc = juncs[par[junc.id]];
    return junc;
}

bool union_f(const Junc &a, const Junc &b, const vector<Junc> &juncs, vector<int> &par, vector<int> &rank) {
    Junc par_a = find(a, juncs, par);
    Junc par_b = find(b, juncs, par);
    if (par_a.id == par_b.id)
        return false;
    if (rank[par_a.id] >= rank[par_b.id]) {
        rank[par_a.id] += rank[par_b.id];
        par[par_b.id] = par_a.id;
    } else {
        rank[par_b.id] += rank[par_a.id];
        par[par_a.id] = par_b.id;
    }
    return true;
}

long jun_dist(const Junc &a, const Junc &b) {
    long x = b.x - a.x;
    long y = b.y - a.y;
    long z = b.z - a.z;
    return x * x + y * y + z * z;
}

int main() {
    ifstream file("../input/day08.txt");
    string line;
    vector<Junc> juncs;
    vector<int> par, rank;
    int id = 0;
    while (file >> line) {
        int x, y, z;
        sscanf(line.c_str(), "%d,%d,%d", &x, &y, &z);
        juncs.emplace_back(x, y, z, id);
        par.push_back(id);
        rank.push_back(1);
        ++id;
    }
    auto cmp = [](const auto &a, const auto &b) { return jun_dist(a.first, a.second) > jun_dist(b.first, b.second); };
    priority_queue<pair<Junc, Junc>, vector<pair<Junc, Junc>>, decltype(cmp)> minHeap(cmp);
    for (int i = 0; i < juncs.size(); ++i) {
        for (int j = i + 1; j < juncs.size(); ++j) {
            minHeap.push(make_pair(juncs[i], juncs[j]));
        }
    }
    int joins = 0;
    long res_p1, square;
    while (!minHeap.empty()) {
        auto p = minHeap.top();
        minHeap.pop();
        bool res = union_f(p.first, p.second, juncs, par, rank);
        ++joins;
        if (joins == 1000) {
            sort(rank.begin(), rank.end());
            int n = rank.size();
            res_p1 = rank[n - 1] * rank[n - 2] * rank[n - 3];
        }
        if (res)
            square = p.first.x * p.second.x;
    }
    printf("Part 1: %ld\nPart 2: %ld\n", res_p1, square);
    return EXIT_SUCCESS;
}
