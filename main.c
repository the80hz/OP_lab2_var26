/*
 * Шарик движется в пространстве ограниченного объёма из начальной точки (x0, y0, z0) с заданной скоростью и отражается от "стенок".
 * Выдать траекторию движения шарика в табличном виде в течение заданного интервала времени.
 * Все параметры (размеры объёма, координаты начальной точки, направление вектора скорости) задаются пользователем в режиме диалога.
 *
 */

#include <stdio.h>

int main() {
    printf("Введите размеры объема: ");
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    printf("Введите координаты начальной точки: ");
    int x0, y0, z0;
    scanf("%d %d %d", &x0, &y0, &z0);

    printf("Введите направление вектора скорости: ");
    int vx, vy, vz;
    scanf("%d %d %d", &vx, &vy, &vz);

    printf("Введите интервал времени: ");
    int t;
    scanf("%d", &t);

    printf("Траектория движения шарика в течение %d секунд:\n", t);
    printf("t\tx\ty\tz \n");
    for (int i = 0; i <= t; i++){
        int x1 = x0 + vx * i;
        int y1 = y0 + vy * i;
        int z1 = z0 + vz * i;
        if (x1 > x){
            x1 = x - (x1 - x);
            vx = -vx;
        }
        if (y1 > y){
            y1 = y - (y1 - y);
            vy = -vy;
        }
        if (z1 > z){
            z1 = z - (z1 - z);
            vz = -vz;
        }
        printf("%d\t%d\t%d\t%d\n", i, x1, y1, z1);
    }

    return 0;
}