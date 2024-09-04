#include <bits/stdc++.h>

using namespace std;

vector<int> parent, rank_;

void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
void kruskal() {
    parent.resize(n);
    rank_.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

}
int main() {

    return 0;
}