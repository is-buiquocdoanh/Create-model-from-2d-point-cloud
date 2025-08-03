# 2D Point Cloud Visualization with Convex Hull

This project demonstrates how to generate and visualize 2D point cloud data using C++ and OpenCV. The visualization includes rendering the points and drawing the **convex hull** that encloses them. The project is educational and suitable for learning basic geometry processing and OpenCV drawing utilities.

## Project Structure
<img width="493" height="190" alt="image" src="https://github.com/user-attachments/assets/1279cc9a-574b-467a-ac42-998f75d767ff" />

## Features

- Generate `n` random 2D points in a user-defined range (default: [0, 1000])
- Save generated points to `data/points.txt`
- Read and visualize the points using OpenCV
- Draw convex hull surrounding the point cloud
- Highlight points and hull edges using color

## Requirements
- C++17 or later
- [OpenCV 4.x](https://opencv.org/releases/)
- C++ compiler:
  - g++ (Linux)
  - MSVC or clang++ (Windows/macOS)
## Build and Run
### 1. Compile and Run Point Generator

```bash
g++ create_point.cpp -o create_point
./create_point
```
This generates a points.txt file in the data/ directory.
<img width="717" height="495" alt="image" src="https://github.com/user-attachments/assets/75741154-9136-41de-aba0-f57a398b094b" />

### 2. Compile and Run Visualizer
```bash
g++ point_cloud.cpp -o point_cloud `pkg-config --cflags --libs opencv4`
./point_cloud
```
The program will open a window showing all points and the convex hull drawn in green.
<img width="674" height="674" alt="image" src="https://github.com/user-attachments/assets/8a1640ce-4128-4db1-8087-7e00e148ee69" />

## Author
- Name: BUI QUOC DOANH
- GitHub: [is-buiquocdoanh](https://github.com/is-buiquocdoanh)
- Email: doanh762003@gmail.com
