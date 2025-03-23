#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define vt vector
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 112345;

int LCS(string a, string b){
    int m = a.size(), n = b.size() , mx = 0;
    vt<vt<int>> dp(m+1, vt<int>(n+1, 0)); // Matriz de indices para guardar quantos são iguais  nas 2 strings
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]){
                // Percorrendo a substring a de 0 ate i e de b de 0 ate j, e verificando se o caractere é igual para acrescentar na DP[i][j](estado das 2 substrings)
                dp[i][j] = dp[i-1][j-1]+1;
                mx = max(mx, dp[i][j]); // iterador de tamanho de substring
            }else{
                // Se não, verifica o melhor estado
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return mx;
}

void solve(){
    string a, b; cin >> a >> b;
    cout << LCS(a, b) << endl; // Verificando o tamanho da Maior Subsequencia Contigua de A e B (LCS).
}

int32_t main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return  0;
}
