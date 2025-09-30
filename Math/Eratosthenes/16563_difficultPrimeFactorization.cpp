#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, P[5000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, -1, sizeof(P));
	cin >> N;
	for (int i = 2; i * i <= 5000000; i++)
	{
		if (P[i] < 0)
			for (int j = i + i; j <= 5000000; j += i)
				P[j] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		vector<int> ans;
		while (P[K] > 0)
		{
			ans.push_back(P[K]);
			K /= P[K];
		}
		ans.push_back(K);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16563