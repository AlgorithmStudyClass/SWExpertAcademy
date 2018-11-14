#include <iostream>
#include <random>
#include <string>
#include<vector>
#include<math.h>
#include <array>
#include <iostream>

void setToNull(int *tempPtr)
{
	// we're making tempPtr point at something else, not changing the value that tempPtr points to.
	tempPtr = nullptr; // use 0 instead if not C++11
}
void setToNull2(int *&tempPtr)
{
	// we're making tempPtr point at something else, not changing the value that tempPtr points to.
	tempPtr = nullptr; // use 0 instead if not C++11
}

void foo(int *&ptr) // pass pointer by reference
{
	ptr = nullptr; // this changes the actual ptr argument passed in, not a copy
}

int* allocateArray(int size)
{
	return new int[size];
}
// Returns a reference to the index element of array
int& getElement(std::array<int, 25> &array, int index)
{
	// we know that array[index] will not be destroyed when we return to the caller (since the caller passed in the array in the first place!)
	// so it's okay to return it by reference
	return array[index];
}int returnByValue()
{
	return 5;
}

int& returnByReference()
{
	static int x = 5; // static ensures x isn't destroyed when it goes out of scope
	return x;
}
int main()
{
	int x = 5;
	int *ptr = &x;
	std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n'; // prints non-null
	foo(ptr);
	std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n'; // prints null
																	// First we set ptr to the address of five, which means *ptr = 5
	int five = 5;
	int *ptr1 = &five;

	// This will print 5
	std::cout << *ptr1 <<std::endl;

	// tempPtr will receive a copy of ptr
	setToNull(ptr);

	// ptr is still set to the address of five!

	// This will print 5
	if (ptr)
		std::cout << *ptr;
	else
		std::cout << " ptr is null" << std::endl;

	setToNull2(ptr);
	if (ptr)
		std::cout << *ptr;
	else
		std::cout << " ptr is null" << std::endl;

	return 0;
}