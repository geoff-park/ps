#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int networkFlow(int source, int sink) {
  // init flow to 0
  memset(flow, 0, sizeof(flow));
  int totalFlow = 0;

  while (true) {
    // find augmenting path using bfs
    vector<int> parent(MAX_V, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);
    while (!q.empty() && parent[sink] == -1) {
      int here = q.front();
      q.pop();
      for (int there = 0; there < V; ++there) {
        if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
          q.push(there);
          parent[there] = here;
        }
      }
    }

    // if there is no augmenting path, break
    if (parent[sink] == -1) break;

    // decide flow
    int amount = INF;
    for (int p = sink; p != source; p = parent[p]) {
      amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    }

    // flow
    for (int p = sink; p != source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    totalFlow += amount;
  }

  return totalFlow;
}
