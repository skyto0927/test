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
    ll a,b,x; cin >> a >> b >> x;
    ll bb = b/x + 1;
    ll aa = (a==0?0:(a-1)/x + 1);
   
    cout <<  bb-aa << endl;

    return 0;
}