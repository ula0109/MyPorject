#include<iostream>
#include<vector>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1) {
		cin >> str2;
		vector<vector<int>> length(str1.size()+1, vector<int>(str2.size()+1,0));
		
		for (int i = 1;i <= str1.size(); i++) {
			for (int j = 1; j <= str2.size();j++) {
				if (str1[i-1] == str2[j-1]) {
					length[i][j] = length[i - 1][j - 1] + 1;
				}
				else {
					if (length[i - 1][j] >= length[i][j - 1]) {
						length[i][j] = length[i - 1][j];
					}
					else {
						length[i][j] = length[i][j - 1];
					}
				}
			}
		}
		/*for (int i = 1;i <= str1.size(); i++) {
			for (int j = 1; j <= str2.size();j++) {
				cout << length[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << length[str1.size() ][str2.size() ]<<endl;
	}
	
}