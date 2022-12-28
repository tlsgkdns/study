#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int N, S;
int solve(int idx, int sum, bool fulled)
{
	if (idx == N)
	{
		return (fulled && sum == S);
	}

	int ret = 0;
	ret = solve(idx + 1, sum + arr[idx], true) + solve(idx + 1, sum, fulled);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << solve(0, 0, false) << '\n';
}

// https://www.acmicpc.net/problem/1182