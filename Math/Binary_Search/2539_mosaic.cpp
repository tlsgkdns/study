#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, K, N, Y, X, l = 0, r;
vector<int> paper;
bool canFill(int leng)
{
	int s = 0;
	for (int i = 0; i < N;)
	{
		int now = paper[i];
		s++;
		while (i < N && now + leng - 1 > paper[i])
			i++;
	}
	return s <= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> K >> N;
	r = R;
	for (int i = 0; i < N; i++)
	{
		cin >> Y >> X;
		l = max(Y, l);
		paper.push_back(X);
	}
	sort(paper.begin(), paper.end());
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (canFill(m)) r = m;
		else l = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/2539