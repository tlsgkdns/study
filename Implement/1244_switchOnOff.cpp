#include <iostream>
#include <vector>

using namespace std;

vector<bool> swtch;

int main()
{
	int n, cmd;
	cin >> n;
	swtch.resize(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		swtch[i] = (tmp == 0) ? false : true;
	}
	cin >> cmd;
	vector<pair<int, int>> student(cmd);

	for (int j = 0; j < cmd; j++)
	{
		int a, b;
		cin >> a >> b;
		student.push_back(make_pair(a, b));
	}

	for (pair<int, int> s : student)
	{
		if (s.second == n)
		{
			swtch[n] = !swtch[n];
			continue;
		}
		if (s.first == 1)
		{
			int mul = s.second;
			for (int num = mul; num <= n; num += mul)
				swtch[num] = !swtch[num];
		}
		if (s.first == 2)
		{
			int cen = s.second;

			if (cen == 1 || cen == n)
			{
				swtch[cen] = !swtch[cen];
				continue;
			}

			int l = cen - 1;	int r = cen + 1;
			while (l > 0 && r < n + 1)
			{
				if (swtch[l] == swtch[r])
				{
					l--;
					r++;
				}
				else
					break;
			}

			for (int i = l + 1; i <= r - 1; i++)
				swtch[i] = !swtch[i];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << swtch[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}

	return 0;
}

// https://www.acmicpc.net/problem/1244