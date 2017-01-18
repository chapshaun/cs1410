#include <iostream>

using namespace std;

class Base{

public:
	Base(){ cout << "Base constructor" << endl; }
	virtual ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base{

public:
	Derived(){ cout << "Derived constructor" << endl; }
	virtual ~Derived(){ cout << "Derived destructor" << endl; }
};

int main(){
	//Derived obj;
	//----
	Base* obj = new Derived();
	delete obj;
	//----

	return 0;
}


//------


#include <iostream>

using namespace std;

class Rectangle{
public:
	Rectangle() :
		m_width(0),
		m_length(0)
	{

	}
	Rectangle(float width, float length) :
		m_width(width),
		m_length(length)
	{

	}
protected:
	float m_width;
	float m_length;
};

class Volume : public Rectangle{
public:
	Volume(float width, float length, float height) :
		Rectangle(width, length),
		m_height(height)
	{

	}

protected:
	float m_height;
};


int main(){



	return 0;
}




//-----


#include <iostream>

using namespace std;


class GradedActivity{
public:


	void setScore(float v) {
		m_score = v;
		computeLetter();
	}
	float getScore() { return m_score; }
	char getLetter() { return m_letter; }
protected:
	char m_letter;
	float m_score;

	void computeLetter() {}
};

class CurvedActivity : public GradedActivity{
public:
	CurvedActivity(float percent) :
		m_percent(percent)
	{}

	void setScore(float raw){ //overriding a function
		m_raw = raw;
		GradedActivity::setScore(raw * (1 + m_percent / 100));
	}

private:
	float m_raw;
	float m_percent;
};


int main(){
	
	CurvedActivity myGrade(10.0);
	myGrade.setScore(40);



	return 0;
}


//--------










































































