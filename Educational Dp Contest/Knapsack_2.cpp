#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = 1e18;

int n;

// Min wt to achieve value v using items from 0 --- (i-1) 
ll f(int i, int v,vector<ll> &wt, vector<ll> &val){

  if(v == 0) return 0;
  if(i == n) return LINF; /// 

  ll skip = f(i + 1, v, wt, val);

  ll take = LINF;
  if(val[i] <= v){
    take = wt[i] + f(i + 1, v - val[i], wt, val);
  }

  return min(take, skip);
}

int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll W;
  
  cin >> n >> W;

  vector<ll> wt(n), val(n);

  ll sumVal = 0;
  for(int i = 0; i < n; i++){
    cin >> wt[i] >> val[i];
    sumVal += val[i];
  }

  vector<ll> dp(sumVal + 1, LINF);  // dp[v] = min wt needed to achieve value v
  dp[0] = 0; // val = 0 require wt = 0

  for(int i = 0; i < n; i++){

    for(ll v = sumVal; v >= val[i]; v--){
      if(dp[v] - val[i] != LINF)
        dp[v] = min(dp[v], wt[i] + dp[v - val[i]]);
    }
  }
  
  for(ll v = sumVal; v >= 0; v--){
    if(dp[v] <= W){
      cout << v << endl;
      break;
    }
  }

  return 0;
}