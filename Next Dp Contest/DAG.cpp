#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 998244353;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

void solve() {
  ll n, m;
  cin >> n >> m;

  vvll adj(n + 1);
  vll indeg(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    indeg[v]++;
    adj[u].push_back(v);
  }

  // ways[u] = no of ways to reach vertex u
  vll ways(n + 1, 0);
  ways[1] = 1;

  queue<int> q;

  for (int i = 1; i <= n; i++)
    if (indeg[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      ways[v] = (ways[u] + ways[v]) % MOD;

      if (--indeg[v] == 0)
        q.push(v);
    }
  }

  cout << ways[n] << endl;
}

int main() {

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}