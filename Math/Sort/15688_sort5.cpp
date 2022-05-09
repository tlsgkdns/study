#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> ar;
int N, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		ar.push_back(num);
	}
	sort(ar.begin(), ar.end());
	for (int i = 0; i < N; i++) cout << ar[i] << '\n';
}

// https://www.acmicpc.net/problem/15688