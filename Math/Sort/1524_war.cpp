#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, T, A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> S;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> A;
			S.push_back({ A, 1 });
		}
		for (int i = 0; i < M; i++)
		{
			cin >> A;
			S.push_back({ A, 0 });
		}
		sort(S.begin(), S.end());
		if (S.back().second == 0) cout << "B\n";
		else cout << "S\n";
	}
}

// https://www.acmicpc.net/problem/1524