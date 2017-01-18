//Chapter 11

//copy constructor
Rectangle r1(10, 20);
Rectangle r2 = r1;

void Example(Rectangle)
{
	
}

Example(r1);


//operator overloading

//Copy Constructor

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

	NumberArray(const NumberArray& obj){
		m_size = obj.m_size;

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



int main(){
	NumberArray a1(10, 1);
	NumberArray a2 = a1;

	cout <<  "a1 total: " << a1.getTotal() << endl;
	a2.setValue(0, 10);
	cout << "a2 total: " << a2.getTotal() << endl;

	cout << "a1 total: " << a1.getTotal() << endl;


	return 0;
}





