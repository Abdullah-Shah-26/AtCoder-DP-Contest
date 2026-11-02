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

total = no of candies available to distribute
      = [0, k]

ndp[total] += dp[total - 0]
ndp[total] += dp[total - 1]
ndp[total] += dp[total - 2]
.
.
ndp[total] += dp[total - a[i]]

L = max(0, total - a[i])
R = total

Valid range: [L, R]

Prefix sum over [L, R]:

pref[R + 1] - pref[L]
*/

int main() {
  int n, k;
  cin >> n >> k;

  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vll dp(k + 1, 0);
  vll ndp(k + 1, 0);
  vll pref(k + 2, 0);

  // No of ways to distribute 0 candies among 0 children = 1
  dp[0] = 1;

  for (int i = 0; i < n; i++) {

    // Building pref sum (1 based) of prev dp row
    pref[0] = 0;

    for (int j = 0; j <= k; j++)
      pref[j + 1] = (pref[j] + dp[j]) % MOD;

    for (int j = 0; j <= k; j++) {
      int L = max(0LL, j - a[i]);

      ndp[j] = (pref[j + 1] - pref[L] + MOD) % MOD;
    }

    swap(dp, ndp);
  }

  cout << dp[k] << endl;

  return 0;
}