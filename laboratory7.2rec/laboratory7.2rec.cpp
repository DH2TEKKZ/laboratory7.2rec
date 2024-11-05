#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int low, const int high, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int minElement(int** a, const int rowCount, const int colCount, int i, int j);

int main()
{
	srand((unsigned)time(NULL));

	int low = -42;
	int high = 51;

	int rowCount = 7;
	int colCount = 6;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, low, high, 0, 0);
	cout << endl;

	Print(a, rowCount, colCount, 0, 0);
	cout << endl;

	int s = minElement(a, rowCount, colCount, 0, 0);

	cout << "sum= " << s;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int low, const int high, int i, int j)
{
	a[i][j] = low + rand() % (high - low + 1);
	if (j < colCount - 1)
	{
		Create(a, rowCount, colCount, low, high, i, j + 1);
	}
	else {
		if (i < rowCount - 1) {
			Create(a, rowCount, colCount, low, high, i + 1, 0);
		}
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1) {
		Print(a, rowCount, colCount, i, j + 1);
	}
	else {
		cout << endl;
		if (i < rowCount - 1) {
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else {
			cout << endl;
		}
	}
}

int minElement(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i >= rowCount) {
		return 0;
	}

	if (j >= colCount) {
		return minElement(a, rowCount, colCount, i + 1, 0);
	}
	int min = a[i][j];
	if (j < colCount - 1) {
		int nextMin = minElement(a, rowCount, colCount, i, j + 1);
		if (nextMin < min) {
			min = nextMin; 
		}
	}

	if (j == 0) {
		return min + minElement(a, rowCount, colCount, i + 1, 0); 
	}

	return min; 
}