#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		int sq = sqrt(N), a = 0;
		for (int i = 1; i <= sq; i++)
		{
			if (i * i == N)
			{
				a++;
				break;
			}
			for (int j = i; j <= sq; j++)
			{
				if ((i * i + j * j) == N)
				{
					a++;
					break;
				}
				for (int k = j; k <= sq; k++)
				{
					if (i * i + j * j + k * k == N)
					{
						a++;
						break;
					}
					for (int l = k; l <= sq; l++)
					{
						if (i * i + j * j + k * k + l * l == N)
						{
							a++;
							break;
						}
						else if (i * i + j * j + k * k + l * l > N)
							break;
					}
				}
			}
		}
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/3933