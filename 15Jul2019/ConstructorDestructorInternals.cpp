
class Complete // hybrid, multiple, virtual Inheritance
{
	// static, mutable, const, volatile, register
	// Contained Objects
public:
	// const, static, virtual, hidden, overloaded member functions

	Complete() // Initializer list
	/*
	1. Call base constructors in order of Inheritance.
	2. Call Contained objects constructors in order of declaration.
	3. Initialize vptr to respective offset table.
	4. Initialize vptr to respective v-table.
	5. Mutable data members are initialized in order of declaration.
	6. Constant data members are initialized in order of declaration.
	*/
	{
	//7. Call constructors of local objects in order of declaration.
	}
	//8. Call destructors of local objects in reverse order of declaration.

	~Complete()
	/*
	1. Initialize vptr to respective offset table.
	2. Initialize vptr to respective v-table.
	*/
	{
	//3. Call constructors of local objects in order of declaration.
	}
	/*
	4. Call destructors of local objects in reverse order of declaration.
	5. Call destructors of Contained objects in reverse order of declaration.
	6. Call destructors of base in reverse order of Inheritance.
	*/
};