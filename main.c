/*
 * Шарик движется в пространстве ограниченного объёма из начальной точки (x0, y0, z0) с заданной скоростью и отражается от "стенок".
 * Выдать траекторию движения шарика в табличном виде в течение заданного интервала времени.
 * Все параметры (размеры объёма, координаты начальной точки, направление вектора скорости) задаются пользователем в режиме диалога.
 */

#include <stdio.h>

int main(){
    printf("(width, height, depth): ");
    int width, height, depth;
    scanf("%d %d %d", &width, &height, &depth);

    printf("(x, y, z): ");
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    printf("(vx, vy, vz): ");
    int vx, vy, vz;
    scanf("%d %d %d", &vx, &vy, &vz);

    printf("(t): ");
    int t;
    scanf("%d", &t);

    int bounceX = 0, bounceY = 0, bounceZ = 0;

    printf("Траектория движения шарика в течение %d секунд:\n", t);
    printf("t\twidth\theight\tdepth \n");
    for (int i = 0; i <= t; i++){
        printf("%d\t%d\t%d\t%d\n", i, x, y, z);
        printf("\n");
        // x coordinate
        if (bounceX == 0){
            if(x + vx <= width){
                x = x + vx;
            }
            else {
                bounceX = 1;
                x = width - (x + vx - width);
            }
        }
        else {
            if(x - vx >= 0){
                x = x - vx;
            }
            else {
                x = -x + vx;
                bounceX = 0;
            }
        }
        // y coordinate
        if (bounceY == 0){
            if(y + vy <= height){
                y = y + vy;
            }
            else {
                bounceY = 1;
                y = height - (y + vy - height);
            }
        }
        else {
            if(y - vy >= 0){
                y = y - vy;
            }
            else {
                y = -y + vy;
                bounceY = 0;
            }
        }
        // z coordinate
        if (bounceZ == 0){
            if(z + vz <= depth){
                z = z + vz;
            }
            else {
                bounceZ = 1;
                z = depth - (z + vz - depth);
            }
        }
        else {
            if(z - vz >= 0){
                z = z - vz;
            }
            else {
                z = -z + vz;
                bounceZ = 0;
            }
        }
    }
    return 0;
}
