/*
Chapter 15
Polymorphism: The ability to take many forms


virtual 	Functions/Methods
				Overloading (same function name, different parameters)
				override (same )
				polymorphism = replace functions
*/

#include <iostream>

using namespace std; 

class GradedActivity{
public:
	void setScore(float v){ m_score = v; }
	float getScore(){ return m_score; }
	virtual char computeLetter(){ //put virtual 
		if (m_score > 90) return 'A';
		if (m_score > 80) return 'B';
		if (m_score > 70) return 'C';
		return 'F';
	}
private:
	float m_score;
};

class PassFailActivity : public GradedActivity{
public:
	void setScore(float v){}// this is overriding. when you add the keyword override, we are using the replace(virtual)
	virtual char computeLetter(){

		//return GradedActivity::computeLetter(); //you could do this
		//sets up a vtable for function pointers 
		if (getScore() >= 70) return 'P';
		return 'N';
	}
private:

};

//Polymorphism, this will execute different pointers 
void report(GradedActivity* grade){
	cout << "The grade is: " << grade->computeLetter() << endl;
}


//void report(PassFailActivity* grade){
//	cout << "The grade is: " << grade->computeLetter() << endl;
//}

int main(){

	GradedActivity* grade1 = new GradedActivity();
	PassFailActivity* grade2 = new PassFailActivity();
	PassFailActivity* grade3 = new PassFailActivity();
	GradedActivity* grade4 = new PassFailActivity();


	grade1->setScore(92);
	grade2->setScore(72);
	grade3->setScore(56);
	grade4->setScore(80);


	report(grade1);
	report(grade2);
	report(grade3);
	report(grade4);





	return 0;
}







/*
Abstract Base Classes (Interface)
	Pure vitual function
	
		virtual void myFunction() = 0;
		
		Concrete 
		


*/




























