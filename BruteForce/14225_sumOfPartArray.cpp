#include <iostream>

using namespace std;

int N, S[21];
bool v[20000003];
void solve(int idx, int s)
{
	if (idx == N)
	{
		v[s] = true;
		return;
	}
	solve(idx + 1, s);
	solve(idx + 1, s + S[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	solve(0, 0);
	for (int i = 1; i <= 20000001; i++)
		if (!v[i])
		{
			cout << i << '\n';
			break;
		}
}

// https://www.acmicpc.net/problem/14225