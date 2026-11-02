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

int n;
vll a;

ll dp[3001][3001];

ll f(ll l, ll r) {
  if (l > r)
    return 0;

  if (l == r)
    return a[r];

  if (dp[l][r] != -1)
    return dp[l][r];

  return dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
}

int main() {

  cin >> n;
  a.assign(n, 0);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  memset(dp, -1, sizeof(dp));

  cout << f(0, n - 1) << endl;

  return 0;
}