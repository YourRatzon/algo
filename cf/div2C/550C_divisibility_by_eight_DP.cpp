
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
const int MAX_N = 1e6 + 5;

vector<vb> DP;
vector<vi> prevv;
string s;

void print_answer(int i, int j) {
		int k = prevv[i][j];
		if (k == -1) {
			cout<<s[i]-'0';
			return;
		}
		print_answer(i-1,k);
		if ((10*k + (s[i]-'0')) % 8 == j) {
			cout<<s[i]-'0';
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>s;
	int N = s.size();
	DP.assign(  N, vb(8, false));
	prevv.assign(N, vi(8, -1));  // -1 means there is no prevv...

	DP[0][(s[0]-'0')%8] = 1; // no prevv

	for (int i = 1; i < N; ++i) {
		int digit = s[i]-'0';
		DP[i][digit%8] = 1; // no  prevv
		for (int j = 0; j < 8; ++j) {
			if (DP[i-1][j]) {
				DP[i][j] = 1; // skip current digit
				prevv[i][j] = j;

				DP[i][(10*j + digit)%8] = 1; // add current digit
				prevv[i][(10*j + digit)%8] = j;
			}
		}
	}

	if (DP[N-1][0]) {
		cout<<"YES\n";
		print_answer(N-1,0);
		cout<<'\n';
	}
	else
		cout<<"NO\n";
  return 0;
}
