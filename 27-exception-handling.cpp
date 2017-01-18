/*
is Palindrome

write a split function
vector of words
  using string stream to create a vector of words

*/

//test
//not polymorphism

/*
Exception Handling


*/

float divide (float n, float d){
  if(d == 0.0) throw "Error can't divide by 0";
  return n/d;
}

try{
  float result = divide(a, b);
}
catch(char* ex){ //... will catch any data type
  std::cout << "don't do that" << std::endl;
}
catch(int ex){

}
