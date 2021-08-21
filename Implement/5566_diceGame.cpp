#include <iostream>
#include <vector>

using namespace std;

vector<int> board, dice;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, pos = 0, ans = 0;
	cin >> N >> M;
	board.resize(N); dice.resize(M);
	for (int i = 0; i < N; i++) cin >> board[i];
	for (int i = 0; i < M; i++) cin >> dice[i];
	while (pos < N - 1)
	{
		pos += dice[ans];
		ans++;
		if (pos >= N - 1) break;
		pos += board[pos];
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/5566