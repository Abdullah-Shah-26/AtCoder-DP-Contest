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
const int N = 301;

bool vis[N][N][N];
double dp[N][N][N];

double f(int c1, int c2, int c3){
  if(c1 == 0 && c2 == 0 && c3 == 0) return 0;

  if(vis[c1][c2][c3]) return dp[c1][c2][c3];

  vis[c1][c2][c3] = 1;

  double ans = 1; // curMove

  // Hit plate having 1 sushi
  if(c1 > 0){
    ans += (1.0 * c1/n) * f(c1-1, c2, c3);
  }

  // Hit plate having 2 sushi's
  if(c2 > 0){
    ans += (1.0 * c2/n) * f(c1+1, c2-1, c3);
  }

  // Hit plate having 3 sushi's
  if(c3 > 0){
    ans += (1.0 * c3/n) * f(c1, c2+1, c3-1);
  }

  // Empty plate possiblity
  double pEmpty = 1.0 * (n - (c1 + c2 + c3))/n;

  ans /= (1.0 - pEmpty);

  return dp[c1][c2][c3] = ans; 
}

int main()
{
  fastio();

  cin >> n;
  vi cnt(4); // c1, c2, c3

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }

  cout << fixed << setprecision(10) << f(cnt[1], cnt[2], cnt[3]) << endl;

  return 0;
}