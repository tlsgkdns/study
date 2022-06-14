#include <complex>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpdb = complex<double>;

const double PI = acos(-1);
string A, B;
ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}


void FFT(vector<cpdb>& p, cpdb w)
{
	int n = p.size();
	if (n == 1) return;

	vector<cpdb> even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++)
	{
		if (i % 2) odd[i >> 1] = p[i];
		else even[i >> 1] = p[i];
	}

	FFT(even, w * w); FFT(odd, w * w);
	cpdb cw(1, 0);
	for (int i = 0; i < (n / 2); i++)
	{
		p[i] = even[i] + cw * odd[i];
		p[i + n / 2] = even[i] - cw * odd[i];
		cw *= w;
	}
}

vector<cpdb> mul(vector<cpdb>& a, vector<cpdb>& b)
{
	int n = 1;
	while (n < a.size() || n < b.size()) n <<= 1;
	n <<= 1;

	a.resize(n), b.resize(n);
	cpdb w(cos(2 * PI / n), sin(2 * PI / n));
	FFT(a, w); FFT(b, w);

	vector<cpdb> c(n);
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

	cpdb rw(cos(-2 * PI / n), sin(-2 * PI / n));
	FFT(c, rw);
	for (int i = 0; i < n; i++) c[i] /= n;
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<cpdb> a, b;
	cin >> A >> B;
	for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
	for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');
	vector<cpdb> c = mul(a, b);
	vector<int> res(c.size());
	for (int i = 0; i < c.size(); i++)
		res[i] = (int)(c[i].real() + 0.5);
	for (int i = 0; i + 1 < res.size(); i++)
	{
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	while (!res.empty() && res.back() == 0) res.pop_back();
	if (res.empty()) res.push_back(0);
	reverse(res.begin(), res.end());

	for (int x : res) cout << x;
	cout << '\n';
}

// https://www.acmicpc.net/problem/15576