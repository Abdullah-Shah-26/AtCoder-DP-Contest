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

struct Fenwick {
  int n;
  vll bit;

  Fenwick(int n) {
    this->n = n;
    bit.resize(n + 1, 0);
  }

  void updateMax(int i, ll val) {
    while (i < n) {
      bit[i] = max(bit[i], val);
      i += i & -i;
    }
  }

  ll prefMax(int i) {
    ll ans = 0;

    while (i > 0) {
      ans = max(ans, bit[i]);
      i -= i & -i;
    }

    return ans;
  }
};

int main() {
  int n;
  cin >> n;

  vll h(n), a(n);

  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  Fenwick ft(n);
  ll ans = 0;

  // Ht is treated as indices of fenwick tree
  for (int i = 0; i < n; i++) {
    ll best = a[i] + ft.prefMax(h[i] - 1);

    ans = max(ans, best);

    // The best dp value at this h[i] is stored & updated in fenwick
    ft.updateMax(h[i], best);
  }

  cout << ans << endl;

  return 0;
}