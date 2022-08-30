#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const string NO = "NO", init = "INIT";

string str, submarine = "100~1~";
unordered_map<string, vector<string>> um;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	um[init] = { "0", "1" };
	um["1"] = { "10", NO };
	um["10"] = { "100", NO };
	um["100"] = { "100~", "100~1" };
	um["100~"] = { "100~", "100~1" };
	um["100~1"] = { "0", "100~1~" };
	um["100~1~"] = { "10 or 0", "100~1~" };
	um["0"] = { NO, "01" };
	um["01"] = { "0", "1" };
	um["10 or 0"] = { "100", "01" };
	string state = init;
	for (char c : str)
	{
		int n = c - '0';
		state = um[state][n];
		if (state == NO) break;
	}
	if (state == "100~1" || state == "100~1~" || state == "01")
		cout << "SUBMARINE\n";
	else
		cout << "NOISE\n";
}

// https://www.acmicpc.net/problem/2671