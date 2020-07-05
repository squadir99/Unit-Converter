/*
Author: Sohail Quadir
Date: 11/11/19
Purpose: The purpose of this program is to convert either length or weight values from US units to metric units and vice versa. 
Sources of Help: None 
Time Spent: 12 hours
*/

#include <stdio.h>
void convertLengths();
void convertWeight();

void lengthToMetric(int* startingFeet, double* startingInches);
void readLengthUS(int* startingFeet, double* startingInches);
void convertLengthToMetric(int* startingFeet, double* startingInches, int* finalMeters, float* finalCM);
void outputLengthMetric(int* startingFeet, double* startingInches, int* finalMeters, float* finalCM);


void lengthToUS(int* startingMeters, double* startingCM);
void readLengthMetric(int* startingMeters, double* startingCM);
void convertLengthToUS(int* startingMeters, double* startingCM, int* pfinalFeet, float* pfinalInches);
void outputLengthUS(int* startingMeters, double* startingCM, int* pfinalFeet, float* pfinalInches);

void weightToMetric(int* pstartingPounds, float* pstartingOunces);
void readWeightUS(int* pstartingPounds, float* pstartingOunces);
void convertWeightToMetric(int* pstartingPounds, float* pstartingOunces, int* pfinalKG, float* pfinalG);
void outputWeightMetric(int* pstartingPounds, float* pstartingOunces, int* pfinalKG, float* pfinalG);


void weightToUS(int* pstartingKG, float* pstartingG);
void readWeightMetric(int* pstartingKG, float* pstartingG);
void convertWeightToUS(int* pstartingKG, float* pstartingG, int* pfinalPounds, float* pfinalOunces);
void outputWeightUS(int* pstartingKG, float* pstartingG, int* pfinalPounds, float* pfinalOunces);
int main(int argc, char* argv[]) {
	int userInput;
	do { //This do while loop continues to ask the user to choose from 1, 2, or 0, until they select 0. 
		
		printf("1. Convert lengths\n");
		printf("2. Convert weights\n");
		printf("0. Exit\n");
		printf("Please choose from (1, 2, 0):\n");
		scanf_s("%d", &userInput);

		if (userInput == 1) { //Checks to see if the user entered 1, and calls the convert lengths function. 
			convertLengths();
		}
		else if (userInput == 2) { //Checks to see if user entered 2, and if they did calls the convert weight function. 

			convertWeight();
		}

	} while (userInput != 0); //continue unless user enters 0, then end the program. 

	if (userInput == 0) { //Lets the user know that they exited. 
		printf("User chose to exit\n");
	}


	return 0;
}
void convertLengths() { //Asks user if they want to convert from m/cm to ft/in. or vice versa 
	int lengthInput;

	int startingFeet = 0;
	int* pStartingFeet = &startingFeet;
	double startingInches = 0;
	double* pStartingInches = &startingInches;

	int startingMeters = 0;
	int* pStartingMeters = &startingMeters;
	double startingCM = 0;
	double* pStartingCM = &startingCM;
	printf("1. Convert lengths from feet/inches to meters/centimeters\n");
	printf("2. Convert lengths from meters/centimeters to feet/inches\n");
	printf("0. Return to Main Menu.\n");
	printf("Please choose from (1, 2, or 0):\n");
	scanf_s("%d", &lengthInput);

	if (lengthInput == 1) {
		lengthToMetric(pStartingFeet, pStartingInches);
	}
	else if (lengthInput == 2) {
		lengthToUS(pStartingMeters, pStartingCM);
	}
	else if (lengthInput == 0) {
		printf("User chose to return to the main menu.\n");
		return;
	}
	else {
		printf("Enter either 1, 2, or 0;\n");
		return;
	}
}

void convertWeight() {
	//Lets the user know that they want to convert weights. 
	int weightInput;

	int startingPounds = 0;
	float startingOunces = 0.00;
	int* pstartingPounds = &startingPounds;
	float* pstartingOunces = &startingOunces;

	int startingKG = 0;
	float startingG = 0.00;
	int* pstartingKG = &startingKG;
	float* pstartingG = &startingG;
	printf("1. Convert weights from pounds/ounces to kilograms/grams.\n");
	printf("2. Convert weights from kilograms/grams to pounds/ounces.\n");
	printf("0. Return to Main Menu.\n");
	printf("Please choose from (1, 2, or 0):\n");
	scanf_s("%d", &weightInput);

	if (weightInput == 1) {
		weightToMetric(pstartingPounds, pstartingOunces);
	}
	else if (weightInput == 2) {
		weightToUS(pstartingKG, pstartingG);
	}
	else if (weightInput == 0) {
		printf("User chose to return to the main menu.\n");
		return;
	}
	else {
		printf("Enter either 1, 2, or 0.\n");
		return;
	}
}

void lengthToMetric(int* startingFeet, double* startingInches) { //Reads length in feet and inches and converts to meters/cm.
	int finalMeters = 0;
	float finalCM = 0.00;
	int* pfinalMeters = &finalMeters;
	float* pfinalCM = &finalCM;

	readLengthUS(startingFeet, startingInches);
	convertLengthToMetric(startingFeet, startingInches, pfinalMeters, pfinalCM);
	outputLengthMetric(startingFeet, startingInches, pfinalMeters, pfinalCM);
	//convertLengths(); //Calling convertLengths allows us to keep asking the user 

}

void lengthToUS(int* pstartingMeters, double* pstartingCM) { //Converts inputted length in meters to US
	int finalFeet = 0;
	float finalInches = 0.00;
	int* pfinalFeet = &finalFeet;
	float* pfinalInches = &finalInches;

	readLengthMetric(pstartingMeters, pstartingCM);
	convertLengthToUS(pstartingMeters, pstartingCM, pfinalFeet, pfinalInches);
	outputLengthUS(pstartingMeters, pstartingCM, pfinalFeet, pfinalInches);

	//convertLengths();

}

void weightToMetric(int* pstartingPounds, float* pstartingOunces) { //US --> Metric (Lbs./Oz --> kg/g)
	int finalKG = 0;
	float finalG = 0.00;
	int* pfinalKG = &finalKG;
	float* pfinalG = &finalG;

	readWeightUS(pstartingPounds, pstartingOunces);
	convertWeightToMetric(pstartingPounds, pstartingOunces, pfinalKG, pfinalG);
	outputWeightMetric(pstartingPounds, pstartingOunces, pfinalKG, pfinalG);
	//convertWeight();
}

void weightToUS(int* pstartingKG, float* pstartingG) { //Metric --> US (Kg/g --> lbs/oz.)
	int finalPounds = 0;
	float finalOunces = 0.00;
	int* pfinalPounds = &finalPounds;
	float* pfinalOunces = &finalOunces;

	readWeightMetric(pstartingKG, pstartingG);
	convertWeightToUS(pstartingKG, pstartingG, pfinalPounds, pfinalOunces);
	outputWeightUS(pstartingKG, pstartingG, pfinalPounds, pfinalOunces);
	//convertWeight();
}

void readLengthUS(int* startingFeet, double* startingInches) { //reads length in US and stores in value of feet and inches into the variables via pointer. 
	printf("Enter feet and inches (separated by a space):\n");
	scanf("%d %lf", &*startingFeet, &*startingInches);
}

void convertLengthToMetric(int* startingFeet, double* startingInches, int* pfinalMeters, float* pfinalCM) { //Does the conversion of US to Metric
	double totalUSLength = (*startingFeet * 12) + (*startingInches);
	double totalUSLengthInMeters = ((totalUSLength / 12) * .3048);
	int meters = 0;
	float cm = 0; 
	while (totalUSLengthInMeters > 1) {
		--totalUSLengthInMeters;
		++meters;
	}
	if (totalUSLengthInMeters < 1 && totalUSLengthInMeters > 0) {
		cm = totalUSLengthInMeters * 100;
	}
	*pfinalMeters = meters;
	*pfinalCM = cm;
}

void outputLengthMetric(int* startingFeet, double* startingInches, int* pfinalMeters, float* pfinalCM) { //Prints result to terminal
	int feet = *startingFeet;
	double inches = *startingInches;
	int finalMeters = *pfinalMeters;
	float finalCM = *pfinalCM;

	printf("%d feet and %.4f inches converted to %d meters and %.4f centimeters.\n", feet, inches, finalMeters, finalCM);
}

void readLengthMetric(int* startingMeters, double* startingCM) { //reads value in metric units and stores into respective variables
	printf("Enter meters and centimeters (separated by a space):\n");
	scanf("%d %lf", &*startingMeters, &*startingCM);
}

void convertLengthToUS(int* startingMeters, double* startingCM, int* pfinalFeet, float* pfinalInches) { //performs operation to convert metric to US
	double  totalMetricLength = (*startingMeters * 100) + (*startingCM);  //total metric length in cm. 
	int feet = 0;
	float inches = 0.00;
	double inchesPerCM = (12 / 30.48);
	double totalMetricLengthInUS = totalMetricLength * inchesPerCM;

	float trueLengthInMeters = totalMetricLengthInUS / 12;

	while (trueLengthInMeters > 1) {
		--trueLengthInMeters;
		++feet;
	}
	if (trueLengthInMeters < 1 && trueLengthInMeters > 0) {
		inches = (trueLengthInMeters * 12);
	}
	*pfinalFeet = feet;
	*pfinalInches = inches;
}

void outputLengthUS(int* startingMeters, double* startingCM, int* pfinalFeet, float* pfinalInches) { //prints Metric to US conversion. 
	int meters = *startingMeters;
	double CM = *startingCM;
	int feetFinal = *pfinalFeet;
	float InchesAfterArithmetic = *pfinalInches;

	printf("%d meters and %.4f centimeters converted to %d feet and %.4f inches.\n", meters, CM, feetFinal, InchesAfterArithmetic);

}

void readWeightUS(int* pstartingPounds, float* pstartingOunces) { //reads pounds and ounces and stores in respective variables 
	printf("Enter kilograms and grams (separated by a space):\n");
	scanf("%d %f", &*pstartingPounds, &*pstartingOunces);
}

void convertWeightToMetric(int* pstartingPounds, float* pstartingOunces, int* pfinalKG, float* pfinalG) { //performs conversion operation from US to metric
	float totalWeightInOunces = (*pstartingPounds * 16) + (*pstartingOunces); //converts inputted pounds to ounces and initializes to float variable.
	float numOfOuncesPerkg = (16 * 2.2046);
	float kgInTermsOfOunces = totalWeightInOunces / numOfOuncesPerkg;
	int numOfKG = 0;
	float numOfG = 0.00;
	while (kgInTermsOfOunces > 1) {
		--kgInTermsOfOunces;
		++numOfKG;
	}
	if (kgInTermsOfOunces < 1 && kgInTermsOfOunces > 0) {
		numOfG = kgInTermsOfOunces * 1000;
	}
	*pfinalKG = numOfKG;
	*pfinalG = numOfG;
}

void outputWeightMetric(int* pstartingPounds, float* pstartingOunces, int* pfinalKG, float* pfinalG) { //prints us to metric value to terminal. 
	int startingPounds = *pstartingPounds;
	float startingOunces = *pstartingOunces;
	int finalKG = *pfinalKG;
	float finalG = *pfinalG;

	printf("%d pounds and %.4f ounces converted to %d kilograms and %.4f grams.\n", startingPounds, startingOunces, finalKG, finalG);

}

void readWeightMetric(int* pstartingKG, float* pstartingG) { //reads metric values and stores in variables 
	printf("Enter pounds and ounces (separated by a space):\n");
	scanf("%d %f", &*pstartingKG, &*pstartingG);
}

void convertWeightToUS(int* pstartingKG, float* pstartingG, int* pfinalPounds, float* pfinalOunces) { //performs conversion from metric to US
	float ouncesPerG = ((16 * 2.2046) / 1000);
	float totalWeightInG = (*pstartingKG * 1000) + (*pstartingG);
	float totalWeightInOuncesMessy = totalWeightInG * ouncesPerG;

	float totalWeightInPoundsMessy = totalWeightInOuncesMessy / 16;
	int pounds = 0;
	float ounces = 0.00;
	while (totalWeightInPoundsMessy > 1) {
		--totalWeightInPoundsMessy;
		++pounds;
	}
	if (totalWeightInPoundsMessy < 1 && totalWeightInPoundsMessy > 0) {
		ounces = totalWeightInPoundsMessy * 16;
	}
	*pfinalPounds = pounds;
	*pfinalOunces = ounces; 
}

void outputWeightUS(int* pstartingKG, float* pstartingG, int* pfinalPounds, float* pfinalOunces) { //outputs final US value
	int startingKG = *pstartingKG;
	float startingG = *pstartingG;
	int finalPounds = *pfinalPounds;
	float finalOunces = *pfinalOunces;

	printf("%d kilograms and %.4f grams converted to %d pounds and %.4f ounces", startingKG, startingG, finalPounds, finalOunces);
}



/*
Computing I -- COMP.1010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching 
learning experience for students, and as training as a practicing computing professional upon graduation. This practice 
is manifested in the University's Academic Integrity policy. Students are expected to strictly avoid academic dishonesty 
and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined 
therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the 
instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, 
the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.


Date: 11/17/19
Name: Sohail Quadir
*/