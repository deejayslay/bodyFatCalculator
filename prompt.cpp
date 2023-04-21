#include <iostream>
#include "USNavyFormula.cpp"
#include "BMIformulas.cpp"
#include <string>


// source: https://free-printable-paper.com/body-fat-percentage-chart/
std::string identifyFitnessLevel(double bodyFat, char gender) {
    // male
    std::string fitnessLevel;
    if (gender == 'M') {
        if (bodyFat < 6.0) {
            fitnessLevel = "Essential Fat";
        }
        else if (bodyFat < 14.0) {
            fitnessLevel = "Athlete";
        }
        else if (bodyFat < 18.0) {
            fitnessLevel = "Fitness";
        }
        else if (bodyFat < 25.0) {
            fitnessLevel = "Acceptable";
        }
        else {
            fitnessLevel = "Obesity";
        }
    }
    // female
    else {
         if (bodyFat < 14.0) {
            fitnessLevel = "Essential Fat";
        }
        else if (bodyFat < 21.0) {
            fitnessLevel = "Athlete";
        }
        else if (bodyFat < 25.0) {
            fitnessLevel = "Fitness";
        }
        else if (bodyFat < 32.0) {
            fitnessLevel = "Acceptable";
        }
        else {
            fitnessLevel = "Obesity";
        }
    }
    return fitnessLevel;
}

// source: https://free-printable-paper.com/body-fat-percentage-chart/
std::string identifyHealthyBodyFatForAge(int age, char gender) {
    std::string healthyRange;
    if (gender == 'M') {
        if (20 <= age && age <= 39) {
            healthyRange = "8 - 19%";
        }
        else if (40 <= age && age <= 59) {
            healthyRange = "11 - 21%";
        }
        else if (60 <= age && age <= 79) {
            healthyRange = "13 - 24%";
        }
        else {
            healthyRange = "Information not available for selected age.";
        }
    }
    else {
        if (20 <= age && age <= 39) {
            healthyRange = "21 - 32%";
        }
        else if (40 <= age && age <= 59) {
            healthyRange = "23 - 33%";
        }
        else if (60 <= age && age <= 79) {
            healthyRange = "24 - 35%";
        }
        else {
            healthyRange = "Information not available for selected age.";
        }        
    }
    return healthyRange;
}

double convertToCentimeter(double measurement) {
    return (measurement*2.54);
}

void displayPrompt() {
    char gender;
    int age;
    double neck, waist, height, weight, hip;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gender (M/F): ";
    std::cin >> gender;
    std::cout << "Neck circumference (in inches): ";
    std::cin >> neck;
    std::cout << "Waist circumference (in inches): ";
    std::cin >> waist;
    // hip measurement only for Female
    if (gender == 'F') {
        std::cout << "Hip circumference (in inches): ";
        std::cin >> hip;
        hip = convertToCentimeter(hip);
    }
    std::cout << "Height (in total inches): ";
    std::cin >> height;
    std::cout << "Weight (in pounds): ";
    std::cin >> weight;
    // US Navy Body Fat Calculator
    std::cout << "\nList of Body Fat percentages: \n";
    neck = convertToCentimeter(neck);
    waist = convertToCentimeter(waist);
    height = convertToCentimeter(height);
    double USNBodyFat = calculateBodyFat(gender, neck, waist, height, hip);
    std::cout << USNBodyFat << "% body fat (US Navy)" << std::endl;

    // BMI Body Fat Calculators
    // calculate BMI first
    double BMI = calculateBMI(height, weight);
    // convert gender to integer
    int intGender;
    if (gender == 'M') {
        intGender = 1;
    }
    else {
        intGender = 0;
    }
    // deurenberg formula 1
    double deurenBodyFat = calcDeurenBF(BMI, age, intGender);
    std::cout << deurenBodyFat << "% body fat (Deurenberg)" << std::endl;
    // deurenberg formula 2
    double deuren2BodyFat = calcDeuren2BF(BMI, age, intGender);
    std::cout << deuren2BodyFat << "% body fat (Deurenberg 2)" << std::endl;
    // Gallagher formula
    double gallagBodyFat = calcGallagBF(BMI, age, intGender);
    std::cout << gallagBodyFat << "% body fat (Gallagher)" << std::endl;
    // Jackson-Pollock formula
    double JPBodyFat = calcJPBF(BMI, age, intGender);
    std::cout << JPBodyFat << "% body fat (Jackson-Pollack)" << std::endl;
    // Jackson As formula
    double jacksonAsBodyFat = calcJasBF(BMI, age, intGender);
    std::cout << jacksonAsBodyFat << "% body fat (Jackson As)" << std::endl;

    // calculate average from the list of BF percentages
    double averageBF = (USNBodyFat+deurenBodyFat+deuren2BodyFat+gallagBodyFat+JPBodyFat+jacksonAsBodyFat)/6;
    std::cout << "\nAverage: " << averageBF << "% body fat" << std::endl;

    // identify fitness level
    std::cout << "Fitness Level: " << identifyFitnessLevel(averageBF, gender) << std::endl;

    // identify healthy BF for age
    std::cout << "Healthy Body Fat percentage for a " << age << " year-old " << gender << ": " <<  identifyHealthyBodyFatForAge(age, gender) << std::endl;

}