//assignment 6 sharks and fish


//create fish class and shark class
//enum = a way to define your own values values for the data type   





//chapter 12 string
#include <iostream>
#include <string>
#include <sstream>

using namespace std;



int main(){
	//-------

	string stream;

	string readMe = "John 20 40";

	istringstream is(readMe);
	ostringstream os;


	string name;
	int score1;
	int score2;

	is >> name >> score1 >> score2;
	os << name << " earned an average of " << (score1 + score2) / 2 << " on his homework." << endl;

	cout << os.str() << endl;

	//-------

	//string strInt = "12345";
	//string strFloat = "123.456";
	//string strMixed = "12345 is a number";
	//string strFromHex = "F";
	//size_t howMany;

	//int resultInt = stoi(strInt);
	//float resultFloat = stof(strFloat);
	//int resultMixed = stoi(strMixed, &howMany);
	//int fromHex = stoi(strFromHex, &howMany, 16);

	//------

	//extern char** environ; // points to the environment variables
	//int k = 0;
	//while (environ[k] != 0){
	//	cout << environ[k] << endl;
	//	k++;
	//}

	//-------

	return 0;
}






























