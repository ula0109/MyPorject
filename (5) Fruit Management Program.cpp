#include <iostream>
#include<string>
#include<iomanip>
using namespace std;


int record[100] = {  };
string fruit_name[100];
int quantity[100];
float price[100];

void Listallfruits() {
    cout << "Record#" << '\t' << "Fruit name" << '\t' << "Quantity" << '\t' << "Price" << '\n';
    for (int i = 0; i < 100; i++) {
        if (record[i] != 0) {
            cout << fixed << setprecision(2) << record[i] << '\t' << fruit_name[i] << "           " << quantity[i] << "              " << price[i] << endl;
        }
    }
}
bool inlistornot(int Record) {
    for (int i = 0; i < 100; i++) {
        if (record[i] == Record)return true;
    }
    return false;
}
/*int whereinlist(int Record) {
    for (int i = 0;i < 100;i++) {
        if (record[i] == Record)return i;
    }
}*/
void Updaterecord() {
    int n = 0, newquantity = 0;
    float newprice = 0;
    string newfruit;
    cin >> n;
    if (record[n - 1] == 0) {
        cout << "Cannot update.The record is empty." << endl;
    }
    else {
        cout << "Record#" << '\t' << "Fruit name" << '\t' << "Quantity" << '\t' << "Price" << '\n';
        cout << fixed << setprecision(2) << record[n] << '\t' << fruit_name[n] << "           " << quantity[n] << "              " << price[n] << endl;
        cout << "Enter the fruit name :";
        cin >> newfruit;
        cout << "Enter quantity and price:";
        cin >> newquantity >> newprice;
        cout << "Record update" << endl;
        fruit_name[n - 1] = newfruit;
        quantity[n - 1] = newquantity;
        price[n - 1] = newprice;
        record[n - 1] = n;
    }
}
/* void fruitprint(int Record) {
     cout << "Record#" << '\t' << "Fruit name" << '\t' << "Quantity" << '\t' << "Price" << '\n';
     cout << record[Record] << '\t' << fruit_name[Record] << '\t' << quantity[Record] << '\t' << price[Record] << endl;
 }*/
void Insertrecord() {
    int n = 0, newquantity = 0;
    float newprice = 0;
    string newfruit;
    cout << "Enter the fruit number for insertion:";
    cin >> n;
    if (inlistornot(n)) {
        cout << "Cannot insert.The record contains information." << endl;
    }
    else {
        cout << "Enter the fruit name:";
        cin >> newfruit;
        cout << "Enter quantity and price:";
        cin >> newquantity >> newprice;
        cout << "Record inserted." << endl;
        fruit_name[n - 1] = newfruit;
        quantity[n - 1] = newquantity;
        price[n - 1] = newprice;
        record[n - 1] = n;
    }
}
void Deleterecord() {
    int n = 0;
    cout << "Enter the fruit number for deletion:";
    cin >> n;
    if (inlistornot(n)) {
        record[n - 1] = 0;
    }
    else {
        cout << "Cannot delete.The record is empty" << endl;
    }
}

int main()
{
    int choice = 0;
    while (choice != 5) {
        cout << "1 List all fruits." << endl << "2 Update record." << endl << "3 Insert record." << endl << "4 Delete record" << endl << "5 End program." << endl << "Enter choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            Listallfruits();
            break;
        case 2:
            Updaterecord();
            break;
        case 3:
            Insertrecord();
            break;
        case 4:
            Deleterecord();
            break;
        case 5:
            cout << "Bye!" << endl;
        }
    }

}
