#include <iostream> 
#include <cmath>
#include <time.h> 

using namespace std;

static double factorial(double i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}

static double fakefactorial(double n) {
	int k = 1;
	for (int i = 1; i < n; i++)
	{
		k = k * (i + 1);
	}
	return k;
}


static double row_rec(double n, double x) {
	if (n == 0) return x;
	if (n > 0) return (row_rec(n - 1, x)) + pow(x, (2 * n + 1)) / factorial(2 * n + 1);
	// Рекурсия работает до тех пор, пока n не уменьшится до 0
}

static double row_for(double n, double x) {
	double k = x;
	for (int i = 1; i <= n; i++) {
		
		k = k + ((pow(x, (2 * i + 1))) / fakefactorial(2 * i + 1));
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	double n, x;
	cout << "Введите длину ряда и значение x" << endl;
	cin >> n >> x;
	clock_t start = clock();
	cout << row_rec(n, x) << endl;
	clock_t end = clock();
	long double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время выполнения методом рекурсии:  %f секунд\n", seconds);


	start = clock();
	cout << row_for(n, x) << endl;
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время выполнения циклом 'for': % f секунд\n", seconds);

}