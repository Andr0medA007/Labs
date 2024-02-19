#include <iostream>
using namespace std;

static int sdvg(int *, int, int);
static int sdvg(int*, int, int, int);

int main()
{
	const int n = 5;
	int r = 0;
	int a[] = {2,1,3,4,5 };
	int k = a[0];
	sdvg(a, n, k);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	int b[] = { 3,5,8,16,7 };
	k = b[0];
	sdvg(b, n, k, r);
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
}


//Функция создания кольца из массива, т.е. перестановка элементов
static int sdvg(int* a, int n, int k) {
	int r = 0;
	for (int i = 0; i < k; i++) {
		r = a[0];
		for (int j = 0; j < n - 1; j++) {
			a[j] = a[j + 1];
		}
		a[n - 1] = r;
	}
	return 0;
}

static int sdvg(int* a, int n, int k, int r) {
	for (int i = 0; i < k; i++) 
	{
		int temp = a[n - 1]; 

		for (int j = n - 2; j >= 0; j--)
		{
			a[j + 1] = a[j];
		}
		a[0] = temp;
	}
	return 0;
}
