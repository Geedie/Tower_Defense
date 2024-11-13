#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <windows.h> // Sử dụng để điều khiển con trỏ trên màn hình console
#include <cmath>
using namespace std;

const int SCREEN_WIDTH = 50;
const int SCREEN_HEIGHT = 20;
const int TOWER_X = 45;       // Tọa độ x của tháp
const int TOWER_Y = 10;       // Tọa độ y của tháp
const int TOWER_RANGE = 10;   // Tầm bắn của tháp
const int BULLET_SPEED = 2;   // Tốc độ di chuyển của đạn
extern mutex screenMutex;


// Đối tượng đạn
class Bullet {
private:
    float x, y;      // Tọa độ hiện tại của đạn
    float dx, dy;    // Tốc độ di chuyển trên trục x và y
    int speed;       // Tốc độ di chuyển của đạn
public:
    float XBull() const;
    float YBull() const;
    // Hàm khởi tạo đạn, từ vị trí bắt đầu đến vị trí mục tiêu
    Bullet(int startX, int startY, int targetX, int targetY, int speed)
        : x(startX), y(startY), speed(speed) {
        // Tính toán vector hướng
        float distanceX = targetX - startX;
        float distanceY = targetY - startY;
        float maxDistance = max(abs(distanceX), abs(distanceY));  // Lấy khoảng cách lớn nhất theo x hoặc y
        dx = (distanceX / maxDistance) * speed; // Tốc độ di chuyển trên trục x
        dy = (distanceY / maxDistance) * speed; // Tốc độ di chuyển trên trục y
    }
    // Di chuyển đạn
    void moveBullet();

    // Kiểm tra nếu đạn nằm ngoài màn hình
    bool outOfBounds() const;
};
