#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    double P;
    cin >> P;
    double a = pow(2, 1/1.5);

    double ans;
    if ((log(P)+log(log(a)))/log(a) < 0){
        ans = P;
    }else{
        ans = (log(P) + log(log(a)) + 1)/log(a);
    }
    cout << fixed << setprecision(10) <<ans << endl;
}
