#include <iostream>
#include <string>
using namespace std;
string N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == "0") break;
		while (N.size() > 1)
		{
			int s = 0;
			for (int i = 0; i < N.size(); i++) s += (N[i] - '0');
			N = to_string(s);
		}
		cout << N << '\n';
	}
}

// https://www.acmicpc.net/problem/6378