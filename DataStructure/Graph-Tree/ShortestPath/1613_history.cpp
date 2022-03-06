#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000;
int adj1[401][401], adj2[401][401];
int N, K, S, A, B;
vector<int> ans;
int main()
{
	for (int i = 0; i <= 400; i++)
		for (int j = 0; j <= 400; j++)
		{
			adj1[i][j] = MAX;
			adj2[i][j] = MAX;
		}
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A >> B;
		adj1[A][B] = 1;
		adj2[B][A] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				adj1[i][j] = min(adj1[i][j], adj1[i][k] + adj1[k][j]);
				adj2[i][j] = min(adj2[i][j], adj2[i][k] + adj2[k][j]);
			}
	cin >> S;
	for (int i = 0; i < S; i++)
	{
		cin >> A >> B;
		if (adj1[A][B] < MAX)
			ans.push_back(-1);
		else if (adj2[A][B] < MAX)
			ans.push_back(1);
		else
			ans.push_back(0);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1613