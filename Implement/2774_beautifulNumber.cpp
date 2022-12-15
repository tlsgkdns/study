#include <iostream>
#include <cstring>
using namespace std;

int T, X;
bool num[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int s = 0;
		memset(num, false, sizeof(num));
		cin >> X;
		while (X > 0)
		{
			if (!num[X % 10])
			{
				s++;
				num[X % 10] = true;
			}
			X /= 10;
		}
		cout << s << '\n';
	}
}

// https://www.acmicpc.net/problem/2774