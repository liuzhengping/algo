#include <stdio.h>
#include <conio.h>

#define MeterInch (1.0/39.37)
#define MeterFoot (MeterInch*12.0)
#define MeterYard (MeterFoot*3.0)
#define MeterMile (MeterYard*1760)

int main() {
    float a, meters, inches;
    int yards, feet, miles;
    for(int puta = 1; puta <= 5; puta++) {
        printf("Line #%d: ", puta);
        scanf("%f", &a);
        miles = (int) (a/MeterMile);
        a-=miles*MeterMile;
        yards = (int) (a/MeterYard);
        a-=yards*MeterYard;
        feet = (int) (a/MeterFoot);
        a-=feet*MeterFoot;
        inches = a/MeterInch;
        printf("Output #%d: %d miles, %d, yards, %d feet, and %f inches\n", puta, miles, yards, feet, inches);
    }     
    getch();
    return 0;
}    
