//Test; not inettest
/*
online compiler

exception handling 
*/


#include <iostream>

using namespace std;

class IntRange{
public:
	IntRange(int lower, int upper):
	m_lower(lower),
	m_upper(upper)
	{}
	
	int getInput(){
		int input;
		cin >> input;
		if(input < m_lower) throw TooLow();
		if(input > m_upper) throw TooHigh();
		
		return input;
	}
	
	class TooLow{
		
	};
	
	class TooHigh{
		
	};
	
private:
	int m_lower;
	int m_upper;
};

int main(){
	
	IntRange range(4, 12);
	
	cout << "Enter a value: ";
	try{
		int value = range.getInput();
		cout << "Value entry" << endl;
	}
	catch(IntRange::TooHigh){
		cout << "You enterend a value above the range." << endl;
	}
	catch(IntRange::TooLow){
		cout << "You enterend a value below the range." << endl;
	}
	
	
	
	
	return 0;
}




#include <iostream>
#include <string>

using namespace std;

class IntRange{
public:
	IntRange(int lower, int upper):
	m_lower(lower),
	m_upper(upper)
	{}
	
	int getInput(){
		int input;
		cin >> input;
		if(input < m_lower) throw OutOfRange(input, "The Value was too low.");
		if(input > m_upper) throw OutOfRange(input, "The Value was too high.");
		
		return input;
	}
	
	class OutOfRange{
	public:
		OutOfRange(int input, string message):
		input(input),
		message(message)
		{}
		int input;
		string message;
	};
	
private:
	int m_lower;
	int m_upper;
};

int main(){
	
	IntRange range(4, 12);
	
	cout << "Enter a value: ";
	try{
		int value = range.getInput();
		cout << "Value entry of " << value << endl;
	}
	catch(IntRange::OutOfRange ex){
		cout << "Invalid data entry, you entered a " << ex.input << endl;
		cout << ex.message << endl;
	}
	
	
	
	
	return 0;
}













































