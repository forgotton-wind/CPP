#include <iostream>
#include <cstring>
#include <cstdlib> 
using std::cin;
using std::cout;
using std::endl;
using std::malloc;
using std::strcmp;

int main()
{
	char** s = (char**)malloc(5 * sizeof(char*));
	for (int i = 0; i < 5; i++) {
		s[i] = (char*)malloc(20 * sizeof(char));
	}
	cout << "������5���ַ���" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}
	char* t = NULL;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4-i; j++) {
			if (strcmp(s[j], s[j + 1]) > 0) {
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
	cout << "����õ��ַ���������ʾ��" << endl;
	for (int i = 0; i < 5; i++) {
		puts(s[i]);
		free(s[i]);
	}
	free(s);
	return 0;
}
