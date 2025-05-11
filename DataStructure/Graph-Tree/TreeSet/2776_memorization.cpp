#include <iostream>
#include <set>

using namespace std;
int N, M, T, A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		set<int> S;
		cin >> N;
		while (N--)
		{
			cin >> A;
			S.insert(A);
		}
		cin >> M;
		while (M--)
		{
			cin >> A;
			cout << (S.find(A) != S.end()) << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/2776