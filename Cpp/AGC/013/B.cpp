//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

// 基本テンプレート
#pragma region MACRO
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define PED cout << "\n"
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define REP(i,x,n) for(int i=x; i<(int)n; ++i)
#define repi(i,n) for(int i=0; i<=(int)n; ++i)
#define REPI(i,x,n) for(int i=x; i<=(int)n; ++i)
#define ILP while(true)
#define FOR(i,c) for(__typeof((c).begin())!=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#pragma endregion

// 型
#pragma region TYPE_DEF
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<string> vs;
#pragma endregion

// Effective std
#pragma region ESTD
template<typename C, typename T> int count(C& c, T t) { return count(ALL(c), t); }
template<typename C, typename F> int count_if(C& c, F f) { return count_if(ALL(c), f); }
template<typename C, typename T> void erase(C& c, T t) { remove(ALL(c), t), c.end(); }
template<typename C> void remove(vector<C>& c, unsigned int index) { c.erase(c.begin()+index); }
template<typename C, typename T, typename U> void replace(C& c, T t, U u) { replace(ALL(c), t, u); }
template<typename C, typename F, typename U> void replace_if(C& c, F f, U u) { (ALL(c), f, u); }
template<typename C> void reverse(C& c) { reverse(ALL(c)); }
template<typename C> void sort(C& c) { sort(ALL(c)); }
template<typename C, typename Pred> void sort(C& c, Pred p) { sort(ALL(c), p); }
#pragma endregion

// 定数
#pragma region CONST_VAL
constexpr int PI = (2*acos(0.0));
constexpr int EPS = (1e-9);
constexpr int MOD = (int)(1e9+7);
constexpr int INF = 100000000;
#pragma endregion

#define int long long

int N, M;

int memo[1000001] = {0};

signed main()
{
    cin >> N >> M;
    vector<vector<int> > graph(N+1);
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int tmp = 1;
    while(true) {
        for(int i=0; i<N+1; ++i) memo[i] = 0;
        vector<int> ans;
        stack<int> st;
        st.push(tmp);
        while(true) {
            if(st.empty()) break;
            int n = st.top();
            st.pop();
            ans.push_back(n);
            memo[n] = 1;
            int f = 0;
            for(int i=0; i<graph[n].size(); ++i) {
                if(memo[graph[n][i]]==0) {
                    f = 1;
                    break;
                }
            }
            if(f==0) break;
            vector<int> node = graph[n];
            for(int i=0; i<node.size(); ++i) {
                if(memo[node[i]]==1) continue;
                st.push(node[i]);
            }
        }
        tmp++;
        if(ans.size()<2) continue;
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); ++i) {
            if(i==0) cout << ans[i];
            else cout << " " << ans[i];
        }
        cout << endl;
        break;
    }

    return 0;
}
