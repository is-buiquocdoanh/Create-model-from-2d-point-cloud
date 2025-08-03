#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 1. Đọc dữ liệu từ file
    ifstream file("D:\\VScode\\Point_cloud\\data\\points.txt");
    if (!file.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return -1;
    }

    vector<Point2f> points;
    float x, y;
    while (file >> x >> y) {
        points.emplace_back(x, y);
    }
    file.close();

    if (points.size() < 3) {
        cerr << "Cần ít nhất 3 điểm để tạo convex hull." << endl;
        return -1;
    }

    // 2. Tìm bounding box
    float minX = points[0].x, minY = points[0].y;
    float maxX = points[0].x, maxY = points[0].y;
    for (auto& pt : points) {
        minX = min(minX, pt.x);
        minY = min(minY, pt.y);
        maxX = max(maxX, pt.x);
        maxY = max(maxY, pt.y);
    }

    // 3. Tạo ảnh
    int width = 800, height = 800;
    Mat image(height, width, CV_8UC3, Scalar(255, 255, 255));

    auto scaleX = [&](float x) { return (int)((x - minX) / (maxX - minX) * (width - 40) + 20); };
    auto scaleY = [&](float y) { return (int)((y - minY) / (maxY - minY) * (height - 40) + 20); };

    // 4. Vẽ điểm
    for (auto& pt : points) {
        circle(image, Point(scaleX(pt.x), height - scaleY(pt.y)), 3, Scalar(0, 0, 255), FILLED);
    }

    // 5. Tìm và vẽ convex hull
    vector<int> hull;
    convexHull(points, hull, true, false);  // Sửa ở đây!

    for (size_t i = 0; i < hull.size(); ++i) {
        Point2f pt1 = points[hull[i]];
        Point2f pt2 = points[hull[(i + 1) % hull.size()]];
        line(image,
            Point(scaleX(pt1.x), height - scaleY(pt1.y)),
            Point(scaleX(pt2.x), height - scaleY(pt2.y)),
            Scalar(0, 255, 0), 2);
    }

    // 6. Hiển thị
    imshow("Convex Hull Visualization", image);
    waitKey(0);
    return 0;
}
