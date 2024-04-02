#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
stack<string> L, W;
vector<string> order;
string T;
int N;

bool cmp(string& n1, string& n2)
{
	if (n1[0] != n2[0]) return n1[0] < n2[0];
	return stoi(string(n1.begin() + 2, n1.end())) < stoi(string(n2.begin() + 2, n2.end()));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
		{
			cin >> T;
			order.push_back(T);
		}
	for (int i = order.size() - 1; i >= 0; i--) L.push(order[i]);
	sort(order.begin(), order.end(), cmp);
	for (int i = 0; i < order.size(); i++)
	{
		if (!W.empty() && W.top() == order[i])
		{
			W.pop();
			continue;
		}
		while (!L.empty() && L.top() != order[i])
		{
			W.push(L.top());
			L.pop();
		}
		if (!L.empty() && L.top() == order[i]) L.pop();
	}
	if (W.empty() && L.empty()) cout << "GOOD\n";
	else cout << "BAD\n";
}

// https://www.acmicpc.net/problem/17178