#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void allPermytation(string s, int from, int to) {
	if (to <= 0)             //ab ba
		return;
	if (from == to) {       //�����ݹ�
		for (int i = 0; i <= to; ++i) {
			cout << s[i];
		}
		cout << endl;
	}
	else {
		for (int j = from; j <= to; ++j) {
			swap(s[j], s[from]);
			allPermytation(s, from + 1, to);
			swap(s[j], s[from]);
		}
	}
}

int main() {
	string s;
	cout << "��������Ҫȫ���еĵ��ʣ� " << endl;
	cin >> s;
	cout << "���ʣ� "<<s<< " ��ȫ����Ϊ��" << endl;
	allPermytation(s, 0, s.length()-1);
	system("pause");
	return 0;
}