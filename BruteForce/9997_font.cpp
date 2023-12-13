#include <iostream>
using namespace std;

int N, W[25], F = (1 << 26) - 1;
string S;
int getBit(string& str)
{
	int ret = 0;
	for (int i = 0; i < str.size(); i++)
		ret |= (1 << (str[i] - 'a'));
	return ret;
}

int solve(int idx, int n)
{
	if (idx == N) return (n == F);
	int ret = solve(idx + 1, n) + solve(idx + 1, (W[idx] | n));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		W[i] = getBit(S);
	}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/9997