#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N < 0) break;
		int s = 1;
		vector<int> div;
		div.push_back(1);
		for (int i = 2; i * i <= N; i++)
		{
			if (N % i == 0)
			{
				if (i * i != N)
				{
					int d = (N / i);
					s += d;
					div.push_back(d);
				}
				div.push_back(i);
				s += i;
			}
		}
		if (s == N)
		{
			cout << N << " = ";
			sort(div.begin(), div.end());
			for (int i = 0; i < div.size(); i++)
			{
				cout << div[i];
				if (i < div.size() - 1) cout << " + ";
			}
			cout << '\n';
		}
		else
		{
			cout << N << " is NOT perfect.\n";
		}
	}
}

// https://www.acmicpc.net/problem/9506