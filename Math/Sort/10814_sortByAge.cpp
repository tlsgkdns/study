#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, age;
string name;
vector<pair<int, pair<int, string>>> member;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		member.push_back({ age, {i, name} });
	}
	sort(member.begin(), member.end());
	for (int i = 0; i < N; i++)
		cout << member[i].first << " " << member[i].second.second << '\n';
}

// https://www.acmicpc.net/problem/10814