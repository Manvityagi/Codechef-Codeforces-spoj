class Solution {
public:
	string defangIPaddr(string address) {
		string raddress = "";
		for (auto c : address) {
			if (c == '.') {
				raddress += "[.]";
			}
			else {
				raddress += c;
			}
		}
		return raddress;
	}
};
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();