#include<iostream>
#include<string>
using namespace std;

int longestPalindrome(string s) {
	if (s.length() == 0)
		return 0;
	int max = 0;
	int count = 0;
	int len = static_cast<int>(s.length());

	for (int i = 0; i < len;++i) {       //i是中心点，向两边延伸
		for (int j = 0; (i-j >= 0) && (i + j < len); ++j) {      //回文长度为奇数
			//注： 当i，j为size_t类型，会导致i-j恒大于0
			if (s[i - j] != s[i + j])  
				break;
			count = j * 2 + 1;
		}

		if (count > max)
			max = count;

		for (int j = 0; (i - j) >= 0 && (i + j + 1 < len); ++j) {   //回文长度是偶数
			if (s[i - j] != s[i + j + 1]) 
				break;
			count = j * 2 + 2;
		}

		if (count > max)
			max = count;
		
	}

	return max;
}

int main() {
	string s;
	cout << "input string: " << endl;
	cin >> s;
	int max = longestPalindrome(s);
	cout << "最长回文长度为： " << max << endl;
	system("pause");
	return 0;
}