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

int main() {

  int n;
  ll mod;
  cin >> n >> mod;

  vvi adj(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vi parent(n, -1);
  vvi children(n);
  vi order = {0};

  // BFS order 
  // So that parent appears before children
  for (int i = 0; i < n; i++) {
    int u = order[i];

    for (int v : adj[u]) {
      if (v == parent[u])
        continue;

      parent[v] = u;
      children[u].push_back(v);
      order.push_back(v);
    }
  }

  // down[u] = cnt of connected subets that can contain u, using only its
  // subtrees
  // Initially down[u] = 1 cause we are creating product 
  vll down(n, 1), up(n, 0), ans(n);

  // Bottom up DFS
  for (int i = n - 1; i >= 0; i--) {
    int u = order[i];

    for (int v : children[u]) {

      // Dont select v or its subtree
      // Select v & valid connected subsets below it
      down[u] = (down[u] * (1 + down[v])) % mod;
    }
  }

  // Top down DFS
  for (int u : order) {
    int k = children[u].size();

    // Pref product
    // To get contribution of left siblings in O(1)
    vll pref(k + 1, 1);

    for (int i = 0; i < k; i++) {
      int v = children[u][i];
      pref[i + 1] = (pref[i] * (1 + down[v])) % mod;
    }

    ll suff = 1;

    for (int i = k - 1; i >= 0; i--) {
      int v = children[u][i];

      // From parent side of v i.e u
      // Select nothing
      // Select a connected subset containing u

      // From sibling side
      // Ex : 
      // u -> parent  
      // a, b, c -> children
      // v = b

      // Siblings : a, c
      
      // Select nothing from subtree of a
      // Select a connected subset containing a
      
      // Select nothing from subtree of c
      // Select a connected subset containing c
      
      up[v] = (1 + up[u]) * pref[i] % mod * suff % mod;

      suff = suff * (1 + down[v]) % mod;
    }

    ans[u] = down[u] * (1 + up[u]) % mod;
  }

  for (ll x : ans)
    cout << x << endl;

  return 0;
}