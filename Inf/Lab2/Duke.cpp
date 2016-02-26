#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	int animalNumber, enquiryNumber;
	cin >> animalNumber;
	int *animalColor = new int[animalNumber];
	for (int counter1 = 0; counter1 < animalNumber; ++counter1) {
		cin >> animalColor[counter1];
	}
	cin >> enquiryNumber;
	int *enquiry = new int[enquiryNumber];
	for (int counter2 = 0; counter2 < enquiryNumber; ++counter2) {
		cin >> enquiry[counter2];
	}
	for (int counter3 = 0; counter3 < enquiryNumber; ++counter3) {
		int leftPosition = BinarySearchLeft(0, animalNumber, animalColor, enquiry[counter3]);
		int rightPosition = BinarySearchRight(0, animalNumber, animalColor, enquiry[counter3]);
		cout << rightPosition - leftPosition << endl;
	}
	delete[] animalColor;
	delete[] enquiry;
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