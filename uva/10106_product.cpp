
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

const int INF = int(2e9);
const ll INF_LL = LLONG_MAX;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string x,y;
	while(cin>>x && cin>>y) {
		vi res(x.size()+y.size(),0);
		reverse(x.begin(),x.end());
		reverse(y.begin(),y.end());
		for (int i = 0; i < x.size(); ++i) {
			int carry = 0;
			for (int j = 0; j < y.size(); ++j) {
					res[i+j] += (x[i]-'0')*(y[j]-'0')+carry;
					carry = res[i+j]/10;
					res[i+j] %= 10;
			}
			res[y.size()+i] += carry;
		}
		int idx = res.size()-1;
		while (idx>=0 && res[idx]==0)
			--idx;
		if (idx<0)
			cout<<0<<'\n';
		else {
			for (; idx>=0; --idx)
				cout<<res[idx];
			cout<<'\n';
		}
	}

  return 0;
}
