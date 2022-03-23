#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int stud[101], order[101];
int N, T, num, cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(order, -1, sizeof(order));
	cin >> N >> T;
	order[0] = 1001; stud[0] = 1001;
	for (int i = 0; i < T; i++)
	{
		cin >> num;
		if (stud[num] == 0 && cnt == N)
		{
			int idx = 0;
			for (int n = 1; n <= 100; n++)
			{
				if (stud[n] == 0 || stud[idx] < stud[n]) continue;
				if (stud[idx] == stud[n] && order[idx] < order[n])
					continue;
				idx = n;
			}
			stud[num] = 1;
			order[num] = i;
			stud[idx] = 0;
			order[idx] = -1;
		}
		else
		{
			if (stud[num] == 0)
			{
				cnt++;
				order[num] = i;
			}
			stud[num]++;
		}
	}
	for (int i = 1; i <= 100; i++)
		if (stud[i] != 0)
			cout << i << " ";
	cout << '\n';
}

//https://www.acmicpc.net/problem/1713