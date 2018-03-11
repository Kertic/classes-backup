#include <iostream>
#include "DList.h"

using namespace std;

int main(void)
{

	DList<> test;


	test.Push_Front(1);
	test.Push_Front(2);
	test.Push_Front(3);
	for (int i = 0; i < test.size(); ++i)
		cout << test[i] << endl;

	cout << "\nTesting pushfront\n";
	test.Push_Front(17);
	for (int i = 0; i < test.size(); ++i)
		cout << test[i] << endl;

	cout << "\nTesting Erase at index 0\n";
	test.Erase(0);
	for (int i = 0; i < test.size(); ++i)
		cout << test[i] << endl;


	cout << "\nTesting Erase at largest index\n";
	test.Erase(test.size() - 1);
	for (int i = 0; i < test.size(); ++i)
		cout << test[i] << endl;


	cout << "Clearing";
	test.Clear();

	int j = 0;
	for (; j < test.size(); ++j)
		cout << test[j] << endl;
	cout << "\n\n\n\n";
	system("pause");

	return 0;
}