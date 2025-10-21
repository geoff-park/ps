#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<vector<int>> SCC;

// start: code for scc
vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here) {
  int ret = discovered[here] = vertexCounter++;
  st.push(here);

  for (int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    if (discovered[there] == -1)
      ret = min(ret, scc(there));
    else if (sccId[there] == -1)
      ret = min(ret, discovered[there]);
  }

  if (ret == discovered[here]) {
    vector<int> temp;

    while (true) {
      int t = st.top();
      st.pop();
      sccId[t] = sccCounter;
      temp.push_back(t);
      if (t == here) break;
    }
    ++sccCounter;

    // add to 'SCC'
    sort(temp.begin(), temp.end());
    SCC.push_back(temp);
  }

  return ret;
}

vector<int> tarjanSCC() {
  sccId = discovered = vector<int>(adj.size(), -1);
  sccCounter = vertexCounter = 0;
  for (int i = 0; i < adj.size(); ++i)
    if (discovered[i] == -1) scc(i);
  return sccId;
}
// end: code for scc

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // input
  cin >> v >> e;
  adj.resize(v);  // 0-based index
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
  }

  tarjanSCC();

  // sort 'SCC'
  sort(SCC.begin(), SCC.end(), [](vector<int> scc1, vector<int> scc2) {
    return scc1[0] < scc2[0];
  });

  // output
  cout << SCC.size() << '\n';
  for (vector<int> scc : SCC) {
    for (int i : scc) cout << ++i << ' ';
    cout << -1 << '\n';
  }
}
