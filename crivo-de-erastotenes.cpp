#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define vt vector
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 112345;
const int MAXM = 1123456789;
const int INF = INT_MAX;

bool crivo[MAXN]; // Vetor de numeros de 1 até 112345

void c(){
    memset(crivo, true, sizeof crivo); // Resetando o vetor
    crivo[0] = crivo[1] = false; // 0 e 1 não são primos
    for(int i = 2; i * i <= MAXN; i++){ // Percorrendo de 2 até a raiz de 112345
        if(crivo[i]){ // Verificando se o numero é primo ( caso base já que todos foram colocados como primos )
            for(int j = i*i; j < MAXN; j+= i) // Percorrer os multiplos do numero primo para distinguir os numeros que não são primos
                crivo[j] = false; // J não é primo
        }
    }
}

void solve(){
    int n; cin >> n;
    cout << (crivo[n] ? "Primo":"Nao eh primo") << endl; // se o numero for primo -> a[numero] = true, else a[numero] = false
}

int32_t main(){
    int t = 1;
    //cin >> t;
    c(); // Executando a função
    while(t--){
        solve();
    }
    return  0;
}
