#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K;
    cin >> N >> K;
    vector<int> treat(N+1, 0);
    REP(i,K){
        int d;
        cin >> d;
        REP(j,d){
            int a;
            cin >> a;
            treat[a]++;
        }
    }

    int ans = 0;
    REP(i,N){
        if (treat[i+1] == 0){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}