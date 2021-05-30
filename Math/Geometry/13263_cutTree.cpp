#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 100000;
struct Line
{
	ll a, b;
	double s;

	Line(ll a_, ll b_, ll s_ = 0) : a(a_), b(b_), s(s_) {}
};

double cross(const Line& f, const Line& g)
{
	return (g.b - f.b) / (f.a - g.a);
}
int h[MAX], c[MAX], n;
vector<Line> s;
long long dp[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	for (int i = 1; i < n; i++)
	{
		Line g(c[i - 1], dp[i - 1]);

		while (!s.empty())
		{
			g.s = cross(g, s.back());
			if (g.s < s.back().s)
				s.pop_back();
			else
				break;
		}
		s.push_back(g);
		ll x = h[i];
		int fpos = 0;
		int left = 0, right = s.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (s[mid].s < x)
			{
				fpos = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		dp[i] = s[fpos].a * x + s[fpos].b;
	}
	cout << dp[n - 1] << '\n';
}

// https://www.acmicpc.net/problem/13263