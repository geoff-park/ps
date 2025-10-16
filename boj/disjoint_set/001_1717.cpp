#include <bits/stdc++.h>
using namespace std;

struct OptimizedDisjointSet {
  vector<int> parent, rank;
  OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if (rank[u] == rank[v]) ++rank[v];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  OptimizedDisjointSet ods(n + 1);

  for (int query = 0; query < m; ++query) {
    int q, a, b;
    cin >> q >> a >> b;

    if (q == 0) {
      ods.merge(a, b);
    }

    if (q == 1) {
      if (ods.find(a) == ods.find(b)) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
}
