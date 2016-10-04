#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//Prototype for sum function
void listMaxMinAvg(ifstream& inputFile, ofstream& outputFile);

int main()
{
	//Create variables with type streams
	ifstream in_stream; //Created an ifstream variable called in_stream that will be the stream name for the input
	ofstream out_stream; //Created an ofstream variable called out_stream that will take care of the output

	in_stream.open("HW6Prob2In.dat"); //Using the stream file name, it opens and assigns the file to stream file name

	//Check to see if file open correctly
	if (in_stream.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	out_stream.open("HW6Prob2Out.dat"); //This will check for the file and if doesn't exist, create it.
	//Check to see if output file opened correctly
	if (out_stream.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	//Function that sums the values
	listMaxMinAvg(in_stream, out_stream);

	in_stream.close();
	out_stream.close();

	return 0;
}

/*******************************************************
Name            :   listMaxMinAvg(ifstream& inputFile, ofstream& outputFile)
Arguments       :   double next, max, total, min, avg
					int counter
Returns         :   None
Precondition    :   inputFile and outputFile must be opened successfully
Postcondition   :   Will calculate max, min and avg as it parses through
					the text file. It will display to screen the final results
					as well as print to outputFile.
*******************************************************/
void listMaxMinAvg(ifstream& inputFile, ofstream& outputFile)
{
	double next, max = 0.0, total = 0.0, min = 0.0, avg = 0.0;
	int counter = 0;
	//While there is still a value in the next line
	while (inputFile >> next)
	{
		total += next;
		counter++;
		if (next > max)
		{
			max = next;
		}
		else if (next < min)
		{
			min = next;
		}
	}

	avg = total / counter;

	outputFile.setf(ios::fixed);
	outputFile.setf(ios::showpoint);
	outputFile.precision(2);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//Output the total to an output file
	cout << "The max number is: " << max << endl
		<< "The min number is: " << min << endl
		<< "The average number is: " << avg << endl;
	outputFile << "The max number is: " << max << endl
		<< "The min number is: " << min << endl
		<< "The average number is: " << avg << endl;
}

/*
Name			:	homework2
Arguements		:	ifstream& inputFile, ofstream& outputFile
					double next, max, total, min, avg;
					int counter;
Return			:	0
Definition		:	A function that returns the max, min and average and displays them
					to screen and outputs results to a dat file
*/