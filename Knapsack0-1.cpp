#include <bits/stdc++.h>
#define comp ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int memo[2020][2020];

int n, c;
int v[2020], w[2020];
ll dp(int ind, int cap){
    if(cap < 0) return -INF;
    if(ind == n) return 0;
    int& pdm = memo[ind][cap];

    if(pdm!=-1) return pdm;
    return pdm = max(dp(ind+1,cap - w[ind]) + v[ind], dp(ind+1, cap));
}

int32_t main(){
    comp;
    cin >> n >> c;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }

    cout << dp(0,c) << endl;
    return 0;
}
