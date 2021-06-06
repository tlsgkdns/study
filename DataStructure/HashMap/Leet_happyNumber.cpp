#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	unordered_map<long long, bool> um;
	long long sumOfDigit(int n)
	{
		long long sum = 0;
		while (n != 0)
		{
			int a = n % 10;
			sum += (a * a);
			n /= 10;
		}
		return sum;
	}
	bool isHappy(int n) {
		bool ans = true;
		while (n != 1)
		{
			if (um.count(n) != 0)
			{
				ans = false;
				break;
			}
			um.insert({ n, true });
			n = sumOfDigit(n);
		}
		return ans;
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	cout << s.isHappy(n) << '\n';
}

// https://leetcode.com/problems/happy-number/