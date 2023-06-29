using namespace std;
#include<iostream>
void randomizedtask3(int* arr, int size);
void viewtask3(int* arr, int size);
void deletearr(int*& arr, int& size, int index1, int index2);

int task3main() {
	int size = 0;
	cout << "Input the size of array  ";
	cin >> size;
	int* arr = new int[size];
	randomizedtask3(arr, size);
	cout << "\nYour array:\n";
	viewtask3(arr, size);
	cout << "Input indexes you want to delete from 1 - " << size << ")\n";
	int index1; int index2;
	cout << "Index 1 -  ";
	cin >> index1;
	cout << "Index 2 -  ";
	cin >> index2;
	deletearr(arr, size, index1, index2);
	cout << "New arr is:\n";
	viewtask3(arr, size);
	return 0;
}

void randomizedtask3(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
	}
}

void viewtask3(int* arr, int size) {
	cout << "////////////////////////////////////\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n////////////////////////////////////\n\n";
}
void deletearr(int*& arr, int& size, int index1, int index2) {
	int* newarr = new int[size - (index2 - index1 + 1)];
	int newsize = size - (index2 - index1 + 1);
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (i == index1 - 1) {
			while (i != index2 - 1) {
				i++;
			}
			continue;
		}
		newarr[k] = arr[i];
		k++;
	}
	size = newsize;
	delete[]arr;
	arr = newarr;
}
