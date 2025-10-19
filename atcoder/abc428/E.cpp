#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> dist;

// find farthest vertex from start (BFS)
int find_farthest(int start) {
  dist.assign(n + 1, -1);
  queue<int> q;

  dist[start] = 0;
  q.push(start);

  int far = start;  // far := farthest vertex
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    for (int there : g[here]) {
      if (dist[there] == -1) {  // not visited
        dist[there] = dist[here] + 1;
        q.push(there);
        // update farthest vertex
        if (dist[there] > dist[far]) far = there;
        if (dist[there] == dist[far] && there > far) far = there;  // compare vertex number
      }
    }
  }
  return far;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  g.assign(n + 1, {});  // 1-based index
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // s and t are the endpoints of the tree's diameter
  int s = find_farthest(1);
  int t = find_farthest(s);

  vector<int> dist_from_s = dist;
  find_farthest(t);
  vector<int> dist_from_t = dist;

  // output
  for (int u = 1; u <= n; ++u) {
    if (dist_from_s[u] > dist_from_t[u])
      cout << s << '\n';
    else if (dist_from_s[u] < dist_from_t[u])
      cout << t << '\n';
    else
      cout << max(s, t) << '\n';
  }
}
