#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
void reverse_str(char* begin,char* end) {
	while (begin < end) {
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
	
}
 
void reverse_changge(char* src) {
	reverse_str(src, src + strlen(src) - 1);
	char* begin = src;
	char* end = src;
	while (*src) {
		if (*src != ' ') {
			 begin = src;
			while (*src != ' '&&*src) {
				src++;
			}
			src = src - 1;
			end = src ;
			reverse_str(begin, end);
		}
		src++;
	}
}
 
int main() {
	char str[100] = { 0 };
	int i = 0;
	while (1) {
		str[i]= getchar();
		if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}
		i++;
	}
	reverse_change(str);
	cout << str << endl;
	system("pause");
	return 0;
}
