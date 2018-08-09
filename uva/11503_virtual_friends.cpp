
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// TIMER
std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
    __duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
    std::cout << "Duration (msec): " << __duration * 1000 << '\n';
}
// END TIMER

//PI
#define M_PI		3.14159265358979323846
// fast input
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

template <class T>
T min_(T a, T b) { return (a < b ? a : b); }
template <class T>
T max_(T a, T b) { return (a > b ? a : b); }

double EPS = 1e-16;
bool eq_(const double& lhs, const double &rhs) {
    return (fabs(lhs - rhs) < EPS);
}

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<llll> vllll;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;

const int INF = int(2e9);
const ll INF_LL = LLONG_MAX;
const ll MOD = 1e9 + 7;
const int MAX_N = 2e5+5;

vi setsz;
vi parent;

int find_set(int u) {
    if (u != parent[u])
        parent[u] = find_set(parent[u]);
    return parent[u];
}

int unite(int u, int v) {
    int pu = find_set(u);
    int pv = find_set(v);
    if (pu == pv)
        return setsz[pv];

    if (setsz[pu]<setsz[pv])
        swap(pu,pv);
    parent[pv] = pu;
    setsz[pu] += setsz[pv];
    return setsz[pu];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, F;
    string u,v;
    cin>>T;
    while(T--) {
        cin>>F;
        unordered_map<string,int> name_id;
        parent.assign(2*F+1, 0);
        setsz.assign(2*F+1, 0);
        int id = 0;
        int currsz;
        for (int i = 0; i < F; ++i) {
            cin>>u>>v;
            if (name_id.find(u) == name_id.end()) {
                name_id[u] = id;
                setsz[id]++;
                parent[id] = id;
                ++id;
            }
            if (name_id.find(v) == name_id.end()) {
                name_id[v] = id;
                setsz[id]++;
                parent[id] = id;
                ++id;
            }
            currsz = unite(name_id[u], name_id[v]);
            cout<<currsz<<'\n';
        }

    }
    return 0;
}
