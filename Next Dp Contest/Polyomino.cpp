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
// We can rotate tiles

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

    // |
    // |
    // Place vertical tile (2 x 1)
    // Covering both rows
    ans += f(i + 1, 0);

    // ___ ___
    // ___ ___
    // Place vertical tiles horizontally
    ans += f(i + 2, 0);

    // Place single L

    // |
    // |___
    // Both rows of cur col gets filled
    // Next col's bottom row also gets filled
    ans += f(i + 1, 1); // 01

    // ____
    // |
    // |
    // Both rows of cur col gets filled
    // Next col's top row also gets filled
    ans += f(i + 1, 2); // 10

    // Overcounting : Already covered below
    //   ___
    // |   |
    // |__ |
    // Place 2 L's
    // Both rows of cur, cur + 1, cur + 2 col's gets filled
    // ans += f(i + 3, 0);
  }

  // Bottom cell filled, top cell empty
  else if (mask == 1) { // 01

    // Place horiztontal tile
    // Covers top cell of this & next col
    ans += f(i + 1, 2); // 10

    // Place L
    // Covers the top cell & both rows of next col
    // ___
    //   |
    //   |
    ans += f(i + 2, 0);
  }

  // Top cell filled, bottom cell empty
  else if (mask == 2) { // 10

    // Place horizontal tile
    // Covers next col bottom cell
    ans += f(i + 1, 1);

    // Place L
    //    |
    // ___|
    // Covers both rows of cur & next col
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