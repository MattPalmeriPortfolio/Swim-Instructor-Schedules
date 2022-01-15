#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
//declare functions
void outputSchedule(int instructorFirst[4][4], int instructorSecond[4][4]);
//precondition: instructorFirst and instructorSecond should be arrays of size [4][4];
//both arrays use 0 to indicate available times and 1 to mark busy times;
//postcondition: outputs the instructor's schedules to the screen
void outputFree(int instructorFirst[4][4], int instructorSecond[4][4]);
//precondition: instructorFirst and instructorSecond should be arrays of size [4][4];
//both arrays use 0 to indicate available times and 1 to mark busy times;
//postcondition: outputs the free individual session timeslots (where at least one instructor is free)
void outputGroup(int instructorFirst[4][4], int instructorSecond[4][4]);
//precondition: instructorFirst and instructorSecond should be arrays of size [4][4];
//both arrays use 0 to indicate available times and 1 to mark busy times;
//postcondition: outputs the free group session timeslots (where both instructors are free)
void editSchedule(int instructorFirst[4][4], int instructorSecond[4][4]);
//precondition: instructorFirst and instructorSecond should be arrays of size [4][4];
//both arrays use 0 to indicate available times and 1 to mark busy times.
//postcondition: prompts user to edit a time slot in one of the instructor's schedules; continues until
//the user indicates they are finished.
void fillArray(int multiArray[][4], const int size, std::istream& inStream);
//precondition: inStream is an opened stream; size corresponds to the size of multiArray;
//postcondition: fills the array with values from inStream
void outputArray(int givenArray[][4], const int size, std::ostream& outStream);
//precondition: outStream is an opened stream; size corresponds to the size of givenArray;
//postcondition: fills outStream with values from givenArray.
void positionToSchedule(int firstIndex, int secondIndex);
//given two indexes of an array containing an instructor's schedule, outputs their value for day and time respectively.

//main
int main()
{
	using namespace std;
	//intialize variables
	int menuOption = 0, jeff[4][4]{ {1, 1, 0, 0} , {0, 1, 1, 1} , {0, 1, 1, 0} , {1, 1, 1, 0} };
	int counter = 0, anna[4][4]{ {1, 1, 0, 1} , {0, 1, 0, 1} , {1, 1, 0, 0} , {1, 0, 1, 1} };
	string inFile, outFile;
	ifstream inData;
	ofstream outData;
	//greet user
	cout << "Welcome to Sam's Swimming School's Schedule Summoner.\n";
	//begin program menu loop
	do
	{
		cout << "Main Menu:\n" << "1: Show schedule\n" << "2: Show free individual lessons\n"
			<< "3: Show free group sessions\n" << "4: Edit schedule\n" << "5: Open schedule from file\n"
			<< "6: Save schedule to file\n" << "7: Exit\n" << "Choose an option: ";
		cin >> menuOption;
		switch (menuOption)
		{
		case 1:
			outputSchedule(jeff, anna);
			break;
		case 2:
			outputFree(jeff, anna);
			break;
		case 3:
			outputGroup(jeff, anna);
			break;
		case 4:
			editSchedule(jeff, anna);
			break;
		case 5:
			cout << "Enter the filename for the input file:\n";
			cin >> inFile;
			inData.open(inFile);
			if (inData.fail())
				exit(1);
			else
			{
				fillArray(jeff, 4, inData);
				fillArray(anna, 4, inData);
				inData.close();
			}
			break;
		case 6:
			cout << "Enter the filename for the output file:\n";
			cin >> outFile;
			outData.open(outFile);
			if (outData.fail())
				exit(1);
			else
			{
				outputArray(jeff, 4, outData);
				outData << endl;
				outputArray(anna, 4, outData);
			}
			break;
		case 7:
			exit(0);
		default:
			cout << "Illegal input. Try again.\n";
			break;
		}
	} while (counter == 0);
	return 0;
}

//define functions:
//uses iostream/fstream
void fillArray(int multiArray[][4], const int size, std::istream& inStream)
{
	int next;
	for (int i = 0; i < size && inStream >> next; i++)
	{
		for (int j = 0; j < 4; j++)
			multiArray[i][j] = next;
	}
	return;
}
//uses iostream/fstream
void outputArray(int givenArray[][4], const int size, std::ostream& outStream)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
			outStream << givenArray[i][j] << std::endl;
	}
	return;
}
//uses iostream
void outputSchedule(int instructorFirst[4][4], int instructorSecond[4][4])
{
	using namespace std;
	cout << setw(6) << "Jeff" << setw(10) << "Monday" << setw(10) << "Tuesday" << setw(10) << "Wednesday"
		<< setw(10) << "Thursday" << endl;
	cout << setw(6) << "11-12";
	for (int i = 0; i < 4; i++)
	{
		if (instructorFirst[0][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	cout << setw(6) << "12-1";
	for (int i = 0; i < 4; i++)
	{
		if (instructorFirst[1][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	cout << setw(6) << "1-2";
	for (int i = 0; i < 4; i++)
	{
		if (instructorFirst[2][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	cout << setw(6) << "2-3";
	for (int i = 0; i < 4; i++)
	{
		if (instructorFirst[3][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << "\n\n";
	cout << setw(6) << "Anna" << setw(10) << "Monday" << setw(10) << "Tuesday" << setw(10) << "Wednesday"
		<< setw(18) << "Thursday" << endl;
	cout << setw(6) << "11-12";
	for (int i = 0; i < 4; i++)
	{
		if (instructorSecond[0][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	cout << setw(6) << "12-1";
	for (int i = 0; i < 4; i++)
	{
		if (instructorSecond[1][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	cout << setw(6) << "1-2";
	for (int i = 0; i < 4; i++)
	{
		if (instructorSecond[2][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	cout << setw(6) << "2-3";
	for (int i = 0; i < 4; i++)
	{
		if (instructorSecond[3][i] > 0)
			cout << setw(10) << "X";
		else
			cout << setw(10) << "O";
	}
	cout << endl;
	return;
}
//uses iostream
void outputFree(int instructorFirst[4][4], int instructorSecond[4][4])
{
	using namespace std;
	cout << "Free individual session slots:\n Jeff:\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (instructorFirst[i][j] == 0)
				positionToSchedule(i, j);
		}
	}
	cout << "Anna:\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (instructorSecond[i][j] == 0)
				positionToSchedule(i, j);
		}
	}
	cout << endl;
	return;
}
//uses iostream
void outputGroup(int instructorFirst[4][4], int instructorSecond[4][4])
{
	using namespace std;
	cout << "Free group session timeslots:\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (instructorFirst[i][j] == 0 && instructorSecond[i][j] == 0)
				positionToSchedule(i, j);
		}
	}
	return;
}
//uses iostream
void editSchedule(int instructorFirst[4][4], int instructorSecond[4][4])
{
	using namespace std;
	int instructor, day, session, status;
	do
	{
		cout << "Which instructor's schedule would you like to edit? 1 for Jeff, 2 for Anna\n";
		cin >> instructor;
	} while (instructor < 1 || instructor > 2);
	do
	{
		cout << "Which day? 1 for Monday, 2 for Tuesday, 3 for Wednesday, 4 for Thursday\n";
		cin >> day;
	} while (day < 1 || day > 4);
	do
	{
		cout << "Which session? 1 for 11-12, 2 for 12-1, 3 for 1-2, 4 for 2-3\n";
		cin >> session;
	} while (session < 1 || session > 4);
	do
	{
		cout << "Is this slot free or taken? 1 for free, 2 for taken\n";
		cin >> status;
	} while (status < 1 || status > 2);
	if (instructor == 1)
		instructorFirst[session - 1][day - 1] = (status - 1);
	else //if instructor == 2
		instructorSecond[session - 1][day - 1] = (status - 1);
	return;
}
//uses iostream
void positionToSchedule(int firstIndex, int secondIndex)
{
	using namespace std;
	switch (secondIndex)
	{
	case 0:
		cout << "Monday ";
		break;
	case 1:
		cout << "Tuesday ";
		break;
	case 2:
		cout << "Wednesday ";
		break;
	case 3:
		cout << "Thursday ";
		break;
	default:
		cout << "ERROR ";
		break;
	}

	switch (firstIndex)
	{
	case 0:
		cout << "11-12";
		break;
	case 1:
		cout << "12-1";
		break;
	case 2:
		cout << "1-2";
		break;
	case 3:
		cout << "2-3";
		break;
	default:
		cout << "ERROR";
		break;
	}
	cout << endl;
	return;
}
