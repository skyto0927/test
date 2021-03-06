#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N; cin >> N;
    ll V=0, E=0;
    REP(i,N-1){
        ll u,v; cin >> u >> v;
        E += min(u,v) * (N - max(u,v) + 1);
    }

    FOR(v,1,N+1){
        V += ll(v)*(ll(v)+1)/2;
    }

    cout << V - E << endl;
    return 0;
}