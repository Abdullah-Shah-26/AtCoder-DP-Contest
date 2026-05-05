#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

/*

ll dp[100005][4];

ll f(int i, int last, vector<array<int,3>> &a){
  if(i == a.size()) return 0;

  if(dp[i][last] != -1) return dp[i][last];

  ll ans = 0;

  for(int j = 0; j < 3; j++){
    if(j == last) continue;

    ans = max(ans, a[i][j] + f(i + 1, j, a));
  }

  return dp[i][last] = ans;
}
  
*/

int main()
{
  fastio();

  int n;
  cin >> n;

  vector<vector<ll>> a(n, vector<ll>(3, 0));

  for (int i = 0; i < n; i++)
    cin >> a[i][0] >> a[i][1] >> a[i][2];

  // memset(dp, -1, sizeof(dp));
  // cout << f(0, 3, a) << endl; // Initally No Task Selected = 3, tasks are 0, 1, 2

  // dp[i][last] = max happiness from day i to n-1
  vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));

  for (int i = n - 1; i >= 0; i--) {
    for (int last = 0; last < 4; last++) {

      ll ans = 0;

      for (int j = 0; j < 3; j++) {
        if (j == last) continue;

        ans = max(ans, a[i][j] + dp[i + 1][j]);
      }

      dp[i][last] = ans;
    }
  }

  cout << dp[0][3] << endl;

  return 0;
}