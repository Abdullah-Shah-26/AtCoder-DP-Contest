#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int n;
const int INF = 1e9;
/* 
int f(int i, vi &a, vi &dp){
  if(i == n-1) return 0;

  if(dp[i] != -1) return dp[i];

  int ans = INF;

  for(int jump = 1; jump <= 2; jump++){
    int j = jump + i;

    if(j < n){
      ans = min(ans, abs(a[i] - a[j]) + f(j, a, dp));
    }
  }
  
  return dp[i] = ans;
}
*/

int main(){
  fastio();

  cin >> n;

  vi a(n);

  for(int i = 0; i < n; i++) cin >> a[i];

  vi dp(n, INF);

  // dp[n-1] = 0;

  // for(int i = n-2; i >= 0; i--){
  //   for(int jump = 1; jump <= 2; jump++){
  //     int j = i + jump;

  //     if(j < n)
  //       dp[i] = min(dp[i], abs(a[i] - a[j]) + dp[j]);
  //   }
  // }

  // cout << dp[0] << endl;

  int next1 = 0; // dp[i+1]
  int next2 = 0; // dp[i+2]

  for(int i = n-2; i >= 0; i--){
      int cur = next1 + abs(a[i] - a[i+1]);

      if(i + 2 < n)
        cur = min(cur, next2 + abs(a[i] - a[i+2]));

      next2 = next1; 
      next1 = cur;
  }


  cout << next1 << "\n";

  return 0;
}