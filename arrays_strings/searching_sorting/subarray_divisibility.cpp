#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define sz size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
typedef vector<vll> vvll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 2e9;
const ll LINF = 2e18;
 
int main() {
    fast_io;
    int n; cin >> n;
    vi a(n); rep(i, 0, n) cin >> a[i];
    map<ll, int> mp;
    mp[0] = 1;
    ll cnt = 0, cur = 0;
    for (int i=0; i<n; i++) {
        cur = (cur + 0ll + (a[i]%n) + n) % n;
        cnt += mp[cur];
        mp[cur]++;
    }
    cout << cnt << endl;
}
