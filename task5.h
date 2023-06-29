using namespace std;
#include<iostream>
void see(int* arr, int size);
void even(int*& arr, int& size);
void odd(int*& arr, int& size);
void maxel(int*& arr, int& size);
void minel(int*& arr, int& size);
void MTM(int*& arr, int& size);
void LTM(int*& arr, int& size);

int bigtask() {
	int size = 0;
	cout << "Input the size of array  ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "Input " << i + 1 << " element ";
		cin >> arr[i];
	}
start:
	cout << "Your array:\n";
	see(arr, size);
	cout << "Choose one of this :\n";
	cout << "------------------------------------------------------------\n";
	cout << "Delete even numbers (input 1)\n";
	cout << "Delete odd numbers (input 2)\n";
	cout << "Delete MAX element (input 3)\n";
	cout << "Delete MIN element (input 4)\n";
	cout << "Delete elements that bigger then the middle index (input 5)\n";
	cout << "Delete elements that smaller then the middle index (input 6)\n";
	cout << "                  input 0 to exit\n";
	cout << "------------------------------------------------------------\n";
	char q;
	cin >> q;
	if (q == '1') {
		even(arr, size);
		goto start;
	}
	else if (q == '2') {
		odd(arr, size);
		goto start;
	}
	else if (q == '3') {
		maxel(arr, size);
		goto start;
	}
	else if (q == '4') {
		minel(arr, size);
		goto start;
	}
	else if (q == '5') {
		MTM(arr, size);
		goto start;
	}
	else if (q == '6') {
		LTM(arr, size);
		goto start;
	}
	else if (q == '0') {
		return 0;
	}
	else {
		cerr << "Wrong inputting\n";
		goto start;
	}
}

void see(int* arr, int size) {
	cout << "////////////////////////////////////\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n////////////////////////////////////\n\n";
}

void even(int*& arr, int& size) {
	int k = 0;
	for (int i = 0; i < size; i++) {
	
		if (arr[i] % 2 == 0) {
			size--;
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];

			}
			i--;
			
			k++;
		}

	}
	cout << endl;
	if (k == 0) {
		cout << "No even numbers detected\n";
	}
	else {
		cout << k << " elements deleted\n";
	}
}

void odd(int*& arr, int& size) {
	int k = 0;
	for (int i = 0; i < size; i++) {

		if (arr[i] % 2 != 0) {
			size--;
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];

			}
			i--;

			k++;
		}

	}
	cout << endl;
	if (k == 0) {
		cout << "No even numbers detected\n";
	}
	else {
		cout << k << " elements deleted\n";
	}
}
void maxel(int*& arr, int& size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] == max) {
			size--;
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];
			}
			break;
		}
	}
	cout << "Deleted MAX (" << max << ") element\n";
}

void minel(int*& arr, int& size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] == min) {
			size--;
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];
			}
			break;
		}
	}
	cout << "Deleted MIN (" << min << ") element\n";
}

void MTM(int*& arr, int& size) {
	int Mindex = arr[(size - 1) / 2];
	int k = 0;
	cout << "The middle number is " << Mindex << endl;
	for (int i = 0; i < size; i++) {
		if (arr[i] > Mindex) {
			size--;
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];
			}
			i--;
			k++;
		}
	}
	cout << endl;
	if (k == 0) {
		cout << "No bigger numbers than "<< Mindex<< " detected\n";
	}
	else {
		cout << k << " elements deleted\n";
	}
}

void LTM(int*& arr, int& size) {
	int Mindex = arr[(size - 1) / 2];
	int k = 0;
	cout << "The middle number is " << Mindex << endl;
	for (int i = 0; i < size; i++) {
		if (arr[i] < Mindex) {
			size--;
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];
			}
			i--;
			k++;
		}
	}
	cout << endl;
	if (k == 0) {
		cout << "No smaller numbers than " << Mindex << " detected\n";
	}
	else {
		cout << k << " elements deleted\n";
	}
}