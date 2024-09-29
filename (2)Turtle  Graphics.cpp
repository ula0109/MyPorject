#include <iostream>
using namespace std;

const int ROW = 21;
const int COL = 21;

int a[ROW][COL] = {  }; // 初始化floor為全0

int main()

{
    int pen_state = 1; // 初始筆的狀態為上
    int row = 0, col = 0; // 初始海龜的位置為(0, 0)
    int direction = 1; // 初始方向為向右
    int distance; // 記錄前進的步數
    int input; // 記錄用戶輸入的指令

    do {
        cout << "Enter command(9 to end input) :";
        cin >> input;

        switch (input) {
        case 1: // 筆設定為上
            pen_state = 1;
            break;

        case 2: // 筆設定為下
            pen_state = 0;
            break;

        case 3: // 向右轉
            direction = (direction + 1) % 4;
            break;

        case 4: // 向左轉
            direction = (direction + 3) % 4;
            break;

        case 5: // 往前移動
            cin >> distance;

            for (int i = 0; i < distance; i++) {
                switch (direction) {
                case 0: // 向上移動
                    if (pen_state == 0 && row != 0) {
                        a[row - i][col] = 1;
                    }

                    break;

                case 1: // 向右移動
                    if (pen_state == 0 && col != 20) {
                        a[row][col + i] = 1;
                    }

                    break;

                case 2: // 向下移動
                    if (pen_state == 0 && row != 20) {
                        a[row + i][col] = 1;
                    }

                    break;

                case 3: // 向左移動
                    if (pen_state == 0 && col != 0) {
                        a[row][col - i] = 1;
                    }
                    break;
                }



            }
            if (direction == 0) {
                row -= distance;
            }
            if (direction == 1) {
                col += distance;
            }
            if (direction == 2) {
                row += distance;
            }
            if (direction == 3) {
                col -= distance;
            }


            break;

        case 6: // 列印出20×20的陣列
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    if (a[i][j] == 1) {
                        cout << "*";
                    }
                    else if (a[i][j] == 0) {
                        cout << " ";
                    }
                }
                cout << endl;
            }

            break;

        case 9: // 結束輸入
             a[ROW][COL] = {  }; // 初始化floor為全0
            break;

        default:
            cout << "無效的指令" << endl;
            break;
        }
    } while (true);
}