#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong diem: ";
    cin >> n;

    // Kiểm tra đầu vào
    if (n <= 0) {
        cerr << "So diem phai lon hon 0!" << endl;
        return -1;
    }

    // Mở file để ghi
    ofstream file("D:\\VScode\\Point_cloud\\data\\points.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file de ghi!" << endl;
        return -1;
    }

    // Khởi tạo seed ngẫu nhiên
    srand((unsigned int)time(nullptr));

	file << n << endl; // Ghi số lượng điểm đầu tiên    

    for (int i = 0; i < n; ++i) {
        float x = static_cast<float>(rand() % 1001); // [0,100]
        float y = static_cast<float>(rand() % 1001); // [0,100]
        file << x << " " << y << endl;
    }

    file.close();
    cout << "Da tao " << n << " diem va ghi vao file points.txt" << endl;

    return 0;
}
