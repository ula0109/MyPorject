 #include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string line;
    cout << "Enter a line of text: ";
    getline(cin, line);

    stringstream ss(line);
    string token;
    vector<string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    sort(tokens.begin(), tokens.end());

   cout << "The tokens in sorted order are:\n";
    for (const auto& t : tokens) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
