#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const ll INF = LLONG_MAX;

int n;
vll a, pref;

ll dp[400][400];

ll f(int l, int r) {
  if (l == r)
    return 0;

  if (dp[l][r] != -1)
    return dp[l][r];

  ll ans = INF;

  // Trying all possible splits
  // k = boundary b/w 2 groups
  for (int k = l; k < r; k++) {
    ans = min(ans, f(l, k) + f(k + 1, r) + pref[r + 1] - pref[l]);
  }

  return dp[l][r] = ans;
}

int main() {
  cin >> n;

  a.assign(n, 0);
  pref.assign(n + 1, 0);

  for (ll &x : a)
    cin >> x;

  for (int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + a[i - 1];

  memset(dp, -1, sizeof(dp));

  cout << f(0, n - 1) << endl;
}