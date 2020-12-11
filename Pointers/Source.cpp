#include<iostream>
#include<ctime>
int*_2_returnSmallNumPointer(int*, int*);
void Swap(int*, int*);
void _3_loadArrayViaPointers(int*, size_t);
void printArray(int*, size_t);
int _4_sumOfElements(int*, size_t);
int _5_prodOfElements(int*, size_t);
int* _6_PointerOfInnerArray(int*, int*, size_t, size_t);
int* _7_deletePrimeNums(int*, size_t);
int* searchMin(int*, size_t);
void choiceSort(int*, size_t);

int main()
{
	//int a = 7, b = 5;
	//int * ptr = &a, * ptr1 = &b;
	//int arr[5] = { 1, 2, 3, 4, 5 };
	//int * ptr_arr = arr; // array name contains address of zero element, means the same: int * ptr_arr = &arr[0]
	//// arr - constant
	//ptr_arr++; // transition to address of next element
	//ptr_arr--;

	////while (ptr_arr <= &arr[4]);
	//std::cout << *(ptr_arr + 3) << std::endl; // arr[i] <=> *(arr + i)

	//std::cout << ptr << std::endl << ptr1 << std::endl; //a's adress
	//std::cout << *ptr << std::endl; //dereference
	//std::cout << ptr - ptr1 << std::endl; // number of elements that can be inserted between a and b
	int a = 3, b = 9;
	const size_t size = 10;
	const size_t sizeB = 2;
	int A[size];
	int B[sizeB];
	srand(time(0));
	Swap(&a, &b);
	std::cout << a << " " << b << std::endl;

	// 2. Create function which takes two pointers and returns pointer to a lesser number.
	std::cout << *_2_returnSmallNumPointer(&a, &b) << std::endl;

	// 3. Given array of integers, initialize and print it via pointers.
	_3_loadArrayViaPointers(A, size);
	printArray(A, size);

	// 4. Create array of 10 integers. Initialize array randomly within -25 to 35 range. Get sum of the elements using pointer to the array.
	_3_loadArrayViaPointers(A, size);
	printArray(A, size);
	std::cout << "Sum of array elements is: " << _4_sumOfElements(A, size) << "\n";
	std::cout << "\n";

	// 5. Create array of 10 integers. Initialize array randomly within -44 to 76 range. Get product of the elements using pointer to the array.
	std::cout << "Product of array elements is: " << _5_prodOfElements(A, size) << "\n";
	
	// 6. Create app which contains function which takes pointers to two arrays(A and B) and arrays sizes.
	// App checks if array B is a subarray of array A and returns pointer to the start of found segment,
	// returns 0 if no such element.
	_3_loadArrayViaPointers(A, size);
	printArray(A, size);
	_3_loadArrayViaPointers(B, sizeB);
	printArray(B, sizeB);
	if (_6_PointerOfInnerArray(A, B, size, sizeB) == nullptr) std::cout << "B is not A\n";
	else std::cout << _6_PointerOfInnerArray(A, B, size, sizeB);

	// 7. Create function which takes pointer to an array and its size. Function deletes all prime numbers and returns pointer to the new array.
	_7_deletePrimeNums(A, size);
	printArray(A, size);
	std::cout << *_7_deletePrimeNums(A, size) << std::endl; // doesn't delete elements, changes to 0 instead
	
	// 8. Create function which gets min array element and returns pointer to it. Use selection sort.
	std::cout << *searchMin(A, size) << std::endl;
	choiceSort(A, size);
	printArray(A, size);
	system("pause");
	return 0;
}
int*_2_returnSmallNumPointer(int*a, int*b)
{
	if (*a > *b) return b;
	else return a;
}
void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void _3_loadArrayViaPointers(int*A, size_t size)
{
	for (int *ptr = A; ptr < A + size; ptr++)
	{
		*ptr = rand() % 50;
	}
}
void printArray(int* A, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << *(A + i) << " ";
	}
	std::cout << "\n";
}
int _4_sumOfElements(int*A, size_t size)
{
	int sum = 0;
	for (int *i = A; i < A + size; i++)
	{
		sum += *i;
	}
	return sum;
}
int _5_prodOfElements(int*A, size_t size)
{
	int prod = 0;
	for (int *i = A; i < A + size; i++)
	{
		prod *= *i;
	}
	return prod;
}
int* _6_PointerOfInnerArray(int*A, int*B, size_t sizeA, size_t sizeB)
{
	for (int *i = A; i < A + sizeA; i++)
	{
		if (*i == *B)
		{
			int* first = i;
			for (int* j = B + 1; j < B + sizeB; j++, i++)
			{
				if (*i != *j || i == A + sizeA)
					return nullptr;
			}
			return first;
		}
		return nullptr;
	}
}
int* _7_deletePrimeNums(int*A, size_t size)
{
	for (int *i = A; i < A + size; i++)
	{
		int* index = i;
		for (int div = 2; div <= *i / 2; div++)
		{
			if (*i % div == 0) break;
			else *i = 0;
		}
	}
	return A;
}
int* searchMin(int*A, size_t size)
{
	int* min = A;
	int* i = A + 1;
	for (i; i < A + size; i++)
	{
		if (*i < *min)
			min = i;
	}
	return min;
}
void choiceSort(int*A, size_t size)
{
	int* i = A;
	for (i; i < A + size; i++)
	{
		int* minptr = searchMin(i, size);
		int *temp = i;
		*i = *minptr;
		minptr = temp;
	}
}
