#include <iostream>
#include <queue>
using namespace std;

int C[22], N, K;
long long ans = 0;
queue<string> q;
string F;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> F;
		ans += C[F.size()];
		if (q.size() == K)
		{
			--C[q.front().size()];
			q.pop();
		}
		++C[F.size()];
		q.push(F);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3078