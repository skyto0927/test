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
    int A,B; cin >> A >> B;
    if((11+A)%13 > (11+B)%13) cout << "Alice" << endl;
    else if((11+A)%13 < (11+B)%13) cout << "Bob" << endl;
    else cout << "Draw" << endl;
    return 0;
}