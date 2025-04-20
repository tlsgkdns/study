#include <iostream>

using namespace std;

long long R, W, L, cnt = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> R;
		if (R == 0) break;
		R *= 2;
		cin >> W >> L;
		cout << "Pizza " << cnt++ << " ";
		if (W * W + L * L <= R * R) cout << "fits on the table.\n";
		else cout << "does not fit on the table.\n";
	}
}

// https://www.acmicpc.net/problem/6502