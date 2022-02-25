#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, T, num, tmp1, tmp2;
vector<vector<int>> ls, ans;
vector<int> arr, arr2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> num;
		arr.push_back(num);
		arr2.push_back(num);
	}
	reverse(arr2.begin(), arr2.end());
	for (int i = 0; i < L; i++)
		arr2[i] = (arr2[i] > 2) ? arr2[i] - 2 : arr2[i] + 2;
	ls.push_back(arr); ls.push_back(arr2);
	for (int i = 0; i < L - 1; i++)
	{
		tmp1 = arr[0]; tmp2 = arr2[0];
		for (int j = 1; j < L; j++)
		{
			arr[j - 1] = arr[j];
			arr2[j - 1] = arr2[j];
		}
		arr[L - 1] = tmp1; arr2[L - 1] = tmp2;
		ls.push_back(arr); ls.push_back(arr2);
	}
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		vector<int> vc;
		for (int i = 0; i < L; i++)
		{
			cin >> num;
			vc.push_back(num);
		}
		for (int i = 0; i < ls.size(); i++)
		{
			bool same = true;
			for (int j = 0; j < L; j++)
				if (vc[j] != ls[i][j])
				{
					same = false;
					break;
				}
			if (same) ans.push_back(ls[i]);
		}
	}
	cout << (int)ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++)
	{
		for (int j = 0; j < L; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}

}

// https://www.acmicpc.net/problem/2641