#include <iostream>
using namespace std;

bool isLoShuMagic(int square[3][3]) {
    int sumRows[3] = {0};
    int sumCols[3] = {0};
    int diagonal1 = 0;
    int diagonal2 = 0;

    // Tính tổng của các hàng, cột và đường chéo.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumRows[i] += square[i][j];
            sumCols[j] += square[i][j];
            if (i == j) {
                diagonal1 += square[i][j];
            }
            if (i + j == 2) {
                diagonal2 += square[i][j];
            }
        }
    }

    // Kiểm tra tổng của các hàng, cột và đường chéo.
    if (sumRows[0] == sumRows[1] && sumRows[1] == sumRows[2] &&
        sumRows[2] == sumCols[0] && sumCols[0] == sumCols[1] &&
        sumCols[1] == sumCols[2] && sumCols[2] == diagonal1 &&
        diagonal1 == diagonal2 && diagonal2 == 15) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int square[3][3];

    // Nhập ma trận.
    cout << "Nhap ma tran 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> square[i][j];
        }
    }

    // Kiểm tra ma trận Lo Shu Magic.
    if (isLoShuMagic(square)) {
        cout << "Day la ma tran Lo Shu Magic.\n";
    } else {
        cout << "Day khong phai la ma tran Lo Shu Magic.\n";
    }

    return 0;
}