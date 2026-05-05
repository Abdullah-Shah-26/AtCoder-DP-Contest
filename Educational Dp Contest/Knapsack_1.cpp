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

ll n, limit;

//! Approach 1 : Rec + Memo

/*
ll dp[101][100001];

ll f(int i, ll curWt, vector<pair<ll, ll>> &a)
{

  if (i >= n || curWt > limit)
    return 0;

  if (dp[i][curWt] != -1)
    return dp[i][curWt];

  ll skip = f(i + 1, curWt, a);

  ll take = 0;

  if (curWt + a[i].first <= limit)
  {
    take = a[i].second + f(i + 1, curWt + a[i].first, a);
  }

  return dp[i][curWt] = max(take, skip);
} 
*/


//! Approach 2 :  Another Way of writing Rec + Memo - which is easier to map to bottom up

ll memo[101][100005];
ll f(int i, int W, vector<pair<ll,ll>> &a){
  
  if(i == 0 || W == 0) return 0;

  if(memo[i][W] != -1) return memo[i][W];

  ll skip = f(i - 1, W, a);
  ll take = 0;

  ll wt = a[i-1].first;
  ll val = a[i-1].second;

  if(wt <= W){
    take = f(i - 1, W - wt, a) + val;
  }

  return memo[i][W] = max(take, skip);
}

int main()
{
  fastio();

  cin >> n >> limit; // Limit on wt

  vector<pair<ll, ll>> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second; // wt, val
  }

  // memset(dp, -1, sizeof(dp));
  // cout << f(0, 0, a) << endl;

  //? memset(memo, -1, sizeof(memo));
  //? cout << f(n, limit, a) << endl;

  //! Approach 1 : Bottom Up 

  /* 
  vector<vector<ll>> dp(n+1, vector<ll> (limit + 1, 0));
  
  // Base Case :

  for(int i = n-1; i >= 0; i--){
    for(int wt = 0; wt <= limit; wt++){
      
      ll skip = dp[i+1][wt];
      ll take = 0;

      if(wt + a[i].first <= limit)
        take = a[i].second + dp[i+1][wt + a[i].first];
    
      dp[i][wt] = max(take, skip);  
    }
  }

  cout << dp[0][0];
  */

  //! Approach 2 : Bottom Up

  vector<vector<ll>> dp(n + 1, vector<ll> (limit + 1, 0));

  //* Base Case
  for(int i = 0; i <= n; i++) dp[i][0] = 0;
  for(int j = 0; j <= limit; j++) dp[0][j] = 0;

  for(int i = 1; i <= n; i++){
    for(int W = 1; W <= limit; W++){

      ll take = 0;
      ll skip = dp[i-1][W];
    
      ll value = a[i-1].second;
      ll wt = a[i-1].first;

      if(wt <= W){
        take = value + dp[i-1][W - wt];
      }

      dp[i][W] = max(take, skip);
    }
  }

  cout << dp[n][limit] << endl;

 return 0;
}