#include <iostream>
#include <random>
#include <string>
#include<vector>
#include<math.h>
#include <array>

using namespace std;

std::tuple<int, double> returnStruct() // return a tuple that contains an int and a double
{
	return std::make_tuple(5, 6.7); // use std::make_tuple() as shortcut to make a tuple to return
}

int main()
{
	std::tuple<int, double> s = returnStruct(); // get our tuple
	std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << '\n'; // use std::get<n> to get the nth element of the tuple

	return 0;
}