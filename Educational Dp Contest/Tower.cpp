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

(W + S) = blocks own wt + capacity it can carry
blocks can be sorted in asc order based on this value

*/

const int N = 1001;
const int W = 20001;

int n;
vector<tuple<ll, ll, ll>> vec;
ll dp[N][W];

ll f(int i, ll totalW) {
  if (i == n)
    return 0;

  if (dp[i][totalW] != -1)
    return dp[i][totalW];

  auto &[w, s, v] = vec[i];

  ll ans = f(i + 1, totalW);

  if (totalW <= s) {
    ans = max(ans, v + f(i + 1, totalW + w));
  }

  return dp[i][totalW] = ans;
}

int main() {

  cin >> n;
  vec.resize(n);

  for (int i = 0; i < n; i++) {
    auto &[w, s, v] = vec[i];
    cin >> w >> s >> v;
  }

  sort(begin(vec), end(vec), [&](auto &a, auto &b) {
    auto &[w1, s1, v1] = a;
    auto &[w2, s2, v2] = b;

    return w1 + s1 < w2 + s2;
  });

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0) << endl;

  return 0;
}