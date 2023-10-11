#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> D;
int N, K, A[10001], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < N - 1; i++)
		D.push_back(A[i + 1] - A[i]);
	sort(D.begin(), D.end());
	for (int i = 0; i < N - K; i++)
		ans += D[i];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2212