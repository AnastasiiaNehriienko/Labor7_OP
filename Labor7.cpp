#include <iostream>
using namespace std;
void input_B(int*, int); //Задання масиву
void output_B(int*, int); //Виведення масиву
int input_z();  //задання числа z
int input_n();  //задання числа n
int count(int*, int, int);  //Розрахунок максимального та його номеру в ряду, кількості чисел, менших за z.
void new_range(int*, int, int); //перестановка першого та max елементів 
int main() {
	int B[10]; //вихідний масив
	int n = input_n();  //число n
	int z = input_z();  //число z
	int max;
	input_B(B, n);
	output_B(B, n);
	max=count(B, z, n);
	new_range(B, n, max);
	return 0;
}

void input_B(int *p, int n){
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		*p = rand() % 19 - 9;  //генерування масиву
		p++;
	}
}
void output_B(int *t, int n) {
	cout << "B:\n";
	for (int i = 0; i < n; i++)
		printf("%4d", *(t + i));  //виведення массиву
	printf("\n");
}
int input_z() {
	int z;
	cout << "Enter z: ";
	cin >> z;
	return z;
}
int input_n() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	return n;
}
int count(int *t, int z, int n) {
	int maximum = -10;  //максимальне число з менших за z
	int i_max=-1;  //його номер
	int N = 0;  //кількість чисел, менших за z
	for (int i = 0; i < n; i++) {
		if (*(t+i) < z) {
			N++;
			if (*(t+i) > maximum) {
				maximum = *(t+i);
				i_max = i;
			}
		}
	}
	cout << "Amount is: " << N << "\nMax=" << maximum << "\nIts number: " << i_max + 1 << "\n";
	return i_max;
}
void new_range(int *t, int n, int max) {
	cout << "New B:\n";  
	if (max + 1) {
		printf("%4d", *(t + max));//виведення обраного числа першим
		for (int i = 1; i < n; i++) {
			if (i == max)
				printf("%4d", *t);  //виведення першого на місці обраного
			else printf("%4d", *(t + i));
		}
		printf("\n");
	}
}
