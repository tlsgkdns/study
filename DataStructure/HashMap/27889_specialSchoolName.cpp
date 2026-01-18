#include <iostream>
#include <unordered_map>

using namespace std;
string S;
unordered_map<string, string> um = { {"NLCS", "North London Collegiate School"}, {"BHA", "Branksome Hall Asia"}, {"KIS", "Korea International School"}, {"SJA", "St. Johnsbury Academy"} };
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> S;
    cout << um[S] << '\n';
}

// https://www.acmicpc.net/problem/27889