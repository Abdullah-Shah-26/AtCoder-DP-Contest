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

// If I can make atleast 1 move that puts my opponent in a losing state - then I WIN

int main() {

  int n, k;
  cin >> n >> k;

  vi a(n);

  for (int &x : a)
    cin >> x;

  vb dp(k + 1, false);

  for (int i = 1; i <= k; i++) {
    for (int j : a) {
      if (i >= j && dp[i - j] == false) {
        dp[i] = true;
      }
    }
  }

  if (dp[k] == true)
    cout << "First" << endl;
  else
    cout << "Second" << endl;

  return 0;
}