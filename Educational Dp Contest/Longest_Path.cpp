#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// DP on DAG :

int main()
{
  fastio();

  int n, m;
  cin >> n >> m;

  vector<int> adj[n + 1];
  vector<int> indeg(n + 1, 0);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    indeg[v]++;
  }

  // Topo Sort + Dp
  queue<int> q;
  vector<int> dp(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    if (indeg[i] == 0)
    {
      q.push(i);
    }
  }

  int processed = 0;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    processed++;

    for (int v : adj[u])
    {

      dp[v] = max(dp[v], 1 + dp[u]);
      indeg[v]--;

      if (indeg[v] == 0)
      {
        q.push(v);
      }
    }
  }

  if(processed != n){
    cout << "Graph has Cycle" << endl;
    return 0;
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;

  return 0;
}