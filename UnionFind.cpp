#include <bits/stdc++.h>
#define comp ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define E end()
#define B begin()
#define fill(v,n) for(int i = 0; i < n; ++i) cin >> v[i];
#define vt vector
#define ii pair<int,int>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5;
int parent[MAXN], peso[MAXN];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(peso[a] < peso[b]) parent[a] = b;
    else if(peso[b] < peso[a]) parent[b] = a;
    else{
        parent[a] = b;
        peso[b]++;
    }
}
int n,m;

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        peso[i] = 0; 
    }
    while(m--){
        int x,y; cin >> x >> y;
        // Juntando o conjunto de X com o conjunto de Y
        join(x,y);
    }

    int a,b; cin >> a >> b ;
    // Verificando se A e B pertecem ao mesmo conjunto
    cout << ((find(a) == find(b))? "Estao no mesmo conjunto.":"Nao estao no mesmo conjunto.") << endl;
}

int32_t main(){
    comp;
    int t = 1;
    //cin >> t;
    for(int js = 1; js <= t; js++){
        solve();
    }
    return 0;
}
