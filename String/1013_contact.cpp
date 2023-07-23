#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
const string B = "B";
unordered_map<string, vector<string>> um;
string str;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	um[""] = { "0", "1" };
	um["1"] = { "10", B };
	um["10"] = { "100", B };
	um["100"] = { "100", "100+1" };
	um["100+"] = { "100+", "100+1" };
	um["100+1"] = { "0", "100+1+" };
	um["100+1+"] = { "Both", "100+1+" };
	um["0"] = { B, "01" };
	um["01"] = { "0", "1" };
	um["Both"] = { "100", "01" };
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		string state = "";
		for (int idx = 0; idx < str.size(); idx++)
		{
			state = um[state][str[idx] - '0'];
			if (state == B) break;
		}
		if (state == "100+1+" || state == "100+1" || state == "01")
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

// https://www.acmicpc.net/problem/1013