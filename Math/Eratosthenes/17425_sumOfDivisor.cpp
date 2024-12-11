#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 1000001;
ll E[MAX], T, N, A[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= MAX; i++)
		for (int j = i; j <= MAX; j += i)
			E[j] += i;
	cin >> T; A[0] = 0;
	for (int i = 1; i <= 1000000; i++)
		A[i] = A[i - 1] + E[i];
	while (T--)
	{
		cin >> N;
		cout << A[N] << '\n';
	}
}

// https://www.acmicpc.net/problem/17425