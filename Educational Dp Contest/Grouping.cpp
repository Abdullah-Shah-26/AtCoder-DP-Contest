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

const int N = 16;

int n;
ll a[N][N];
ll score[1 << N], dp[1 << N];

// TC = O(3 ^ N)
ll f(int mask) {
  if (mask == 0)
    return 0;

  if (dp[mask] != -1)
    return dp[mask];

  ll ans = 0;

  // Sub only uses bits that are in mask i.e
  // Rabbits that are still ungrouped
  for (int sub = mask; sub > 0; sub = (sub - 1) & mask)
    ans = max(ans, score[sub] + f(mask ^ sub));

  return dp[mask] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  for (int mask = 1; mask < (1 << n); mask++)
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if ((mask >> i & 1) && (mask >> j & 1))
          score[mask] += a[i][j];

  memset(dp, -1, sizeof(dp));

  cout << f((1 << n) - 1) << endl;

  return 0;
}