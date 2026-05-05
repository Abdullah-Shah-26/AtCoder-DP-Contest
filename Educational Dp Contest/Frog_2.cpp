#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const int INF = 1e9;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, k;

vi dp;

/* 

int f(int i, vi &a){
  if(i == n-1) return 0;

  if(dp[i] != -1) return dp[i];

  int ans = INF;

  for(int jump = 1; jump <= k; jump++){
    int j = i + jump;

    if(j < n){
      ans = min(ans, abs(a[i] - a[j]) + f(j, a));
    }
  }

  return dp[i] = ans;
}

*/

int main() {
  fastio();

  cin >> n >> k;

  vi a(n);
  dp.assign(n, INF);

  for(int i = 0; i < n; i++) cin >> a[i];

  // cout << f(0, a) << endl;

  dp[n-1] = 0; // Base Case
  
  /*
   
  for(int i = n-2; i >= 0; i--){ // TC = O(N ^ 2)

    int ans = INF;
    for(int jump = 1; jump <= k; jump++){
      int j = i + jump;

      
      if(j < n){
        ans = min(ans, abs(a[i] - a[j]) + dp[j]);
      }
    }

    dp[i] = ans;
  }

  */

  multiset<int> ms1, ms2; 

  for(int i = n-2; i >= 0; i--){
    
  }

  cout << dp[0] << endl;

  return 0;
}