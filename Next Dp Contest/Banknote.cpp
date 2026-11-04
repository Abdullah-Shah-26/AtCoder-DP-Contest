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

f(i, carry) = min extra no of notes needed from digit position I onwards

*/

string s;
int n;
ll dp[20][2];

ll f(int i, int carry) {

  // All digits processed
  if (i == n)
    return carry;

  ll &ans = dp[i][carry];

  if (ans != -1)
    return ans;

  ans = LINF;

  for (int x = 0; x <= 9; x++) {

    // Since we are processing digits from R -> L
    int d = s[n - i - 1] - '0';

    int sum = d + x + carry;

    int digit = sum % 10;
    int ncarry = sum / 10;

    ans = min(ans, x + digit + f(i + 1, ncarry));
  }

  return ans;
}

void solve() {
  ll num;
  cin >> num;

  s = to_string(num);
  n = s.size();

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0) << endl;
}

int main() {

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}