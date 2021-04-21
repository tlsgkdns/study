#include <iostream>
#include <vector>
using namespace std;
using p = pair<int, int>;
vector<vector<int>> quad;
string ans;
int n;
void compress(p s, p e)
{
	int a = quad[s.first][s.second]; bool b = false;
	for (int i = s.first; i <= e.first; i++)
		for (int j = s.second; j <= e.second; j++)
		{
			int c = i, d = j;
			if (a != quad[i][j])
			{
				b = true;
				break;
			}
		}

	if (!b)
	{
		ans.push_back(a);
		return;
	}
	int hy = (s.first + e.first) / 2; int hx = (s.second + e.second) / 2;
	ans.push_back('(');
	compress(s, make_pair(hy, hx));
	compress(make_pair(s.first, hx + 1), make_pair(hy, e.second));
	compress(make_pair(hy + 1, s.second), make_pair(e.first, hx));
	compress(make_pair(hy + 1, hx + 1), e);
	ans.push_back(')');
}
int main()
{
	cin >> n; quad.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < n; j++)
			quad[i][j] = line[j];
	}
	compress(make_pair(0, 0), make_pair(n - 1, n - 1));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1992