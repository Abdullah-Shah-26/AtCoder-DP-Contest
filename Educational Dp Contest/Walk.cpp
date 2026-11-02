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

/*

Brute Force :

TC : O(N * K)

N <= 50
K <= 1e18

int f(int u, int remLen){
  if(remLen == 0)
    return 1;

  int paths = 0;
  for(int v : adj[u]){
    paths += f(v, remLen - 1);
  }

  return paths;
}

ans = 0;
for(int u = 0; u < n; u++){
  ans += f(u, k)
}

*/

vvll multiply(vvll &A, vvll &B) {
  int n = A.size();

  vvll C(n, vll(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

  return C;
}

vvll matExpo(vvll base, ll exp) {
  int n = base.size();

  vvll ans(n, vll(n, 0));

  for (int i = 0; i < n; i++)
    ans[i][i] = 1;

  while (exp) {
    if (exp & 1)
      ans = multiply(ans, base);

    base = multiply(base, base);
    exp >>= 1;
  }

  return ans;
}

int main() {
  ll n, k;
  cin >> n >> k;

  // Adj matrix
  vvll adj(n, vll(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];

  vvll mat = matExpo(adj, k);

  ll ans = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans = (ans + mat[i][j]) % MOD;

  cout << ans << endl;

  return 0;
}