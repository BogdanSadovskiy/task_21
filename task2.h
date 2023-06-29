using namespace std;
#include<iostream>
void addeltask2(int*& arr, int& size, int* arr2, int size2, int index);
void randomizedtask2(int* arr, int size);
void viewtask2(int* arr, int size);
int task2main() {
	int size = 0;
	cout << "Input the size of array  ";
	cin >> size;
	int* arr = new int[size];
	randomizedtask2(arr, size);
	cout << "\nYour array:\n";
	viewtask2(arr, size);
start:
	int size2 = 0;
	cout << "How many elements you want to add in the array?  ";
	cin >> size2;

	int* arr2 = new int[size2];
	randomizedtask2(arr2, size2);
	cout << "\nNew elements:\n";
	viewtask2(arr2, size2);
index:
	cout << "Input the index from new elements will start (1 - " << size << ")  ";
	int index = 0; cin >> index;
	if (index <1 || index>size) {
		cout << "Wrong inputting\n";
		goto index;
	}
	addeltask2(arr, size, arr2, size2, index);
	delete[] arr2;
	cout << "Now your arr is:\n";
	viewtask2(arr, size);
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
void addeltask2(int*& arr, int& size, int* arr2, int size2, int index) {
	int* newarr = new int[size + size2];
	int k = 0;
	
	for (int i = 0; i < size + size2; i++) {
		if (index-1 == i) {
			for (int j = 0; j < size2; j++) {
				newarr[i] = arr2[j];
				if (j<size2-1){ 
					i++; 
				}
			}
		}
		else {
			newarr[i] = arr[k];
			k++;
		}
	}

	size = size + size2;
	delete[] arr;
	arr = newarr;


}
void randomizedtask2(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
	}
}
void viewtask2(int* arr, int size) {
	cout << "////////////////////////////////////\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n////////////////////////////////////\n\n";
}