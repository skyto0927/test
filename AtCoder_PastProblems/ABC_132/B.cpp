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
    int N; cin >> N;
    vector<int> P(N);

    REP(i,N) cin >> P[i];

    int ans = 0;

    FOR(i,1,N-1){
        if((P[i+1]-P[i]) * (P[i]-P[i-1]) > 0) ans++;
    }

    cout << ans << endl;
    return 0;
}