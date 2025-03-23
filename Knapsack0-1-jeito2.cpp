#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 112345;

void solve(){
    int w,n; cin >> w >> n; // Recebendo o peso que a mochila suporta e o numero de itens
    vector<int> dp(w+1, 0) , ps(n), vl(n); // Criando os vetores para a representação de itens e mochila

    for(int i = 0; i < n; i++)
        cin >> ps[i] >> vl[i]; // Recebendo entrada na ordem -> Peso Item -> Valor Item

    for(int i = 0; i < n; i++)
        for(int j = w; j >= ps[i]; j--)
            dp[j] = max(dp[j], dp[j - ps[i]] + vl[i]); // Verificando se a melhor opção em comparação ao peso do item I: Deixar(dp[j]) ou Levar(dp[j - ps[i]] + vl[i])


    cout << dp[w] << endl;
}

int32_t main(){
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return  0;
}
