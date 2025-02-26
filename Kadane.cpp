#include <bits/stdc++.h>
#define comp ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int kadane(vector<int> v){
    int maximo = 0;
    int aux = -INF;
    for(auto i : v){
        aux+=i;
        maximo = max(maximo, aux);
        if(aux < 0) aux = 0;
    }
    return maximo;
}

int32_t main(){
    comp;
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = kadane(v);
    cout << "A maior soma máxima do array v e: " << ans << endl;
    return 0;
}
