#include <iostream>
#include <set>
using namespace std;

set<int> S;
int A, B, N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		S.insert(A);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> B;
		if (S.find(B) != S.end())
			S.erase(B);
		else
			S.insert(B);
	}
	cout << S.size() << '\n';
}

// https://www.acmicpc.net/problem/1269