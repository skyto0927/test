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
    string a,b,c; cin >> a >> b >> c;
    if(a[a.size()-1] == b[0] && b[b.size()-1]==c[0])cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}