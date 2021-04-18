#include <unordered_map>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
	unordered_map<string, bool> room;
	int n;

	cin >> n;

	string name, state;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> state;
		auto f = room.find(name);
		if (f == room.end())
		{
			if (state == "enter")
				room.insert(unordered_map<string, bool>::value_type(name, true));
			else
				room.insert(unordered_map<string, bool>::value_type(name, false));
		}
		else
		{
			if (state == "enter")
				f->second = true;
			else
				f->second = false;
		}
	}
	vector<string> people;

	for (auto it : room)
		if (it.second)
			people.push_back(it.first);

	sort(people.begin(), people.end(), greater<string>());

	for (string p : people) cout << p << '\n';
	return 0;
}

//https://www.acmicpc.net/problem/7785