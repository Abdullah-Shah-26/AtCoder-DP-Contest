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
using T = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

const int N = 2e5 + 5;
const int LOG = 20;
int up[LOG][N];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  // nxt[x] = min end among events with st >= x
  // n + 1 = none
  vi nxt(n + 3, n + 1);

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    nxt[l] = min(nxt[l], r);
  }

  for (int x = n - 1; x >= 1; x--)
    nxt[x] = min(nxt[x], nxt[x + 1]);

  // up[0][x] = stores the next free day  
  int dead = n + 2;
  for (int x = 1; x <= n; x++)
    up[0][x] = (nxt[x] == n + 1 ? dead : nxt[x] + 1);
  
  up[0][n + 1] = up[0][dead] = dead;

  for (int k = 1; k < LOG; k++)
    for (int x = 1; x <= dead; x++)
      up[k][x] = up[k - 1][up[k - 1][x]];

  while (q--) {
    int l, r;
    cin >> l >> r;

    int pos = l, ans = 0;

    for (int k = LOG - 1; k >= 0; k--) {
      if (up[k][pos] <= r + 1) {
        pos = up[k][pos];
        ans += (1 << k);
      }
    }

    cout << ans << endl;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}