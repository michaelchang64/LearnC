#include <stdio.h>

#define INCHES_PER_POUND (166)

int main(void) {
    int height, length, width, volume, weight;

    printf("Enter length of box: ");
    scanf("%d", &height);
    printf("Enter width of box: ");
    scanf("%d", &width);
    printf("Enter length of box: ");
    scanf("%d", &length);

    volume = height * length * width;
    weight = (volume + 165) / INCHES_PER_POUND;

    printf("Volume (cubic inches):\t\t%d\n", volume);
    printf("Dimensional weight (pounds): \t%d\n", weight);

    return 0;
}
