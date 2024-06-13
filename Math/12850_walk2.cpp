#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;
int D = 0;
const ll MOD = 1000000007;
mat arr = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

mat multiply(mat& a, mat& b)
{
	mat ret(8, vector<ll>(8, 0L));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
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
	cin >> D;
	mat ans = mulRepeat(D, arr);
	cout << ans[0][0] << '\n';
}

// https://www.acmicpc.net/problem/12850