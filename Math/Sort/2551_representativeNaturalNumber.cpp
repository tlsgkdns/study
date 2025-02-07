#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
ll N, A[5000001], s = 0, tmp = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		s += A[i];
	}
	sort(A, A + N);
	s /= N;
	for (int i = 0; i < N; i++) tmp += 2 * A[i] - 2 * s - 1;
	s += (tmp > 0);
	cout << A[(N - 1) / 2] << " " << s << '\n';
}

// https://www.acmicpc.net/problem/2551