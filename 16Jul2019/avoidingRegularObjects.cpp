#include <iostream>
using namespace std;

class cA {
	int m_i;
	cA(int x = 0) :m_i(x) { cout << "cA::Cons:this = " << this << endl; }
public:
	~cA() { cout << "cA::Des: this= " << this << endl; }
	static cA* Creator() { return new cA(); }
};

void avoid_stackObjects() {
	//cA aObj; // Avoided stack objects,
//	cA *ap = new cA();
	cA *ap = cA::Creator();

	cout << "ap = " << ap << endl;
	cout << "=======" << endl;
	delete ap;
}

class cB{
public:
	//static void* operator new(size_t size) = delete; // {}
};

struct sZ {} zObj;
void * operator new (size_t size, sZ &nickname) {
	cout << "void * operator new (size_t size, sZ &nickname) " << endl;
	return nullptr;
}

void avoid_heapObjects() {
	cB bObj;

	//cB *bp = new cB();
	cB *bp = new(zObj) cB();
}

int main() {
	avoid_stackObjects();
	avoid_heapObjects();

	return 0;
}




#if 0
#include <functional>

int main_tup() {
	std::tuple<int, char, float> tObj(10, 'A', 45.56f);

	cout << " get<0>(tObj)" << get<0>(tObj) << endl;
	cout << " get<1>(tObj)" << get<1> (tObj) << endl;
	cout << " get<2>(tObj)" << get<2>(tObj) << endl;

	cout << " tObj[0]= " << tObj[0] << endl;
	cout << " tObj[1]= " << tObj[1] << endl;
	cout << " tObj[2]= " << tObj[2] << endl;

}
#endif








