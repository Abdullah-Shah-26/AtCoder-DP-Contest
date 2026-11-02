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
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

const int N = 1e5 + 5;

int n;
ll dp[N][2];
vi adj[N];

// 0 = Black
// 1 = White

// No 2 adjacent nodes can be black
// But 2 adj nodes can be white

ll dfs(int u, int p, int col) {

  ll &ans = dp[u][col];

  if (ans != -1)
    return ans;

  ans = 1;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    // If parent is black
    // Children has no option but to be white
    if (col == 0) {
      ans = (ans * dfs(v, u, !col)) % MOD;
    }

    // If parent is white
    // Each child has an option to be B or W
    else {
      ans = (ans * (dfs(v, u, !col) + dfs(v, u, col)) % MOD) % MOD;
    }
  }

  return ans;
}

int main() {

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(dp, -1, sizeof(dp));

  // Start with root as black or white
  ll ans = (dfs(1, -1, 0) + dfs(1, -1, 1)) % MOD;

  cout << ans << endl;

  return 0;
}