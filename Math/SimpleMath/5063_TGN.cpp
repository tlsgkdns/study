#include <iostream>
using namespace std;
int N, R, E, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> R >> E >> C;
		R += C;
		if (R == E) cout << "does not matter\n";
		else if (R < E) cout << "advertise\n";
		else cout << "do not advertise\n";
	}
}

// https://www.acmicpc.net/problem/5063