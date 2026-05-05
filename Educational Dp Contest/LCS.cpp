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

int dp[3001][3001];
int f(int i, int j, string &s, string &t)
{
  if (i == 0 || j == 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  if (s[i-1] == t[j-1])
  {
    return dp[i][j] = 1 + f(i - 1, j - 1, s, t);
  }
  else
  {
    return dp[i][j] = max(f(i - 1, j, s, t), f(i, j - 1, s, t));
  }
}

*/

int main()
{
  fastio();

  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();

  // memset(dp, -1, sizeof(dp));
  // int lcsLen = f(s.size(), t.size(), s, t);
  // cout << lcsLen << endl;

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;

  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {

      if (s[i - 1] == t[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int i = n, j = m;
  int lcsLen = dp[n][m];
  int idx = lcsLen;
  string lcs(lcsLen, '*');

  while (i > 0 && j > 0)
  {

      if (s[i - 1] == t[j - 1])
      {
        lcs[idx - 1] = s[i - 1];
        idx--;
        i--;
        j--;
      }
    else if (dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }

  cout << lcs << endl;

  return 0;
}