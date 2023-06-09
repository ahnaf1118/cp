#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i=a; i<b; i++)
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9;
const ll LINF = 1e17;

vi graph[N];
vvi up(N, vi(20, 0));

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i=1; i<20; i++)
        if (up[v][i-1] != -1) up[v][i] = up[up[v][i-1]][i-1];
        else up[v][i] = -1;
    for (auto c: graph[v]) {
        if (c==p) continue;
        dfs(c, v);
    }
}

int ans_query(int v, int k, int index=19) {
    if (v==-1 or not k) return v;
    for (int i=index; i>=0; i--) {
        if (k >= (1<<i)) return ans_query(up[v][i], k-(1<<i), i);
    }
}

int main() {
    int n, q; cin >> n >> q;
    rep(i, 0, n-1) {
        int u=i+2, v;
        cin >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, -1);
    rep(i, 0, q) {
        int u, k;
        cin >> u >> k;
        cout << ans_query(u, k) << endl;
    }
}