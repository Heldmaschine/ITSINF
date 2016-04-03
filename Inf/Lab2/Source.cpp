#include <iostream>

using namespace std;
int BinarySearchRight(int left, int right, int array[], int key);
int BinarySearchLeft(int left, int right, int array[], int key);
int main()
{
	int animalNumber, enquiryNumber, enquiry;
	cin >> animalNumber;
	int* animalColor = new int[animalNumber];
	for (int counter1 = 0; counter1 < animalNumber; ++counter1) {
		cin >> animalColor[counter1];
	}
	cin >> enquiryNumber;
	for (int counter2 = 0; counter2 < enquiryNumber; ++counter2) {
		cin >> enquiry;
		int leftPosition = BinarySearchLeft(0, animalNumber, animalColor, enquiry);
		int rightPosition = BinarySearchRight(0, animalNumber, animalColor, enquiry);
		cout << rightPosition - leftPosition << endl;
	}
	delete[] animalColor;
	system("pause");
	return 0;
}

int BinarySearchLeft(int left, int right, int array[], int key) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (key <= array[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int BinarySearchRight(int left, int right, int array[], int key) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (key >= array[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}