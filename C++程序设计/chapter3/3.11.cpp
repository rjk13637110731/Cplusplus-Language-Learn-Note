# include <iostream>

using namespace std;

int main() {
	
	int i = 1;
	int sum = 0;

	do {
		sum += i;
		i++;
	} while (i <= 100);

	cout << "sum = " << sum << endl;

	return 0;
}
