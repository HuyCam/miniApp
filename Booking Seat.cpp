/*
	This Programm is to book a seat in the Theater.
	Author:	Huy Cam.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Global variable
const int COLLUMN = 9;
const int ROW = 7;
//Prototype
bool validateSeatAddress(char[]);
void convertLetterToNumber(char[], char[], char[], int);
void reservation(char[], char[][COLLUMN]);
bool checkSeatAvailable(char[], char[][COLLUMN], char[], int);
int seatQC( char [][COLLUMN], int);
int main()
{
	
	int seatQuantities;
	int i = 0;
	int j = 0;
	int seatQAvail;
	char letter[ROW] = { 'A','B','C','D','E','F','G' };
	char number[ROW] = { '0','1','2','3','4','5','6'};
	char seatMap[ROW][COLLUMN];
	char seatAddress[3];
	char answer;
	bool seatStatus = false;
	bool cond;
	

	// Create seatMap
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLLUMN; j++)
		{
			seatMap[i][j] = '0';
		}
	}
	cout << "WELCOME TO HUY CAM'S THEATER" << endl;
	// Ask users if they want to make a reservation
	cout << "Do you want to make a reservation? Y/N" << endl;
	cin >> answer;

	
	while (toupper(answer) == 'Y')
	{
		// Rendering seatMap
		for (i = 1; i <= COLLUMN; i++)
		{
			cout << "\t" << i;
		}
		cout << endl;

		for (i = 0; i < ROW; i++)
		{
			cout << letter[i];
			for (j = 0; j < COLLUMN; j++)
			{
				cout << "\t" << seatMap[i][j];
			}
			cout << endl;
		}

		// Ask number of seat
		cout << "How many seat you want to reserve?" << endl;
		cin >> seatQuantities;

		// Check input type
		cond = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		// Validate seatQuantities
		seatQAvail = seatQC( seatMap, ROW);
		
		// Check available quantities
		if (seatQAvail == 0)
		{
			cout << "No more seat available." << endl;
			exit(1);
		}
		while (cond)
		{
			cout << "Re-enter your number of seats: " << endl;
			cin >> seatQuantities;

			cond = cin.fail();

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		// Validate seatQuantities input range
		while (seatQuantities <= 0 || seatQuantities > seatQAvail)
		{
			cout << "Your seat muss larger than 0 and lesser than " << seatQAvail << endl;
			cout << "Please re-enter number of seats you wanted: " << endl;
			cin >> seatQuantities;
		}

		// Ask seatAddress
		for (int q = 1; q <= seatQuantities; q++)
		{
			cout << "Select your seat " << q << ": ";
			cin >> seatAddress;
			cout << endl;

			// Validate Seat Address
			while (!validateSeatAddress(seatAddress))
			{
				cout << "Your seat address must be within the map!";
				cout << "Please re-enter your seat address: ";
				cin >> seatAddress;
			}

			// Converting seatAddress
			convertLetterToNumber(seatAddress, letter, number, ROW);

			// Reservation process
			seatStatus = checkSeatAvailable(seatAddress, seatMap, letter, ROW);
			while (!seatStatus)
			{
				cout << "This seat is already reserved. ";
				cout << "Select another seat " << q << ": ";
				cin >> seatAddress;
				
				// Validate Seat Address
				while (!validateSeatAddress(seatAddress))
				{
					cout << "Your seat address must be within the map!";
					cout << "Please re-enter your seat address: ";
					cin >> seatAddress;
				}

				cout << endl; // Rendering clearance

				// Converting seatAddress
				convertLetterToNumber(seatAddress, letter, number, ROW);

				seatStatus = checkSeatAvailable(seatAddress, seatMap, letter, ROW);
				
			}
			// Making reservation
			reservation(seatAddress, seatMap);
		}

		// Ask for another reservation
		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Do you want to make another reservation? Y/N" << endl;
		cin >> answer;
	}
	
	return 0;
}
// ******************************************************
// checkSeatAvailable check if the seat user selected	*
// is available											*
// ******************************************************
bool checkSeatAvailable(char seatAddress[], char seatMap[][COLLUMN], char letter[], int row)
{
	int seatR = seatAddress[0] - '0';
	int seatC = seatAddress[1] - '0';

	if (seatMap[seatR][seatC] == 'X')
	{
		return false;
	}

	cout << "Seat is available. Processing reservation.." << endl;
	return true;
}

// ******************************************************
// convertLetterToNumber will convert a seatLetter to	*
// a number												*
// ******************************************************
void convertLetterToNumber(char seatAddress[], char letter[], char number[], int ROW)
{
	int seatC = static_cast<int>(seatAddress[1]) - 1;
	seatAddress[1] = static_cast<char>(seatC);
	for (int i = 0; i < ROW; i++)
	{
		if (seatAddress[0] == letter[i])
			seatAddress[0] = number[i];
	}
}

void reservation(char seatAddress[], char seatMap[][COLLUMN])
{
	int seatR = seatAddress[0] - '0';
	int seatC = seatAddress[1] - '0';
	seatMap[seatR][seatC] = 'X';
	cout << "Reservation for seat " << seatAddress[0] << seatAddress[1] << " is done." << endl << endl;
}

// **************************************************
// Validate seatAddress will validate input as this	*
// format [A-G][1-9]								*
// **************************************************
bool validateSeatAddress(char seatAddress[])
{
	seatAddress[0] = toupper(seatAddress[0]);
	if (seatAddress[0] < 'A' || seatAddress[0] > 'G' || seatAddress[1] < '1' || seatAddress[1] > '9')
	{
		return false;
	}

	return true;
}

// **************************************************
// seatQC will count how many available seats		*
//  available										*
// **************************************************
int seatQC(char seatMap[][COLLUMN], int row)
{
	int count = 0;
	int i;
	int j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < COLLUMN; j++)
		{
			if (seatMap[i][j] == '0')
				count++;
		}
	}
	return count;
}