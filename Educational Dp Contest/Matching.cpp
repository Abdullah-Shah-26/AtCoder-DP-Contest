#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

static const auto fastio = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

const int N = 21;

int n;
int comp[N][N]; // compatibility
int dp[N][1 << N];

// mask = bitmask of used indices

int f(int i, int mask){
  if(i >= n)
    return 1;

  if(dp[i][mask] != -1)
    return dp[i][mask];

  int ways = 0; 

  for(int j = 0; j < n; j++){
    if(mask & (1 << j))
      continue;

    if(comp[i][j]){
      ways  = (ways + f(i + 1, mask | (1 << j))) % MOD;
    }
  }

  return dp[i][mask] = ways;
}

int main() {

  cin >> n;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> comp[i][j];

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0) << endl;

  return 0;
}