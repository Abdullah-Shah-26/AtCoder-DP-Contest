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

ll n, m;
/* 
ll dp[1001][1001];

ll dfs(int i, int j, vector<vector<char>> &grid)
{
  if (i >= n || j >= m)
    return 0;
  if (grid[i][j] == '#')
    return 0;
  if (i == n - 1 && j == m - 1)
    return 1;

  if (dp[i][j] != -1)
    return dp[i][j];

  ll ways = 0;

  ways = (ways + dfs(i + 1, j, grid)) % MOD;
  ways = (ways + dfs(i, j + 1, grid)) % MOD;

  return dp[i][j] = ways;
}
*/


int main()
{
  fastio();

  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m, '.'));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  // memset(dp, -1, sizeof(dp));
  // cout << dfs(0, 0, grid) << endl;

  vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));

  dp[n-1][m-1] = grid[n-1][m-1] == '.';

  for(int i = n-1; i >= 0; i--){
    for(int j = m-1; j >= 0; j--){
      
      if(grid[i][j] == '#') continue;

      // DAG Like Graph So No need of visited :)
      dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i][j+1]) % MOD;
    }
  }

  cout << dp[0][0] << endl;

  return 0;
}