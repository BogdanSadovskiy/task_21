using namespace std;
#include<iostream>
void addel(int*& arr, int& size, int* arr2, int size2);
void randomized(int* arr, int size);
void view(int* arr, int size);
int master() {
	int size = 0;
	cout << "Input the size of array  ";
	cin >> size;
	int* arr = new int[size];
	randomized(arr, size);
	cout << "\nYour array:\n";
	view(arr, size);
	start:
	int size2 = 0;
	cout << "How many elements you want to add in the array?  ";
	cin >> size2;
	int* arr2 = new int[size2];
	randomized(arr2, size2);
	cout << "\nNew elements:\n";
	view(arr2, size2);
	addel(arr, size, arr2, size2);
	delete[] arr2;
	cout << "Now your arr is:\n";
	view(arr, size);
	exit:
	cout << "Want to add some elements again? (1 - yes; 0 - exit)\n";
	char q;
	cin >> q;
	if (q == '1') {
		goto start;
	}
	else if (q == '0') {
		return 0;
	}
	else {
		cout << "Wrong inputting\n";
		goto exit;
	}

}
void addel(int*& arr, int& size, int* arr2,int size2) {
	int* newarr = new int[size + size2];
	int i = 0;
	for (; i < size; i++) {
		newarr[i] = arr[i];
	}
	for (int j = 0; j < size2; j++) {
		newarr[i] = arr2[j];
		i++;
	}

	size = size + size2;
	delete[] arr;
	arr = newarr;
	
	
}
void randomized(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
	}
}
void view(int* arr, int size) {
	cout << "////////////////////////////////////\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n////////////////////////////////////\n\n";
}