#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll n,d; cin >> n >> d;
    int ans = 0;
    REP(i,n){
        ll x,y; cin >> x >> y;
         if(x*x+y*y<=d*d) ans++;

    }
    cout << ans << endl;
    return 0;
}