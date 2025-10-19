#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // input
  int n;
  cin >> n;
  vector<int> X(n);
  for (int i = 0; i < n; ++i) cin >> X[i];

  // brute-force
  int ans = 1000000000;
  for (int p = 1; p <= 100; p++) {
    int cost = 0;
    for (int x : X) cost += (x - p) * (x - p);
    ans = min(ans, cost);
  }

  // output
  cout << ans << '\n';
}
