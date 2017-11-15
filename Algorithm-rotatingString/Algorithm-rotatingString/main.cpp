#include<iostream>
#include<string>
using namespace std;

//void leftShiftOne(string& s) {
//	char temp = s[0];
//	size_t length = s.length();
//	for (int i = 1; i < length; ++i) {
//		s[i - 1] = s[i];
//	}
//
//	s[length - 1] = temp;
//}
//
//void reverseM(string& s, int m) {
//	while (m--) {
//		leftShiftOne(s);
//	}
//}

//void reverseString(string& s, int from ,int to){
//	char temp;
//	while (from < to) {
//		temp = s[from];
//		s[from++] = s[to];
//		s[to--] = temp;
//	}
//}
//
//void leftReverseString(string& s, int m) {
//	
//	size_t length = s.length();
//	m %= length;
//	reverseString(s,0,m-1);
//	reverseString(s,m,length-1);
//	reverseString(s,0,length-1);
//}
//
//void exercise_1(string& s,int m) {
//	size_t length = s.length();
//	m %= length;
//	reverseString(s,0, m - 1);
//	reverseString(s,m,length-1);
//}

//void reverseString(string& s, int from, int to) {
//	char temp;
//	while (from < to) {
//		temp = s[from];
//		s[from++] = s[to];
//		s[to--] = temp;
//	}
//}
//
//void exercise_2(string& s,int m) {
//	size_t length = s.length();
//	if (m > length) {
//		cout << "m>n" << endl;
//		return;
//	}
//	reverseString(s,0,length-m-1);
//	reverseString(s,length-m,length-1);
//	reverseString(s,0,length-1);
//}

void reverseString(string& s, int from, int to) {  //核心翻转操作
	char temp;
	while (from < to) {
		temp = s[from];
		s[from++] = s[to];
		s[to--] = temp;
	}
}

void exercise_3(string& s) {
	int p = 0, q = 0;
	size_t length = s.length();
	for (; q < (int)length; ++q) {
		if (s[q] == ' ' ) {
			reverseString(s, p, q - 1);
			while (s[q] == ' ') {
				++q;
				if (s[q] != ' ') {
					break;
				}
			}
			p = q;
		}
		if (q == length-1) {
			reverseString(s, p, q);
		}

	}
	reverseString(s, 0, length - 1);
}

void wanmeikaoti(string& str) {
	int left = 0;
	int right = (int)str.length()-1;

	while (str[left] == ' ') {
		++left;
	}

	while (str[right] == ' ') {
		--right;
	}
	//cout << str.length() << endl;
	//cout << left << "   " << right << endl;
	str.erase(0,left);
	str.erase(right+1-left,str.length()-1-right+left);
	//cout << str.length() << endl;

	cout << "处理的字符串密文为： " << str << endl;
	size_t i = 0, j = 0;
	for (; j < str.length(); ++j) {
		if (str[j] == ' ') {
			reverseString(str, i, j - 1);
			while (str[j] == ' ') {
				++j;
				if (str[j] != ' ') {
					break;
				}
			}
			i = j;
		}
		
		if (j == str.length() - 1) {
			reverseString(str,i,j);
		}
	}

	reverseString(str,0,str.length()-1);
}


class A {};
void f(const A** p) {};
void g(const A* const *p) {};
void k(const A* &p) {};

int main() {
	////string str = "123456";
	//string str_2 = "Ilovebaofeng";
	//string str_3 = "I am a student.";
	////exercise_1(str,2);
	////exercise_2(str_1,7);
	//exercise_3(str_3);
	//cout << str_3 << endl;
	string miwen = "   1 5721    23      ";
	//翻译为"23    5721 1"
	wanmeikaoti(miwen);
	cout << miwen << endl;

	
	system("pause");
	return 0;
}