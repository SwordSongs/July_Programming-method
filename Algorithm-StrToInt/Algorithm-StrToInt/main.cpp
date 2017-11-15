#include<iostream>
#include<string>
using namespace std;

enum Status {kValid = 0,kInvalid};
int g_Status = kValid;

long long strToIntCore(const char* digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			if (!minus && num > 0x7FFFFFFF
				|| minus && num < (int)0x80000000)
			{
				num = 0;
				break;
			}

			++digit;
		}
		else
		{
			num = 0;
			break;
		}

	}

	if (*digit == '\0')
	{
		g_Status = kValid;
	}

	return num;
}


int strToInt(const char* s) 
{
	g_Status = kInvalid;
	long long num = 0;

	if (s != NULL && *s != '\0') 
	{
		bool minus = false;
		if (*s == '+') 
		{
			++s;
		}
		else if (*s == '-') 
		{
			++s;
			minus = true;
		}

		if (*s != '\0')
		{
			num = strToIntCore(s,minus);
		}
	}

	return (int)num;
}




//int strToInt(string s) {
//	int result = 0;
//	for (size_t i = 0; i < s.length(); ++i) {
//		result *= 10;
//		result += (s[i] - '0');
//	}
//
//	return result;
//}


int main() {
	char* str = "w";
	int d = strToInt(str);
	cout <<"×Ö·û´®"<<str<<"×ª»»Êý×ÖÎª£º "<< d << endl;

	system("pause");
	return 0;
}