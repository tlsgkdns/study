#include <iostream>
#include <vector>
using namespace std;
vector<int> T;
bool ans[1002];
int C, K, a = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	for (int n = 1; a <= 1000; a += n, n++) T.push_back(a);
	for (int i = 1; i < T.size(); i++)
		for (int j = 1; j < T.size(); j++)
			for (int k = 1; k < T.size(); k++)
				if (T[i] + T[j] + T[k] <= 1000)
					ans[T[i] + T[j] + T[k]] = true;
	while (C--)
	{
		cin >> K;
		cout << ans[K] << '\n';
	}
}

// https://www.acmicpc.net/problem/10448