#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int N; //0 < N < 500
int A , B;
int prices[500];
int routes[500][500];

int getLowest() {
	int currentLowestPrice = 1001;
	int found = 0;
	int hasOne = -1;
	for (int i = 0; i < N; i++) {
		found = distance(routes[i] , find(routes[i] + 1 , routes[i] + (routes[i][0] + 1) , B));
//		cout << "Loc. Index: " << found << endl;
		hasOne = distance(routes[i], find(routes[i] + 1 , routes[i] + (routes[i][0] + 1) , A));
		if (found < routes[i][0] + 1 && hasOne < routes[i][0] + 1 && hasOne < found) {
//			cout << "Price " << i << ": " << prices[i] << endl;
			if (prices[i] < currentLowestPrice) { currentLowestPrice = prices[i]; }
		}
	}
	if (currentLowestPrice == 1001) { return -1; }
	else {return currentLowestPrice;}
}

int main() {
	ifstream fin("cowroute.in");
	fin >> A;
	fin >> B;
	fin >> N;
	int temp = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (i % 2 == 0) {
			fin >> prices[i / 2];
			fin >> temp;
			routes[i / 2][0] = temp;
		} else {
			for (int m = 0; m < temp; m++) {
				fin >> routes[(i - 1) / 2][m + 1];
			}
		}
	}
	fin.close();
/*	Verify file:
	cout << A << " " << B << " " << N << endl;
	for (int i = 0; i < N; i++) {
		cout << prices[i] << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int m = 0; m < routes[i][0]; m++) {
			cout << routes[i][m + 1] << " ";
		}
		cout << endl;
	}
*/ //	End Verify
	ofstream fout("cowroute.out");
	int ans = getLowest();
	fout << ans << endl;
	fout.close();
	return 0;
}
