#include <iostream>
using namespace std;

 // --------- Library --------------
struct gameObject {
	virtual void collidesWith(gameObject &rhs) = 0;
	virtual void collided() = 0;
};
struct Asteroid :gameObject {
	virtual void collidesWith(gameObject &rhs) {		cout << " Asteroid object collided with ";
		rhs.collided();
	}
	virtual void collided() {		cout << " Asteroid object" << endl;	}
};
struct Satellite :gameObject {
	virtual void collidesWith(gameObject &rhs) {
		cout << " Satellite object collided with ";
		rhs.collided();
	}
	virtual void collided() { cout << " Satellite object" << endl; }
};
struct Ship :gameObject {
	virtual void collidesWith(gameObject &rhs) {
		cout << " Ship object collided with ";
		rhs.collided();
	}
	virtual void collided() { cout << " Ship object" << endl; }
};

// ----------- Middle layer ----
void collision(gameObject & lhs, gameObject & rhs) {
	
	if (typeid(lhs) != typeid(rhs))
		lhs.collidesWith(rhs);
	else
		cout << typeid(lhs).name() <<" type objects cannot collide with "<< typeid(rhs).name() <<" object" << endl;
		//cout << " Same type objects cannot collide...." << endl;
	
	/*
	if (&lhs == &rhs)
		cout << "Same object" << endl;
	else
		lhs.collidesWith(rhs);
	*/
}
// ------------ Application ----
int main01() {
	Asteroid aObj;
	Satellite saObj;
	Ship sObj;

	collision(aObj, saObj);
	collision(aObj, sObj);
	collision(saObj, sObj);


	collision(sObj, sObj);
	int i = 0;

	collision((gameObject&)(i), sObj);
	return 0;
}

#include <typeinfo>

struct MyType  {
	void name() { cout << " My name is MyType"; }
};

void main() {
	int iVal = 10;
	//type_info ti ( typeid(iVal));
	Asteroid aObj;
	//type_info tAst ( typeid(aObj));


	//cout << " typeid(iVal): " << typeid(iVal).name() << endl;

	cout << "typeid(MyType).name(): " << typeid(MyType).name() << endl;

	
	cout << "typeid(typeid(MyType)).name(): " << typeid(typeid(MyType)) .name() << endl;
}









/*
int main()
{
	main();
	return 0;
}
*/