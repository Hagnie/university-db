#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int, int> extended_gcd(int a, int b)
{
		if (a == 0) {
				return make_tuple(b, 0, 1);
		}

		int gcd, x, y;

		tie(gcd, x, y) = extended_gcd(b % a, a);

		return make_tuple(gcd, (y - (b/a) * x), x);
}

int main()
{
	unsigned int a, n;
	cout << "Enter number a: ";
	cin >> a;
	cout << "Enter number n: ";
	cin >> n;

	tuple<int, int, int> t = extended_gcd(a,n);

	int gcd = get<0>(t);

	if (gcd != 1) {
		cout << "b = 0";
		return 0;
	}
	else{
		int x = get<1>(t);
		cout << "b = " << x;
	}
	return 0;
}