#include <iostream>

using namespace std;
int y = 0, m = 0, C, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C;
		y += ((C / 30) + 1) * 10;
		m += ((C / 60) + 1) * 15;
	}
	if (y > m) cout << "M " << m << '\n';
	else if (y < m) cout << "Y " << y << '\n';
	else cout << "Y M " << y << '\n';
}

// https://www.acmicpc.net/problem/1267