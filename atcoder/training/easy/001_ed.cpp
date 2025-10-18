#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  int ans = 0;
  int outlet = 1;
  while (outlet < b) {
    --outlet;
    outlet += a;
    ++ans;
  }
  cout << ans << '\n';
}
