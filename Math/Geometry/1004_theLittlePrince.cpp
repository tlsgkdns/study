#include <iostream>
#include <vector>
using namespace std;
int t, n;
int a1, b1, a2, b2, a, b, r;
vector<int> v;
bool inside(int a1, int b1, int a2, int b2, int rd)
{
	int r2 = rd * rd;
	int dist = (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2);
	return dist < r2;
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int ans = 0;
		cin >> a1 >> b1 >> a2 >> b2;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> a >> b >> r;
			bool ins1 = inside(a1, b1, a, b, r);
			bool ins2 = inside(a2, b2, a, b, r);
			if (ins1 && ins2) continue;
			if (ins1 || ins2) ans++;
		}
		v.push_back(ans);
	}
	for (int a : v) cout << a << '\n';
}