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

int n;
vector<double> p;

double dp[3005][3005];
bool vis[3005][3005];

double f(int i, int heads)
{

  if (i == n)
  {
    return heads > (n - heads); // If heads > Tails then prob of heads > prob of tails, return 1, valid way found
  }

  if (vis[i][heads])
    return dp[i][heads];
  vis[i][heads] = true;

  double takeHead = p[i] * f(i + 1, heads + 1);
  double takeTail = (1.0 - p[i]) * f(i + 1, heads);

  return dp[i][heads] = takeHead + takeTail;
}

int main()
{
  fastio();

  cin >> n;

  p.resize(n);

  for (int i = 0; i < n; i++)
    cin >> p[i];

  memset(vis, 0, sizeof(vis));
  cout << fixed << setprecision(10) << f(0, 0) << endl;
}

/*
int main()
{
  fastio();

  int n;
  cin >> n;

  vector<double> p(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
  dp[0][0] = 1.0;

  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= i;  j++){

      // Tail
      dp[i][j] += dp[i-1][j] * (1 - p[i]);
      // Head
      if(j > 0)
        dp[i][j] += dp[i-1][j-1] * p[i];
    }
  }

  double res = 0.0;

  for (int j = n / 2 + 1; j <= n; j++)
  {
    res += dp[n][j];
  }

  cout << fixed << setprecision(10) << res << endl;

  return 0;
}
*/