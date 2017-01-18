//assignment 4
//copy constructor
//assignment oporator, in class implementation
//you have to keep track of how many digits with setDigit(pos of digit, value of digit)

//mathematical operator

Length a,b;

Length c=a+b;

<return type> operator+(const &, const &);



//operator overloading



#include <iostream>
#include <ostream> //define generic ostream, iostream includes it tho


using namespace std;

class Length

{

public:
	Length() :
		m_feet(0),
		m_inches(0)

	{

	}

	Length(int feet, int inches) :
		m_feet(feet),
		m_inches(inches)
	{

	}

	int getFeet() const { return m_feet; }
	int getInches() const { return m_inches; }

	Length operator+(const Length& rhs){
		Length result;

		result.m_feet = m_feet + rhs.m_feet;
		result.m_inches = m_inches + rhs.m_inches;

		result.simplify();


		return result;
	}

	Length operator-(const Length& rhs){
		Length result;

		result.m_feet = m_feet - rhs.m_feet;
		result.m_inches = m_inches - rhs.m_inches;

		result.simplify();


		return result;
	}

	bool operator>(const Length& rhs) const {  //only return booleon
		bool result = false;

		if (m_feet > rhs.m_feet){
			result = true;
		}
		else if (m_feet == rhs.m_feet && m_inches > rhs.m_inches){
			result = true;
		}

		return result;
	}

	//ostream& operator<<(ostream& strm, const Length& obj){
		//strm << "feet: " << obj.getFeet() << ",inches: " << obj.getinches() << endl;
		//return strm;
	//}

	void simplify(){
		if (m_inches >= 12){
			m_feet += (m_inches / 12);
			m_inches = m_inches % 12;
		}
		//else if(m_inches <= 0){
		//	m_feet = 
		//}
	}

private:
	int m_feet;
	int m_inches;
};

int main(){

	Length a(10, 4);
	Length b(0, 10);

	Length c = a + b;
	Length d = c - b;

	Length e = a.operator+(b); // same thing as line above


	cout << "feet: " << c.getFeet() << ", inches: " << c.getInches() << endl;
	cout << "feet: " << d.getFeet() << ", inches: " << d.getInches() << endl;


	//same as above, extraction and insertion operator
	//cout << c << endl;

	//cout << d << endl;

	//relational operator
	if (a > b){
		cout << "a is greater than b" << endl;
	}
	else{
		cout << "a is not greater than b" << endl;
	}



	return 0;
}







