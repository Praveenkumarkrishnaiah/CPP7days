#include <iostream>
using namespace std;

#define MAX 5

class MyVector {
	int top;
	int arr[MAX];
public:
	MyVector() :top(-1) {}
	void push_back(int val) { arr[++top] = val; }
	int operator[] (int index) { return arr[index]; }
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
		int& operator *() { return m_p->arr[index]; }
	};
	Iterator begin() { return Iterator(this, 0); }
	Iterator end() { return Iterator(this, MAX); }
};

int main() {
	MyVector vObj;

	for (int i = 0; i < MAX; i++)
		vObj.push_back(i);

	for (int i = 0; i < MAX; i++)
		cout << "vObj[" << i << "]= " << vObj[i] << endl;
		
	for (MyVector::Iterator it = vObj.begin(); it != vObj.end(); ++it)
		cout << " *it= " << *it << endl;
	return 0;
}

















int main_cpuzzle2() {
	int arr[] = { 1,2,3,4,5 };
	int k = 2;

	arr[k *=2, 2, 3] = 678;

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		cout << "arr[" << i << "]= " << arr[i] << endl;
	return 0;
}

int main_cpuzzle1() {
	int i = 10, n = 4;

	printf("i=%*d\n", n, i);
	printf("i=%*d\n", 3, i);
	printf("i=%*d\n", 2, i);
	printf("i=%*d\n", 1, i);
	return 0;
}