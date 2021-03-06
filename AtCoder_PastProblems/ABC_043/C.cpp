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
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    int ans = INF;
    for(int i=-100; i<=100; i++){
        int sum = 0;
        REP(j,N){
            sum += (i-a[j]) * (i-a[j]);
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}