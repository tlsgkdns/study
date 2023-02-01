#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[4001], B[4001], C[4001], D[4001];
long long ans = 0;
vector<int> S1, S2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			S1.push_back(A[i] + B[j]);
			S2.push_back(C[i] + D[j]);
		}
	sort(S1.begin(), S1.end()); sort(S2.begin(), S2.end());
	for (int i = 0; i < S1.size(); i++)
		ans += upper_bound(S2.begin(), S2.end(), -S1[i]) - lower_bound(S2.begin(), S2.end(), -S1[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/7453