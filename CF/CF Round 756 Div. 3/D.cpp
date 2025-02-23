#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void printArr(vector<ll> &arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" \n"[i == n - 1];
    }
}

inline void prog() {
    int n, root = 0;
    cin>>n;
    vector<ll> b(n), p(n), dist(n), w(n, 0);
    vector<int> adjList[n];
    for(auto &i: b) cin>>i;
    for(auto &i: p) cin>>i;
    for(int i=0; i<n; i++) {
        b[i]--;
        p[i]--;
        dist[p[i]] = i;
        if(b[i] == i) {
            root = i;
            continue;
        }
        adjList[b[i]].push_back(i);
    }
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if((curr == root && w[curr] != 0) || ((curr != root) && (w[curr] < 1 || w[curr] > (int)1e9))) {
            cout<<"-1\n";
            return;
        }
        for(int &dest: adjList[curr]) {
            q.push(dest);
            w[dest] = dist[dest] - dist[curr];
        }
    }
    printArr(w, n);
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}