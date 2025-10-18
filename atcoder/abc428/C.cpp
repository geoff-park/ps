#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  vector<int> A = {0};
  vector<int> B = {0};

  for (int query = 0; query < q; ++query) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      char c;
      cin >> c;
      A.push_back(A.back() + (c == '(' ? 1 : -1));
      B.push_back(min(B.back(), A.back()));
    } else if (cmd == 2) {
      A.pop_back();
      B.pop_back();
    }
    cout << (A.back() == 0 and B.back() == 0 ? "Yes" : "No") << '\n';
  }
}
