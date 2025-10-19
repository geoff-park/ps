#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// floor(sqrt(x))
ll f(ll x) {
  ll y = sqrt(x);
  // adjustment for floating-point error
  while (y * y > x) --y;
  while ((y + 1) * (y + 1) <= x) ++y;
  return y;
}

ll solve(ll c, ll d) {
  ll ans = 0;

  ll xmin = 1, xmax = 9, cshift = 10;
  while (xmin <= c + d) {
    ll l = max(xmin, c + 1);
    ll r = min(xmax, c + d);

    if (l <= r) {
      ll vl = c * cshift + l;
      ll vr = c * cshift + r;
      ans += f(vr) - f(vl - 1);
    }

    // update
    xmin = xmin * 10;
    xmax = (xmax + 1) * 10 - 1;
    cshift *= 10;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    ll c, d;
    cin >> c >> d;
    cout << solve(c, d) << '\n';
  }
}
