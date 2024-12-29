#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, A[300001], S[300001];
unordered_map<int, bool> um;
bool ans = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		um[A[i]] = (i % 2);
	}
	sort(A, A + N);
	for (int i = 0; i < N; i++)
	{
		if (um[A[i]] != (i % 2))
		{
			ans = false;
			break;
		}
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/20309