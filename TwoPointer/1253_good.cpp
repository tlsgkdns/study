#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int idx = 0; idx < N; idx++)
	{
		int l = (idx == 0) ? 1 : 0, r = (idx == N - 1) ? N - 2 : N - 1;
		while (l < r)
		{

			int s = arr[l] + arr[r];
			if (s == arr[idx])
			{
				if ((arr[l] == 0 || arr[r] == 0) && (l == idx || r == idx))
				{
					if (l == idx) l++;
					else r--;
					continue;
				}
				ans++;
				break;
			}
			else if (s < arr[idx]) l++;
			else r--;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1253