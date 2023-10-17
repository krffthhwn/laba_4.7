#include <iostream> 
#include <iomanip> 
#include <cmath> 
using namespace std;
int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "atan(x)" << " |"
		<< setw(7) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		n = 0;
		a = x;
		S = a;
		do {
			n++;
			if (((pow(-1, n)) * pow(x, 2 * n + 1)) / (2 * n + 1))
				R = ((2 * n - 1) / (pow(-1, n - 1)) * pow(x, x - 1));
			else
				if ((2 * n - 1) / (pow(-1, n - 1)) * pow(x, x - 1))
					R = (2 * n - 1) * (-1) * pow(x, 2) / (2 * n + 1);
			a *= R;
			S += a;
		} while (abs(a) >= eps);
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << atan(x) << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	return 0;
}