#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

//////////////////ここの値は必ず確認！！！！！////////////////////
//---------------------------------------------------------//
const int MOD = 998244353;
const int MAXR = 510000;
//---------------------------------------------------------//

template<ll mod> class modint{
public:
    ll val=0;
    //コンストラクタ
    modint(ll x=0){while(x<0)x+=mod;val=x%mod;}
    //コピーコンストラクタ
    modint(const modint &r){val=r.val;}
    //算術演算子
    modint operator -(){return modint(-val);} //単項
    modint operator +(const modint &r){return modint(*this)+=r;}
    modint operator -(const modint &r){return modint(*this)-=r;}
    modint operator *(const modint &r){return modint(*this)*=r;}
    modint operator /(const modint &r){return modint(*this)/=r;}
    //代入演算子
    modint &operator +=(const modint &r){
        val+=r.val;
        if(val>=mod)val-=mod;
        return *this;
    }
    modint &operator -=(const modint &r){
        if(val<r.val)val+=mod;
        val-=r.val;
        return *this;
    }
    modint &operator *=(const modint &r){
        val=val*r.val%mod;
        return *this;
    }
    modint &operator /=(const modint &r){
        ll a=r.val,b=mod,u=1,v=0;
        while(b){
            ll t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        val=val*u%mod;
        if(val<0)val+=mod;
        return *this;
    }
    //等価比較演算子
    bool operator ==(const modint& r){return this->val==r.val;}
    bool operator <(const modint& r){return this->val<r.val;}
    bool operator !=(const modint& r){return this->val!=r.val;}
};

using mint = modint<MOD>;

//入出力ストリーム
istream &operator >>(istream &is,mint& x){//xにconst付けない
    ll t;is >> t;
    x=t;
    return (is);
}
ostream &operator <<(ostream &os,const mint& x){
    return os<<x.val;
}

//累乗
mint modpow(const mint &a,ll n){
    if(n==0)return 1;
    mint t=modpow(a,n/2);
    t=t*t;
    if(n&1)t=t*a;
    return t;
}

//二項係数の計算
mint fac[MAXR+1],finv[MAXR+1],inv[MAXR+1];
//テーブルの作成
void com_init() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    FOR(i,2,MAXR){
        fac[i]=fac[i-1]*mint(i);
        inv[i]=-inv[MOD%i]*mint(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}
//演算部分
mint com(ll n,ll k){
    if(n<k)return 0;
    if(n<0)return 0;
    if(k==0) return 1;
    return fac[n]*finv[k]*finv[n-k];
}

template<typename T> vector<T> compress(vector<T> &C1){
    vector<T> vals;
    int N = (int)C1.size();
    REP(i,N){
        vals.push_back(C1[i]);
    }

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,N){
        C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin() + 1;
    }

    return vals;
}

template<class T> struct BIT{
    vector<T> bit;
    int M;

    BIT(int M_): M(M_+1), bit(M_+1,0) {}

    T sum(int a){//sum [1,i) 1_indexed!!!!
        int ret = 0;
        for(int i=a; i>0; i-= i & -i) ret += bit[i];
        return ret;
    }
    
    T sum(int a, int b){//sum [i,j)  1_indexed!!!!
        return sum(b-1) - sum(a-1);
    }

    void add(int a, T x){
        for(int i=a; i<M; i+= i & -i) bit[i] += x;
    }

    void print(){
        FOR(i,1,M){
            cout << sum(i,i+1) << " ";
        }
        cout << endl;
    }
};

int main() {
    int N; cin >> N;
    vector<int> Y(N);
    vector<pair<int,int>> XY(N);
    REP(i,N){
        cin >> XY[i].first >> XY[i].second;
    }
    sort(ALL(XY));
    REP(i,N){
        Y[i] = XY[i].second;
    }

    compress(Y);
    BIT<int> left(N*2);
    BIT<int> right(N*2);

    REP(i,N){
        right.add(Y[i],1);
    }


    mint ans = 0;
    REP(i,N){
        
        left.add(Y[i],1);
        right.add(Y[i],-1);

        mint lu = modpow((ll)2, left.sum(Y[i]+1,N+1)) - 1;
        mint ld = modpow((ll)2, left.sum(1,Y[i])) - 1;
        mint ru = modpow((ll)2, right.sum(Y[i]+1,right.M)) - 1;
        mint rd = modpow((ll)2, right.sum(1,Y[i])) - 1;
        ans += modpow((ll)2, N-1);
        ans += lu*rd;
        ans += ld*ru;
        ans += lu*rd*(ld+ru);
        ans += ld*ru*(lu+rd);
        ans += lu*ld*ru*rd;
    }
    cout << ans << endl;

    return 0;
}