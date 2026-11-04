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

struct SegTree {
  int n;
  vll seg, lazy;

  SegTree(int n) {
    this->n = n;
    seg.assign(4 * n, -LINF);
    lazy.assign(4 * n, 0);
  }

  void apply(int i, ll val) {
    seg[i] += val;
    lazy[i] += val;
  }

  void push(int i) {
    if (lazy[i] == 0)
      return;

    apply(2 * i, lazy[i]);
    apply(2 * i + 1, lazy[i]);

    lazy[i] = 0;
  }

  // Range update
  void update(int i, int l, int r, int ql, int qr, ll val) {
    if (l > qr || r < ql)
      return;

    if (l >= ql && r <= qr) {
      apply(i, val);
      return;
    }

    push(i);

    int mid = (l + r) >> 1;

    update(2 * i, l, mid, ql, qr, val);
    update(2 * i + 1, mid + 1, r, ql, qr, val);

    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
  }

  // Range max query
  ll query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql)
      return -LINF;

    if (l >= ql && r <= qr)
      return seg[i];

    push(i);

    int mid = (l + r) >> 1;

    return max(query(2 * i, l, mid, ql, qr), query(2 * i + 1, mid + 1, r, ql, qr));
  }

  // Point update
  void update(int i, int l, int r, int pos, ll val) {
    if (l == r) {
      seg[i] = val;
      lazy[i] = 0;
      return;
    }

    push(i);

    int mid = (l + r) >> 1;

    if (pos <= mid)
      update(2 * i, l, mid, pos, val);
    else
      update(2 * i + 1, mid + 1, r, pos, val);

    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
  }

  void rangeAdd(int l, int r, ll val) {
    if (l > r)
      return;

    update(1, 0, n - 1, l, r, val);
  }

  ll queryMax(int l, int r) {
    if (l > r)
      return -LINF;

    return query(1, 0, n - 1, l, r);
  }

  void pointSet(int idx, ll val) { update(1, 0, n - 1, idx, val); }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, ll>>> events(n + 2);

  for (int i = 0; i < m; i++) {
    int l, r;
    ll w;

    cin >> l >> r >> w;

    events[l].push_back({l, w});
    events[r + 1].push_back({l, -w});
  }

  SegTree seg(n + 1);

  // dp[0] = 0, no prev 1
  seg.pointSet(0, 0);

  vll dp(n + 1, -LINF);

  for (int i = 1; i <= n; i++) {
    for (auto [l, w] : events[i]) {
      seg.rangeAdd(0, l - 1, w);
    }

    dp[i] = seg.queryMax(0, i - 1);

    seg.pointSet(i, dp[i]);
  }

  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << endl;

  return 0;
}