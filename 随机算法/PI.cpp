#include "liushuo.h"
#include <math.h>

const double MaxX = 10.0;
const double MaxY = 10.0;
const double length = 1.0; //the length of the needle


/*
int main(int argc, char const *argv[])
{
    int i;
    double j;
    double x1, x2, y1, y2;
    double centerX, centerY;
    double sinValue;
    double height;
    double distance;
    double temp;
    int count = 0;
    int PointNum;

    printf("input the numble of the needle:\n");
    scanf("%d", &PointNum);

    srand(time(NULL));
    for (i = 0; i < PointNum; i++) {
        x1 = Randomf(0.0, MaxX);
        x2 = Randomf(0.0, MaxX);
        y1 = Randomf(0.0, MaxY);
        y2 = Randomf(0.0, MaxY);
        centerY = Randomf(0.0, MaxY);
        centerX = Randomf(0.0, MaxX);
        temp = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        distance = sqrt(temp);

        if (distance == 0) {
            i--;
            continue;
        }
        sinValue = fabs(y1 - y2) / distance;
        height = 0.5 * sinValue * length;
        //printf("%lf\n", centerY);
        //printf("%lf\n", height);
        for (j = 0.0; j < 10.1; j += 2 * length) {
            if ((j <= centerY + height) && (j > centerY - height)) {
                count++;
                break;
            } 
        }
    }
    //printf("%d\n", count);
    double result = (double) PointNum / count;
    printf("%lf\n", result);
    return 0;
}
*/
