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
const int MAXN = 1e3;

struct node{
    int x, y, dis;
    
};

int parent[MAXN] , peso[MAXN], n , m;
node nodes[MAXN],  MST[MAXN];

bool cmp(node a, node b){
    return a.dis < b.dis;
}

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

void solve(){

    cin >> n >> m;
    // Resetando o Union Find
    for(int i = 1 ; i <= n; i++){
        parent[i] = i;
        peso[i] = 0;
    }
    // Recebendo as arestas e com os pesos
    for(int i = 1; i <= m; i++) cin >> nodes[i].x >> nodes[i].y >> nodes[i].dis;
    // Ordenando as arestas pelos pesos
    sort(nodes+1, nodes+1+m, cmp);
    int s = 0;
    // Iterador da MST
    for(int i = 1; i <= m; i++){
        // Verificando se um vertice com outro ja faz parte do mesmo componente conexo
        if(find(nodes[i].x) != find(nodes[i].y)){
            // Se não : juntar e acrescentar na MST
            join(nodes[i].x, nodes[i].y);
            MST[++s] = nodes[i];
        }
    }
    int peso_total = 0;
    // Calculando o peso total da arvore
    for(int i = 1; i < n; i++){
        // Printando as arestas da arvore
        cout << MST[i].x << " -> " << MST[i].y << ": " << MST[i].dis << endl; 
        peso_total += MST[i].dis;
    }
    cout << peso_total << endl;
    
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
