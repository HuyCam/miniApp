// Retrieve a specific day info of weather
// Author: Huy Cam

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void processFile(ifstream&, vector<string> &, vector<double> &, vector<int> &, vector<int> &);
void locateData(const vector<string>&, const vector<double>&, const vector<int>&,
	const vector<int>&, string );
int askWeatherInfo();
int main()
{
	const int SIZE = 365;
	int option;						// To hold the option 
	vector<string> date;
	vector<double> prcp;
	vector<int> highTemp, lowTemp;
	ifstream weather;
	string test;					// this string only for skiping the first record
	string inputDate;				

	date.reserve(SIZE);
	prcp.reserve(SIZE);
	highTemp.reserve(SIZE);
	lowTemp.reserve(SIZE);
	
	weather.open("WeatherData2017.txt");

	if (!weather)
	{
		cout << "Coudn't open file" << endl;
		return 0;
	}

	// Skip the first record
	getline(weather, test);

	// Read all record
	processFile(weather, date, prcp, highTemp, lowTemp);

	// If this file has no record or not even at least one record
	if (date.empty() && prcp.empty() && highTemp.empty() && lowTemp.empty())
	{
		cout << "This file has no record" << endl;
		system("pause");
		return 0;
	}

	// Get option
	option = askWeatherInfo();

	while (option == 1)
	{
		// Ask user to choose specific date
		cout << "Enter the date you want to see precipitation, "
			 << "high temperature and low temperature (month/date/year): ";
		cin >> inputDate;
		locateData(date, prcp, highTemp, lowTemp, inputDate);

		// Get new option
		option = askWeatherInfo();
	}

	cout << "See you later" << endl;

	system("pause");
	return 0;
}

void processFile(ifstream &weather, vector<string>& dateV,
	vector<double> &prcpV, vector<int> &highV, vector<int> &lowV)
{
	string date;
	double prcp;
	int high, low;
	double snow, snwd;
	int i = 0; //Test;
	
	while (!weather.eof())
	{
		weather >> date >> prcp >> snow >> snwd >> high >> low;
		
		dateV.push_back(date);
		prcpV.push_back(prcp);
		highV.push_back(high);
		lowV.push_back(low);
	}
}

void locateData(const vector<string>& date, const vector<double>& prcp, const vector<int>& high,
	const vector<int>& low, string inputDate)
{
	int size = date.size();
	int index = -1;			// hold the index of the specific date in vector

	// Run loop through date vector to find user input date
	for (int i = 0; i < size; i++)
	{
		if (date.at(i) == inputDate)
		{
			index = i;
		}
	}

	// stop function if it can't find input date
	if (index == -1)
	{
		cout << "Sorry, weather info on your desire date isn't available!" << endl;
		return;
	}
	try {
		cout << "Weather info on " << inputDate << " :" << endl;
		cout << setw(15) << left << "Precipitation" << setw(18) << "High Temperature"
			<< setw(17) << "Low Temperature" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << setw(15) << prcp.at(index) << setw(18) << high.at(index)
			<< setw(17) << low.at(index) << endl << endl;
	}
	catch(out_of_range& oor){
		cout << "Out of range error: " << oor.what() << endl;
	}
}

//***************************************
// This ask user to input weather info	*
// and validate that input.				*
// **************************************
int askWeatherInfo()
{
	int option;

	// Ask user if they want to see weather info
	cout << "Chose the option you want\n";
	cout << "1. See specific weather info.\n";
	cout << "2. Quit.\n";
	cin >> option;

	// Validate option
	while (option != 1 && option != 2)
	{
		cout << "Please enter valid option!!" << endl;

		// Ask user if they want to see weather info
		cout << "Chose the option you want\n";
		cout << "1. See specific weather info.\n";
		cout << "2. Quit.\n";
		cin >> option;
	}

	return option;
}
