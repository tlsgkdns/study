#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	string tmp;
	vector<string> input;

	do
	{
		getline(cin, tmp);
		if (tmp == "EOI") break;
		transform(tmp.begin(), tmp.end(), tmp.begin(),
			[](unsigned char c) {return tolower(c); });
		input.push_back(tmp);
	} while (true);

	for (string s : input)
	{
		string::size_type it = s.find("nemo");
		if (it != string::npos && ((it + 3) == string::npos || !isalpha(s[it + 4])) && (it == 0 || !isalpha(s[it - 1])))
		{
			cout << "Found" << '\n';
		}
		else
		{
			cout << "Missing" << '\n';
		}

	}

	return 0;
}

// https://www.acmicpc.net/problem/10173