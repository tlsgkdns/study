#include <iostream>
#include <vector>
using namespace std;

vector<string> input;
vector<bool> ans;

bool isCycle(string& str, int n)
{
	vector<int> number(10, 0);
	for (int i = 0; i < str.size(); i++)
		number[str[i] - '0']++;
	int up = 0, cnt = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		int num = str[i] - '0';
		num *= n; num += up;
		if (number[num % 10] == 0) return false;
		number[num % 10]--;
		up = num / 10;
	}
	return up == 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	while (true)
	{
		cin >> str;
		if (cin.eof()) break;
		input.push_back(str);
		bool a = true;
		for (int n = 1; n <= str.size(); n++)
			if (!isCycle(str, n))
			{
				a = false;
				break;
			}
		ans.push_back(a);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		string cycle = (ans[i]) ? "cyclic\n" : "not cyclic\n";
		cout << input[i] << " is " << cycle;
	}
}

// https://www.acmicpc.net/problem/6373