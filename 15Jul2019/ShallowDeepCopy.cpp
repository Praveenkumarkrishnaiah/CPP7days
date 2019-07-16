#include <iostream>
#include <cstring>
using namespace std;

class MyString {
	char *m_p;
public:
	MyString() :m_p(NULL) {}
	MyString(const char *p) : m_p(new char[strlen(p) + 1]) { strcpy(m_p, p); }
	~MyString() {
		if (m_p) {
			cout << " Deleted string is: " << m_p << endl;
			delete[] m_p;
			m_p = NULL;
		}
		else
			cout << " empty string object destroyed" << endl;

	}
	//MyString(MyString &rhs) : m_p(rhs.m_p) {} // Shallow Copy
	MyString(MyString &rhs) : m_p(new char[strlen(rhs.m_p) + 1]){ strcpy(m_p, rhs.m_p); } // Deep Copy

};
int main() {
	MyString str1;
	MyString str2("Hello");
	MyString str3("World");

	MyString str4(str2);

	cout << "================" << endl;
}