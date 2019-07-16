#include <iostream>
using namespace std;

#define MAX 8

template <typename T>
class MyVector {
	int top;
	T arr[MAX];
public:
	MyVector() :top(-1) {}
	void push_back(T val) { arr[++top] = val; }
	T& operator[] (int index) { return arr[index]; }
	class Iterator {
		MyVector *m_p;
		int index;
	public:
		Iterator(MyVector *p, int ind) :m_p(p), index(ind) {}
		bool operator != (Iterator rhs) {
			if (this->m_p == rhs.m_p)
				if (this->index == rhs.index)
					return false;
			return true;
		}
		Iterator operator ++ () { index++;  return *this; }
		T& operator *() { return m_p->arr[index]; }
	};
	Iterator begin() { return Iterator(this, 0); }
	Iterator end() { return Iterator(this, MAX); }
};

int main_own() {
	MyVector<int> vObj;

	for (int i = 0; i < MAX; i++)
		vObj.push_back(i);

	for (int i = 0; i < MAX; i++)
		cout << "vObj[" << i << "]= " << vObj[i] << endl;

	for (MyVector<int>::Iterator it = vObj.begin(); it != vObj.end(); ++it)
		cout << " *it= " << *it << endl;

	//*it = 12345;

	return 0;
}

#include <vector>

int main() {
	vector<int> vObj;

	for (int i = 0; i < MAX; i++)
		vObj.push_back(i);

	for (int i = 0; i < MAX; i++)
		cout << "vObj[" << i << "]= " << vObj[i] << endl;

	for (vector<int>::iterator it = vObj.begin(); it != vObj.end(); ++it)
		cout << " *it= " << *it << endl;
	return 0;
}
