#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	float sales[5][6] = { 0 };
	int i, j, price;
	cout << "銷售人員(1/2/3/4)-1->end:";
	while (cin >> i) {
		if (i != -1) {
			cout << "輸入商品(1/2/3/4):";
			cin >> j ;
			cout << "輸入數量:";
			cin>> price;
			sales[i][j] = price;
			cout << "銷售人員(1/2/3/4)-1->end:";
		}
		else break;
	}
	float sum[5] = {};
	float total[6] = {};
	for (int a = 1; a < 5; a++) {
		for (int b = 1; b < 6; b++) {
			sum[a] += sales[a][b];
		}
	}
	for (int a = 1; a < 6; a++) {
		for (int b = 1; b < 5; b++) {
			total[a] += sales[b][a];
		}
	}

	cout << fixed << setprecision(2) << " " << "\t" << "1" << "\t" << "2" << "\t" << "3" << "\t" << "4""\t" << "5" << "\t" << "Total" << endl;
	cout << fixed << setprecision(2) << "1" << "\t" << sales[1][1] << "\t" << sales[1][2] << "\t" << sales[1][3] << "\t" << sales[1][4] << "\t" << sales[1][5] << "\t" << sum[1] << endl;
	cout << fixed << setprecision(2) << "2" << "\t" << sales[2][1] << "\t" << sales[2][2] << "\t" << sales[2][3] << "\t" << sales[2][4] << "\t" << sales[2][5] << "\t" << sum[2] << endl;
	cout << fixed << setprecision(2) << "3" << "\t" << sales[3][1] << "\t" << sales[3][2] << "\t" << sales[3][3] << "\t" << sales[3][4] << "\t" << sales[3][5] << "\t" << sum[3] << endl;
	cout << fixed << setprecision(2) << "4" << "\t" << sales[4][1] << "\t" << sales[4][2] << "\t" << sales[4][3] << "\t" << sales[4][4] << "\t" << sales[4][5] << "\t" << sum[4] << endl;
	cout << endl;
	cout << fixed << setprecision(2) << "Total" << "\t" << total[1] << "\t" << total[2] << "\t" << total[3] << "\t" << total[4] << "\t" << total[5] << endl;

}