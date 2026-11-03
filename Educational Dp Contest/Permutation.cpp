#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

/*

f(len, last) = no of valid perm of length len where last is the position of last element when perm is sorted 

ll f(int len, int last){
  if(len == 1)
    return 1;

  // len = 3
  // P1 P2 P3
  // P1 s[0] P2 s[1] P3

  // I want prev to be soemthing < P3 
  if(s[len - 2] == '<'){
    for(int prev = 1; prev < last; prev++)
      ans = (ans + f(len - 1, prev)) % MOD;
  }
    
  // I want prev to be something > P3
  else{
    for(int prev = last; prev <= len - 1; prev++)
      ans = (ans + f(len - 1, prev)) % MOD;
  }

  return ans;
}

*/

int main() {

  int n;
  cin >> n;

  string s;
  cin >> s;

  vll dp(n + 1, 0), ndp(n + 1, 0);
  vll pref(n + 1, 0);

  // 1 valid perm of len = 1
  dp[1] = 1;

  for (int len = 2; len <= n; len++) {

    // pref sum of prev dp row
    pref[0] = 0;
    for (int j = 1; j < len; j++)
      pref[j] = (pref[j - 1] + dp[j]) % MOD;

    for (int last = 1; last <= len; last++) {
      if (s[len - 2] == '<')
        ndp[last] = pref[last - 1] - pref[1 - 1];
      else
        ndp[last] = (pref[len - 1] - pref[last - 1] + MOD) % MOD; 
    }

    dp.swap(ndp);
    fill(begin(ndp), end(ndp), 0);
  }

  
  // 1 2 3 
  // len = 3
  // last = 1, dp[3][1] -> perm ending with smallest elem
  // last = 2, dp[3][2] -> perm ending with middle elem
  // last = 3, dp[3][3] -> perm ending with largest elem
  
  // ans = sum of all valid perms
  ll ans = 0;
  for (int last = 1; last <= n; last++)
    ans = (ans + dp[last]) % MOD;

  cout << ans << endl;

  return 0;
}