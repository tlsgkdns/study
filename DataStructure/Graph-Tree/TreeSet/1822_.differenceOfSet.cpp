#include <iostream>
#include <set>
using namespace std;

set<int> S, ans;
int N, M, A, B;

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
		if (S.find(B) != S.end()) S.erase(B);
	}
	cout << S.size() << '\n';
	for (const int& a : S) cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1822