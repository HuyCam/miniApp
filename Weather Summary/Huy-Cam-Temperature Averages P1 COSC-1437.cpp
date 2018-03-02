// * Weather Summary
// Author: Huy Cam
// Class: COSC-1437-21642
// Instructor: Julie Hester

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void convertRecordNumber(string, string, string, double &, int &, int &);
void checkMax(string, string &, int &, int);
void checkMin(string, string &, int &, int);
double averageMin(int, int);
double averageMax(int, int);
int main()
{
	string date, prcp, snow, snwd, tmax, tmin, minDate, maxDate;
	double avgMax, avgMin, totalPRCP = 0;
	double precip;		// To hold precipitation in double data type
	int tMax, tMin;		// This to hold tmax tmin in integer data type
	int overallMax = 0;
	int overallMin;
	int count = 0, totalMin = 0, totalMax = 0;
	
	ifstream weatherFile;
	weatherFile.open("WeatherData2017.txt");

	if (!weatherFile)
	{
		cout << "Coudn't open file" << endl;
		return 0;
	}

	// Skip the first record
	getline(weatherFile, date);
	
	// Read the first record and assign overallMin to tMin
	getline(weatherFile, date, '\t');
	getline(weatherFile, prcp, '\t');
	getline(weatherFile, snow, '\t');
	getline(weatherFile, snwd, '\t');
	getline(weatherFile, tmax, '\t');
	getline(weatherFile, tmin);

	convertRecordNumber(prcp, tmax, tmin, precip, tMax, tMin);
	checkMax(date, maxDate, overallMax, tMax);
	overallMin = tMin;
	checkMin(date, minDate, overallMin, tMin);
	count++;
	totalPRCP += precip;
	totalMin += tMin;
	totalMax += tMax;

	// Read the rest of the record
	while (!weatherFile.eof())
	{
		getline(weatherFile, date, '\t');
		getline(weatherFile, prcp, '\t');
		getline(weatherFile, snow, '\t');
		getline(weatherFile, snwd, '\t');
		getline(weatherFile, tmax, '\t');
		getline(weatherFile, tmin);

		convertRecordNumber(prcp, tmax, tmin, precip, tMax, tMin);
		checkMax(date, maxDate, overallMax, tMax);
		checkMin(date, minDate, overallMin, tMin);
		count++;
		totalPRCP += precip;
		totalMin += tMin;
		totalMax += tMax;
	}

	// Calculate average minimum nad average maximum
	avgMin = averageMin(totalMin, count);
	avgMax = averageMax(totalMax, count);

	// Display Summary
	cout << "Overal minumum: " << overallMin << " on " << minDate << endl;
	cout << fixed  << setprecision(2)  << "Average minimum: " << avgMin << endl;
	cout << "Overal maximum: " << overallMax << " on " << maxDate << endl;
	cout << setprecision(2) << "Average maximum: " << avgMax << endl;
	cout << "Total Precipitation: " << totalPRCP << endl;

	return 0;
}

// **********************************************************
// convertRecordNumber will convert string variable to		*
// double or int											*
// **********************************************************
void convertRecordNumber(string prcp, string tmax, string tmin, double &precip, int &tMax, int &tMin)
{
	precip = stod(prcp);
	tMax = stoi(tmax);
	tMin = stoi(tmin);
}

// **********************************************
// checkMax check if the TMAX is overall max	*
// and if that is the overall max, assign date	*
// to maxDate									*
// **********************************************
void checkMax(string date, string &maxDate ,int &overallMax, int tMax)
{	
	if (tMax > overallMax)
	{
		overallMax = tMax;
		maxDate = date;
	}
}

// **********************************************
// checkMin check if the TMAX is overall min	*
// **********************************************
void checkMin(string date, string &minDate, int &overallMin, int tMin)
{
	if (tMin < overallMin )
	{
		overallMin = tMin;
		minDate = date;
	}
}

double averageMin(int totalMin, int count)
{
	return ((totalMin * 1.0)/ count) ;
}

double averageMax(int totalMax, int count)
{
	return ((totalMax * 1.0 )/ count) ;
}
