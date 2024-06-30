#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;
int N, S, E, T;
mat adj(52, vector<ll>(52));
char ch;
const ll MOD = 1000003;

mat multiply(mat& a, mat& b)
{
	mat ret(52, vector<ll>(52, 0L));
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
		{
			for (int k = 0; k < 52; k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	return ret;
}
mat mulRepeat(int n, mat& m)
{
	if (n == 1) return m;
	if (n % 2 > 0)
	{
		mat tmp = mulRepeat(n - 1, m);
		return multiply(m, tmp);
	}
	mat a = mulRepeat(n / 2, m);
	return multiply(a, a);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S >> E >> T;
	--S; --E;
	for (int n = 0; n < N; n++)
	{
		for (int i = 1; i < 5; i++)
			adj[n * 5 + i][n * 5 + i - 1] = 1;
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			cin >> ch;
			if (ch == '0') continue;
			int n = (ch - '0');
			adj[y * 5][x * 5 + n - 1] = 1;
		}
	mat ans = mulRepeat(T, adj);
	cout << ans[S * 5][E * 5] << '\n';
}

// https://www.acmicpc.net/problem/1533