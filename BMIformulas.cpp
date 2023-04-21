#include <math.h>

// source: https://www.cdc.gov/healthyweight/assessing/bmi/childrens_BMI/childrens_BMI_formula.html
double calculateBMI(double height, double weight) {
    double BMI = 703 * (weight/pow(height/2.54, 2));
    return BMI;
}

// source: https://globalrph.com/medcalcs/estimation-of-total-body-fat/

// Deurenberg formula
double calcDeurenBF(double BMI, int age, int gender) {
    double bodyFat = (1.20 * BMI) + (0.23*age) - (10.8*gender) - 5.4;
    return bodyFat;
}

// Deurenberg formula 2
double calcDeuren2BF(double BMI, int age, int gender) {
    double bodyFat = (1.29 * BMI) + (0.20*age) - (11.4*gender) - 8.0;
    return bodyFat;
}

// Gallagher formula
double calcGallagBF(double BMI, int age, int gender) {
    double bodyFat = (1.46*BMI) + (0.14*age) - (11.6*gender) - 10;
    return bodyFat;
}

// Jackson-Pollock formula
double calcJPBF(double BMI, int age, int gender) {
    double bodyFat = (1.61*BMI) + (0.13*age) - (12.1*gender) - 13.9;
    return bodyFat;
}

// Jackson As formula
double calcJasBF(double BMI, int age, int gender) {
    double bodyFat = (1.39*BMI) + (0.16*age) - (10.34*gender) - 9;
    return bodyFat;
}