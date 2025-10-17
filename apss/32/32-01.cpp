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
    // find argumenting path using bfs
  }

  // if there is no argumenting path, break

  // decide flow

  // flow

  return totalFlow;
}
