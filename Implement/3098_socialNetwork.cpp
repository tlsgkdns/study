#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> K;
int N, M, A, B;
vector<int> F[51];
bool adj[51][51], H[51][51], connected[51][51], connecting[51][51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		connected[A][B] = true;
		connected[B][A] = true;
	}
	while (true)
	{
		int c = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				c += connected[i][j];
		if (c == N * (N - 1)) break;
		memset(connecting, false, sizeof(connecting));
		int C = 0;
		for (int here = 1; here <= N; here++)
		{
			for (int mid = 1; mid <= N; mid++)
			{
				if (!connected[here][mid] || connecting[here][mid]) continue;
				for (int there = 1; there <= N; there++)
				{
					if (here == there || connected[here][there] || mid == there
						|| !connected[mid][there] || connecting[mid][there] || connecting[here][there]) continue;
					connecting[here][there] = true;
					connecting[there][here] = true;
					++C;
				}
			}
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (connecting[i][j])
					connected[i][j] = true;
		K.push_back(C);
	}
	cout << K.size() << '\n';
	for (int i = 0; i < K.size(); i++) cout << K[i] << '\n';
}

// https://www.acmicpc.net/problem/3098