#include "cenemy.h"

int Enemy::XEne() const {
    return x;
}
int Enemy::YEne() const {
    return y;
}
// Di chuyển kẻ địch theo đường đi
void Enemy::moveEnemy() {
    if (waypointIndex < path.size()) {      // Kiểm tra còn điểm dừng nào không
        int targetX = path[waypointIndex].first;
        int targetY = path[waypointIndex].second;

        // Tính toán hướng di chuyển
        int dx = targetX - x;
        int dy = targetY - y;

        // Di chuyển từng bước một theo trục x hoặc y
        if (abs(dx) > abs(dy)) {
            x += (dx > 0) ? 1 : -1;
        }
        else {
            y += (dy > 0) ? 1 : -1;
        }

        // Nếu đạt điểm dừng hiện tại, chuyển đến điểm dừng tiếp theo
        if (x == targetX && y == targetY) {
            waypointIndex++;
        }
    }
    else {
        alive = false; // Khi kẻ địch hết điểm dừng, đánh dấu là "chết"
    }
}
