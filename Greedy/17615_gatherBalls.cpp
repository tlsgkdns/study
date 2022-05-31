#include <iostream>
#include <algorithm>
using namespace std;

string ball;
char head, tail;
int N, R = 0, B = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> ball;
	head = ball[0]; tail = ball.back();
	for (int i = 0; i < N; i++)
	{
		if (ball[i] == 'R') R++;
		else B++;
	}
	int idx = 0, ans = 500001;
	while (head == ball[idx]) idx++;
	if (head == 'R') ans = min(R - idx, B);
	else ans = min(R, B - idx);
	idx = N - 1;
	while (tail == ball[idx]) idx--;
	if (tail == 'R') ans = min(ans, min(R - (N - idx) + 1, B));
	else ans = min(ans, min(R, B - (N - idx) + 1));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17615