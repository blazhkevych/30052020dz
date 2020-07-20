/*
Напишіть програму, яка знаходить найбільше число паліндром, яке
утворюється шляхом множення двох простих п'ятизначних чисел.
Програма має вивести на екран саме число паліндром та два співмножники.
Просте число — це натуральне число, яке має рівно два різних натуральних
дільники (лише 1 і саме число). Послідовність простих чисел починається так:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, …
Паліндром - рядок, що однаково читається в обох напрямках (зліва направо та
справа наліво). Наприклад 11, 12321, А мене нема,..
*/
#include <iostream>
#include <ctime>
using namespace std;

int reverse(long long int num) {
	long long int rev = 0;
	while (num > 0) {
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	return rev;
}
int main()
{
	size_t start_time = clock();
	int max = 99999;
	int count = 0;
	long long int arr[99999]{ 0 };
	bool prime_number;
	cout << "One moment, please ..." << endl;
	for (int i = 10000; i < max; i++) {
		prime_number = true;
		for (int j = 2; j <= sqrt(i); j++)
			if ((i % j) == 0)
				prime_number = false;
		if (prime_number) {
			arr[count] = i;
			count++;
		}
	}
	long long int num;
	long long int max_num = 0;
	int i_max = 0, j_max = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			num = arr[i] * arr[j];
			if (num == reverse(num)) {
				if (num > max_num) {
					max_num = num;
					i_max = i;
					j_max = j;
				}
			}
		}

	}
	cout << arr[i_max] << " * " << arr[j_max] << " = " << max_num << endl;
	size_t end_time = clock();
	size_t search_time = end_time - start_time;
	cout << "seconds are spent on processing = " << (end_time - start_time) / 1000.00 << endl;
}

