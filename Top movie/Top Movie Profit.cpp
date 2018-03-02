// This programm will find the movies with the most profit
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	ifstream movieFile;
	int maxGross = 0;
	int gross = 0;
	string title;
	string studio;
	string lifeTimeGross;
	string year;
	string test;
	string largestTitle;

	movieFile.open("Movies.txt");

	if (movieFile.fail())
	{
		cout << "Error! There is no file" << endl;
		return 0;
	}

	// skipt the first record
	getline(movieFile, test);

	while (!(movieFile.eof()))
	{
		getline(movieFile, title, '\t');
		getline(movieFile, studio, '\t');
		getline(movieFile, lifeTimeGross , '\t');
		getline(movieFile, year);

		gross = stoi(lifeTimeGross);

		if (gross > maxGross)
		{
			maxGross = gross;
			largestTitle = title;
		}
	}
		
	movieFile.close();

	// Display result
	cout << "Movie with the highest gross is: " << largestTitle << " with " << maxGross << "$"
		<< endl;
	

	return 0;
}