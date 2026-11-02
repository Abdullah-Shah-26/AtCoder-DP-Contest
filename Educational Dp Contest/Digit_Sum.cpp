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

ll D;
string s;
ll dp[100005][2][101];

ll f(int i, bool tight, ll sum) {
  if (i == s.size())
    return sum == 0;

  if (dp[i][tight][sum] != -1)
    return dp[i][tight][sum];

  int limit = tight ? (s[i] - '0') : 9;
  ll ans = 0;

  for (int d = 0; d <= limit; d++) {
    ll newSum = (sum + d) % D;
    bool newT = tight && (d == limit);

    ans = (ans + f(i + 1, newT, newSum)) % MOD;
  }

  if (!tight)
    dp[i][tight][sum] = ans;

  return ans;
}

int main() {

  cin >> s >> D;

  memset(dp, -1, sizeof(dp));
  cout << ((f(0, true, 0) - 1) + MOD) % MOD << endl;

  return 0;
}