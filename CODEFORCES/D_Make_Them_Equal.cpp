#include <bits/stdc++.h> 
using namespace std; 

string LexicographicalMaxString(string str) 
{ 
	char maxchar = 'a'; 
	vector<int> index; 

	for (int i = 0; i < str.length(); i++) { 
		if (str[i] >= maxchar) { 
			maxchar = str[i]; 
			index.push_back(i); 
		} 
	} 
	string maxstring = ""; 

	for (int i = 0; i < index.size(); i++) { 
		if (str.substr(index[i], str.length()) > maxstring) { 
			maxstring = str.substr(index[i], str.length()); 
		} 
	} 
	return maxstring; 
} 

int main() 
{ 
	string str = "acbacbc"; 
	cout << LexicographicalMaxString(str); 
	return 0; 
} 
