#include <math.h>

double calculateBodyFat(char gender, double neck, double waist, double height, double hip=0) {
    double firstCalc;
    if (gender == 'M') {
        firstCalc = 495 / ( 1.0324 - 0.19077 * log10( waist - neck ) + 0.15456 * log10(height) );
        return (firstCalc - 450);
    }
    else if (gender == 'F') {
        firstCalc = 495 / ( 1.29579 - 0.35004 * log10( waist + hip - neck ) + 0.22100 * log10( height ) );
        return  firstCalc - 450;
    }
    return 0;
}