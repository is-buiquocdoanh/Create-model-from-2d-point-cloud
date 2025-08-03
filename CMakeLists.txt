cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Point_cloud")

# C++17 là đủ
set(CMAKE_CXX_STANDARD 17)

# Đường dẫn OpenCV của bạn
set(OpenCV_DIR "C:/opt/opencv/build/x64/vc16/lib")

# Tìm OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Tạo executable
add_executable(Point_cloud "Point_cloud.cpp" "Point_cloud.h")
add_executable(create_point create_point.cpp)
add_executable(convex_hull convex_hull.cpp)


# Liên kết với thư viện OpenCV
target_link_libraries(Point_cloud ${OpenCV_LIBS})
