//Lvalue and Rvalue

int x = 34; // x is an lvalue
int& lRef = x; // lRef is a lvalue reference





int x = 0;
x = 12;
std::cout << x << std::endl;
x = square(4); // square(4) is rvalue reference; [16] get's copied into x
std::cout << x << std::endl;


int square(int x){
	return x * x; // x * x gets stored in anonymous value in memory [16]
	

}

int&& r = rvalue(4);


















