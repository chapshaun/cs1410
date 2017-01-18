//inheritance

void report(Grade *grade){
	std::cout << grade->getPercent() << std::endl;
}

//in main
report(&myGrade);
report(&yourGrade);


//polymorphism

//protected 
class TestGrade : public Grade{ // public, protected, or private
	
}

class TestGrade : protected Grade{
	
}

class TestGrade : private Grade{
	
}

/*
public						protected						private
base: public				base: public					base: public
derived: public				derived: protected				derived: private

base: protected				base: protected					base: protected
derived: protected			derived: protected				derived: private

base: private				base: private					base: private
derived: not visable		derived: not visable			derived: not visable


*/

#include <iostream>

using namespace std;

class Base{

public:
	Base(){
		cout << "Base constructor" << endl;
	}
	~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base{

public:
	Derived(){
		cout << "Derived constructor" << endl;
	}
	~Derived(){ cout << "Derived destructor" << endl; }
};

int main(){
	Derived obj;

	return 0;
}







