//pointers and returning pointers from functions


{
#include <iostream>

char* find(char d, char* str)
{
	char* ptr = str;
	while (*ptr != d)
	{
		ptr++;
	}

	return ptr;
}

int main()
{
	char* start = find('a', "The lazy sleeping...");

	std::cout << start << std::endl;

	return 0;
}
}

{//Dynamacally allocating memory
	#include <iostream>

//pointers and returning pointers from functions

char* find(char d, char* str)
{
	char* ptr = str;
	while (*ptr != d)
	{
		ptr++;
	}

	return ptr;
}

char* getName()
{
	char* name = new char[100];

	std::cout << "Enter your name: ";
	std::cin.getline(name, 100);

	return name;
}

int main()
{
	//char* start = find('a', "The lazy sleeping...");
	//std::cout << start << std::endl;

	char* name = getName();
	std::cout << name << std::endl;

	delete []name;

	return 0;
}
}



class Rectangle
{
	public:
		Rectangle(int height, int width);

}

Rectangle* pObj = new Rectangle(10, 20);

pObj->getWidth();

(*pObj).getWidth();


{
	#include <iostream>

//pointers and returning pointers from functions

char* find(char d, char* str)
{
	char* ptr = str;
	while (*ptr != d)
	{
		ptr++;
	}

	return ptr;
}

char* getName()
{
	char* name = new char[100];

	std::cout << "Enter your name: ";
	std::cin.getline(name, 100);

	return name;
}

class Rectangle
{
public:
	Rectangle(float width, float height);
	m_width(width);
	m_height(height);


private:
	float m_width;
	float m_height;
};

int main()
{
	Rectangle* pHouse = new Rectangle(1000, 2000);
	std::cout << pHouse->getHeight() << ", " << pHouse.getWidth() << std::endl;
	//char* start = find('a', "The lazy sleeping...");
	//std::cout << start << std::endl;

	//char* name = getName();
	//std::cout << name << std::endl;
	//delete []name;

	return 0;
}
}


//Assignment 3;
std::vector<IPRecord*> // how to declare it


v[4]->incrementFrequency(); // how to use it
