#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <memory>
#include <functional>
using namespace std;

#define ALL(g) (g).begin(), (g).end()
#define REP(i, x, n) for(auto i=x; i<n; i++)
#define rep(i, n) REP(i, 0, n)
#define RET(i, x, n) for(auto i=x; i<=n; i++)
#define ret(i, n) REP(i, 0, n)
#define F(i, j, k) fill(i[0], i[0]+j*j, k)
#define P(p) cout << (p) << endl;
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define pb push_back

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<long, long> pil;
typedef long long ll;

int N, Q;
int O[200005];

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin >> N >> Q;
  int x, y;
  rep(i, Q) {
    cin >> x >> y;
    x--;
    y--;
    O[x]++;
    O[y+1]--;
  }

  int cnt = 0;
  rep(i, N) {
    cnt += O[i];
    cout << cnt % 2;
  }
  cout << endl;
  return 0;
}
