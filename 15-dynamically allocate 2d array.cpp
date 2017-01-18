//dynamically allocate 2d array

//allocate an array of pointers, with those pointers we allocate arrays


int** myArray;

myArray = new int*[8];

myArray[0] = new int[100];

myArray[i] = new int[100];
.
.
.
.



//syntax for use , you wouldn't do this anymore, you would use vectors of vectors
myArray[0][0] = i;

myArray[2][10] = 44;


//clean up in reverse order of make_heap

delete[] myArray[1];
delete[] myArray[0];
delete[] myArray;
