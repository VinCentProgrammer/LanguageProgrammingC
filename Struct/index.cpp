// C++ program to illustrate concept of
// the constant pointers to constant
#include <iostream>
using namespace std;

// Driver Code
int main()
{

	const int a{ 50 };
	const int b{ 90 };

	// ptr points to a
	const int* const ptr{ &a };

	// *ptr = 90;
	// Error: assignment of read-only
	// location ‘*(const int*)ptr’

	// ptr = &b;
	// Error: assignment of read-only
	// variable ‘ptr’

	// Address of a
	cout << ptr << "\n";

	// Value of a
	cout << *ptr << "\n";

	return 0;
}
