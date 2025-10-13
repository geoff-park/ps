#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[i].first = --u;
    edges[i].second = --v;
  }
  int ans = m;
  for (int bit = 0; bit < 1 << n; bit++) {
    int delete_count = 0;
    for (auto e : edges) {
      int u = e.first;
      int v = e.second;
      if ((1 & (bit >> u)) == (1 & (bit >> v))) delete_count++;
    }
    ans = min(ans, delete_count);
  }
  cout << ans << '\n';
}
