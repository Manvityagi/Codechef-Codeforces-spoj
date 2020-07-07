#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> names(n);
	for(int i = 0; i < n; ++i) {
		cin >> names[i];
	}
	sort(names.begin(), names.end());
	int answer = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(names[i][0] == names[j][0] && i % 2 == j % 2) {
				++answer;
			}
		}
	}
	printf("%d\n", answer);
}