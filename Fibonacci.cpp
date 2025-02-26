#include <bits/stdc++.h>
#define comp ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll fib(int x){
    ll fib_n = 1;
    ll fib_prev = 0;
    for(int i = 0; i < x; ++i){
        fib_prev+=fib_n;
        swap(fib_n, fib_prev);
        fib_n%= MOD;
        fib_prev%=MOD;
    }

    return fib_prev;
}
int32_t main(){
    comp;
    int x; cin >>x;
    cout << fib(x) <<endl;
    return 0;
}
