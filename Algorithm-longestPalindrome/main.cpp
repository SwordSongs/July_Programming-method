#include<iostream>
#include<string>
using namespace std;

int longestPalindrome(string s) {
	if (s.length() == 0)
		return 0;
	int max = 0;
	int count = 0;
	int len = static_cast<int>(s.length());

	for (int i = 0; i < len;++i) {       //i�����ĵ㣬����������
		for (int j = 0; (i-j >= 0) && (i + j < len); ++j) {      //���ĳ���Ϊ����
			//ע�� ��i��jΪsize_t���ͣ��ᵼ��i-j�����0
			if (s[i - j] != s[i + j])  
				break;
			count = j * 2 + 1;
		}

		if (count > max)
			max = count;

		for (int j = 0; (i - j) >= 0 && (i + j + 1 < len); ++j) {   //���ĳ�����ż��
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
	cout << "����ĳ���Ϊ�� " << max << endl;
	system("pause");
	return 0;
}