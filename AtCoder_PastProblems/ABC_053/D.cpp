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
    map<int,int> A;
    int N; cin >> N;
    REP(i,N){
        int a; cin >> a;
        A[a]++;
    }

    int ans = 0;
    for(auto a: A){
        ans += a.second - 1;
    }
    cout << N - (ans + ans%2) << endl;
    return 0;
}