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
const int MOD = 998244353;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

/*

i = no of chars constructed in T
c1 = no of chars matched from s1 as subseq
c2 =                          s2
c3 =                          s3

F(i, c1, c2, c3) = No of ways to complete remaining positions of T without containing any of s1,s2,s3 as a subsequence

*/

int N;
string s1, s2, s3;
int n1, n2, n3;

ll dp[1001][10][10][10];

ll f(int i, int c1, int c2, int c3) {

  if (c1 == n1 || c2 == n2 || c3 == n3)
    return 0;

  if (i == N)
    return 1;

  ll &ans = dp[i][c1][c2][c3];

  if (ans != -1)
    return ans;

  ans = 0;

  for (char ch = 'a'; ch <= 'z'; ch++) {

    int nc1 = c1;
    int nc2 = c2;
    int nc3 = c3;

    if (c1 < n1 && s1[c1] == ch)
      nc1++;

    if (c2 < n2 && s2[c2] == ch)
      nc2++;

    if (c3 < n3 && s3[c3] == ch)
      nc3++;

    ans = (ans + f(i + 1, nc1, nc2, nc3)) % MOD;
  }

  return ans;
}

int main() {

  cin >> N;
  cin >> s1 >> s2 >> s3;

  n1 = s1.size();
  n2 = s2.size();
  n3 = s3.size();

  memset(dp, -1, sizeof(dp));
  cout << f(0, 0, 0, 0);

  return 0;
}