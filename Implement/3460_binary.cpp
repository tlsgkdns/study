#include <iostream>
#include <vector>

using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int cnt = 0;
		vector<int> b;
		while (N > 0)
		{
			if (N % 2 > 0) b.push_back(cnt);
			N /= 2;
			++cnt;
		}
		for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/3460