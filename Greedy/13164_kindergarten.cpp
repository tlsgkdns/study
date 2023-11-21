#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> S;
int N, K, A[300002], M1 = 0, M2 = 0;
bool C[300002];
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N); M1 = A[0]; M2 = A[0];
	for (int i = 1; i < N; i++)
		S.push_back({ A[i - 1] - A[i], i });
	sort(S.begin(), S.end());
	for (int i = 0; i < K - 1; i++) C[S[i].second] = true;
	C[N] = true;
	for (int i = 1; i <= N; i++)
	{
		if (C[i])
		{
			ans += M2 - M1;
			M2 = A[i];
			M1 = A[i];
		}
		else
		{
			M2 = A[i];
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13164