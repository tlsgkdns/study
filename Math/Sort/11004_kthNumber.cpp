#include <iostream>
#include <algorithm>

using namespace std;
int N, K, A[5000001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	cout << A[K - 1] << '\n';
}

// https://www.acmicpc.net/problem/11004