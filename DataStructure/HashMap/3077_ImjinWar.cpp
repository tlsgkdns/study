#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> D;
int N, a1 = 0, a2 = 0;
string C, A[2501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C;
		D[C] = i;
	}
	for (int i = 0; i < N; i++) cin >> A[i];
	a2 = (N * (N - 1)) / 2;
	for (int idx1 = 0; idx1 < N; idx1++)
		for (int idx2 = idx1 + 1; idx2 < N; idx2++)
			if (D[A[idx1]] < D[A[idx2]])
				++a1;
	cout << a1 << "/" << a2 << '\n';
}

// https://www.acmicpc.net/problem/3077