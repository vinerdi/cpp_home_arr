#include <iostream>
using namespace std;

int* allocateArray(int size) {
	return new int[size];
}

void initializeArray(int* arr, int size) 
{
	for (int i = 0; i < size; i++) {
		arr[i] = i+1;
	}
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}cout<< endl;
}

void deleteArray(int* &arr) {
	delete[] arr;
	arr = nullptr;
}

void addElementToEnd(int* &arr, int &size, int newElement) {
    int* newArr = new int[size + 1];
    
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    
    newArr[size] = newElement;
    
    delete[] arr;
    
    arr = newArr;
    
    size += 1;
}

void insertElementAtIndex(int* &arr, int &size, int index, int value) {
	int* newArr = new int[size + 1];
	
	for (int i = 0; i < index; i++) {
		newArr[i] = arr[i];
	}
	
	newArr[index] = value;
	
	for (int i = index; i < size; i++) {
		newArr[i + 1] = arr[i];
	}
	
	delete[] arr;
	
	arr = newArr;
	
	size++;
}

void remove_element_at_index(int*& arr, int& size, int index) {
	if (index < 0 || index >= size)
	{
		cout << "erorr index!";
		return;
	}
	int* newArr = new int[size - 1];
	for (int i = 0, j= 0; i < size; i++)
	{
		if (i != index)
		{
			newArr[j++] = arr[i];
		}

	}
	delete[] arr;
	arr = newArr;
	size--;
	
}

int main() {
	int size = 6;
	int* arr = allocateArray(size);

	initializeArray(arr, size);
	cout << "Array: ";
	printArray(arr, size);

	// Add element to the end of the array
	addElementToEnd(arr, size, 7);
	cout << "Array after adding element: ";
	printArray(arr, size);
	cout << endl;

	// Insert element at index
	insertElementAtIndex(arr, size, 3, 10);
	cout << "Array after inserting element: ";
	printArray(arr, size);
	cout << endl;

	// Remove element at index
	remove_element_at_index(arr, size, 3);
	cout << "Array after removing element: ";
	printArray(arr, size);

	deleteArray(arr);


	return 0;	
}