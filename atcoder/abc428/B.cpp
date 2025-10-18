#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // input
  int n, k;
  string s;
  cin >> n >> k >> s;

  // make a dictionary: memo[t] := #appearance of t
  map<string, int> memo;
  for (int i = 0; i + k - 1 < n; ++i) {
    string t = s.substr(i, k);
    memo[t]++;
  }

  // find max appearance
  int vmax = 0;
  for (auto& kv : memo) {
    vmax = max(vmax, kv.second);
  }

  // list all t with max appearance (for-map lists all keys in lexicographical order)
  vector<string> vs;
  for (auto& kv : memo) {
    if (kv.second == vmax) vs.push_back(kv.first);
  }

  // output
  cout << vmax << '\n';
  for (string& str : vs) cout << str << ' ';
  cout << '\n';
}
