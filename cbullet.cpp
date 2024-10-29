#include "Bullet.h"


float Bullet::XBull() const {
    return x;
}
float Bullet::YBull() const {
    return y;
}

// Hàm khởi tạo đạn, từ vị trí bắt đầu đến vị trí mục tiêu
void Bullet::moveBullet() {
    x += dx;
    y += dy;
}

// Kiểm tra nếu đạn nằm ngoài màn hình
bool Bullet::outOfBounds() const {
    return x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT;
}
