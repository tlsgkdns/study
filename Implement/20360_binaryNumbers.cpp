#include <iostream>

using namespace std;
int N, idx = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N > 0)
	{
		if (N % 2 > 0) cout << idx << " ";
		idx++;
		N /= 2;
	}
}

// https://www.acmicpc.net/problem/20360