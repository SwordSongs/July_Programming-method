#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//O(n*n)
int longestPalindrome(string s) {
	if (s.length() == 0)
		return 0;
	int max = 0;
	int count = 0;
	int len = static_cast<int>(s.length());

	for (int i = 0; i < len; ++i) {       //i是中心点，向两边延伸
		for (int j = 0; (i - j >= 0) && (i + j < len); ++j) {      //回文长度为奇数
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

//马拉车算法，O(n)
int Manacher(string s) {
	//transform
	int len = static_cast<int>(s.length());
	char* string = new char[2 * len + 3];

	for (int i = 0, index = 0; (i < 2 * len + 2); ++i) {  //aba -- $#a#b#a#,$处理边界
		if (0 == i)
			string[0] = '$';
		else if (i % 2 == 1)
			string[i] = '#';
		else {
			string[i] = s[index];
			++index;
		}

	}
	string[2 * len + 2] = '\0';   //字符串边界，重要

	//处理部分
	int newLen = 2 * len + 2;
	int maxLen = -1;

	int id;                //回文中心位置
	int mx = 0;            //id + P[id],回文子串边界
	int *p = new int[newLen];

	for (int i = 1; i < newLen; ++i) {
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;

		while (string[i - p[i]] == string[i + p[i]])  //不需边界判断，左'$',右'\0'
			p[i]++;

		if (mx < i + p[i]) {   //每走一步i，都要和mx比较，我们希望mx尽可能远，这样才更有机会执行if(i < mx),
			id = i;            //从而提高效率
			mx = i + p[i];
		}

		maxLen = max(maxLen,p[i]-1);
	}

	

	delete[] string;
	delete[] p;
	return maxLen;
}

int main() {
	string s;
	cout << "input string: " << endl;
	cin >> s;
	int max;
	//max = longestPalindrome(s);
	max = Manacher(s);
	cout << "最长回文长度为： " << max << endl;
	
	system("pause");
	return 0;
}