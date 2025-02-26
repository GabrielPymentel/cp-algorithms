#include <bits/stdc++.h>
#define comp ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<int> adj[2020] , visitados;
vector<int> bfs(int i){
    visitados[i] = 1;
    queue<int> fila;
    fila.push(i);
    while(!fila.empty()){
        int v_atual = fila.front();
        fila.pop();
        for(int v : adj[v_atual]){
            if(!visitados[v]){
                visitados[v] = 1;
                fila.push(v);
            }
        }       
    }

    return visitados;
}

int32_t main(){
    comp;
    int v, a; cin >> v >> a;
    visitados.assign(v,0);
    for(int i = 0; i < v; i++) adj[i].clear();
    for(int i = 0, x,y; i < a; i++){
        cin >> x >> y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    auto ans = bfs(0);
    for(int i : ans){
        cout << i << " ";
    }

    cout << endl;
    return 0;
}
