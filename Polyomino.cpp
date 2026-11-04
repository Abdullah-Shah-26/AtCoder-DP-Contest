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
ll dp[45][4];

// Grid : 2 x N

ll f(int i, int mask) {
  if (i == n)
    return mask == 0;

  if (i > n)
    return 0;

  ll &ans = dp[i][mask];

  if (ans != -1)
    return ans;

  ans = 0;

  // Both rows of this col are filled
  if (mask == 3)
    ans += f(i + 1, 0);

  // Both rows are empty
  else if (mask == 0) {

    // Place vertical tile
    ans += f(i + 1, 0);

    // Place single L

    // Both rows of cur col gets filled
    // Next col's bottom row also gets filled
    ans += f(i + 1, 1); // 01

    // Both rows of cur col gets filled
    // Next col's top row also gets filled
    ans += f(i + 1, 2); // 10

    // Place 2 L's
    // Both rows of cur & next col's gets filled
    ans += f(i + 3, 0);
  }

  // 1 cell filled & other empty
  // Place L
  else {
    ans += f(i + 2, 0);
  }

  return ans;
}

int main() {

  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0) << endl;

  return 0;
}