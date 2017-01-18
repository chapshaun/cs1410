//assignment 4

std::string s = "1234";

m_number[0] = s[0] - '0';

cstring n_number;


// test next week

//three coding questions

//Chapter 9 - Chapter 10 - Chapter 11 (a little)

Thursday, Friday, Saturday, Sunday, Monday



///
#include <iostream>

using namespace std;

class NumberArray
{
public:
	NumberArray(unsigned int size, double defaultValue) :
		m_size(size)

	{
		m_array = new double[size];
		for (unsigned int item = 0; item < size; item++){
			m_array[item] = defaultValue;
		}
	}

	NumberArray(const NumberArray& obj):
		m_size(obj.m_size)

	{

		m_array = new double[m_size];
		for (unsigned int item = 0; item < m_size; item++){
			m_array[item] = obj.m_array[item];
		}
		cout << "Copy Constructor called" << endl;
	}

	~NumberArray(){
		delete[]m_array;
	}

	void setValue(unsigned int position, double value){ m_array[position] = value; }

	double getTotal(){
		double total = 0;
		for (unsigned int item = 0; item < m_size; item++){
			total += m_array[item];
		}
		return total;
	}

private:
	double* m_array;
	unsigned int m_size;

};

NumberArray test(NumberArray a){
	NumberArray a2(10, 2);

	return a2;
}

NumberArray makeArray(){
	NumberArray a(20, 2);

	return a;
}


void reportArray(NumberArray a){
	cout << a.getTotal() << endl;
}


int main(){
	NumberArray a1(10, 1);
	NumberArray a2(a1);
	NumberArray a3(makeArray());

	cout << "a1 total: " << a1.getTotal() << endl;
	a2.setValue(0, 10);
	cout << "a2 total: " << a2.getTotal() << endl;

	cout << "a1 total: " << a1.getTotal() << endl;

	reportArray(a1);


	return 0;
}



//operator overloading
//mathmatical operators
=
++
--
*
/
+=
//relational oporators
==
!=

// = 
void operator=(NumberArray& rhs);

NumberArray& operator=(NumberArray& rhs);




















