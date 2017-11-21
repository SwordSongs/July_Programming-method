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

	for (int i = 0; i < len; ++i) {       //i�����ĵ㣬����������
		for (int j = 0; (i - j >= 0) && (i + j < len); ++j) {      //���ĳ���Ϊ����
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

//�������㷨��O(n)
int Manacher(string s) {
	//transform
	int len = static_cast<int>(s.length());
	char* string = new char[2 * len + 3];

	for (int i = 0, index = 0; (i < 2 * len + 2); ++i) {  //aba -- $#a#b#a#,$����߽�
		if (0 == i)
			string[0] = '$';
		else if (i % 2 == 1)
			string[i] = '#';
		else {
			string[i] = s[index];
			++index;
		}

	}
	string[2 * len + 2] = '\0';   //�ַ����߽磬��Ҫ

	//������
	int newLen = 2 * len + 2;
	int maxLen = -1;

	int id;                //��������λ��
	int mx = 0;            //id + P[id],�����Ӵ��߽�
	int *p = new int[newLen];

	for (int i = 1; i < newLen; ++i) {
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;

		while (string[i - p[i]] == string[i + p[i]])  //����߽��жϣ���'$',��'\0'
			p[i]++;

		if (mx < i + p[i]) {   //ÿ��һ��i����Ҫ��mx�Ƚϣ�����ϣ��mx������Զ�������Ÿ��л���ִ��if(i < mx),
			id = i;            //�Ӷ����Ч��
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
	cout << "����ĳ���Ϊ�� " << max << endl;
	
	system("pause");
	return 0;
}