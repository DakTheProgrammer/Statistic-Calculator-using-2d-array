//Dakota Wilson
//CMPS 1063 - Dr.Colmenares

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void populateMatrix(int [10][10]);
void extractColumn(int [10][10], int [10]);
void showMeTheMatrix(const int [10][10]);
void computeStats(int [10], double &, double &, double &);
double myMeanFx(int [10]);
double myVarFx(int [10], double Mean);
double myStDevFx(double Var);

int main()
{
	int Matrix[10][10], Removed[10];//Declares the 10x10 matrix and the 
	                                //removed column
	double myMean, myVariance, myStDev;

	populateMatrix(Matrix);
	showMeTheMatrix(Matrix);
	extractColumn(Matrix, Removed);
	computeStats(Removed, myMean, myVariance, myStDev);

	cout << "The Mean is: " << myMean << '\n';
	cout << "The Variance is: " << myVariance << '\n';
	cout << "The Standard Deviation is: " << myStDev << '\n';

	system("pause");
	return 0;
}

void populateMatrix(int Matrix[10][10])
{
	int col, row;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			Matrix[row][col] = (rand() % 5) + 1;//Loads the matrix with random
			                                    //intigers from 1-5
		}
	}
}

void extractColumn(int Matrix[10][10], int Removed[10])
{
	int RemCol, row;

	cout << "\nChose a column to extract 0-9: ";
	cin >> RemCol;

	for (row = 0; row < 10; row++)
	{
		Removed[row] = Matrix[row][RemCol];//Puts the values of the column 
		                                   //removed into a new matrix
	}
}

void showMeTheMatrix(const int Matrix[10][10])
{
	int row, col;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			cout << Matrix[row][col] << ' ';//Outputs the 10x10 Matrix
		}
		cout << '\n';
	}
}

void computeStats (int Removed[10], double &myMean, 
	double &myVariance, double &myStDev)
{

	double Mean = myMeanFx(Removed), Var = myVarFx(Removed, Mean);
	//Declares the mean and varince so it can be used in other functions
	
	myMean = myMeanFx(Removed);
	//Finds the mean using removed column and returns to main

	myVariance = myVarFx(Removed, Mean);
	//Finds the variance using removed column and mean and returns to main

	myStDev = myStDevFx(Var);
	// Finds the Standard deviation using variance of previous function and
	//returns to main
}

double myMeanFx(int Removed[10])
{
	int Sum, row;
	double Mean;

	Sum = 0;

	for (row = 0; row < 10; row++)
	{
		Sum += Removed[row];// finds sum of removed array
	}

	Mean = Sum / 10.0;

	return Mean;
}

double myVarFx(int Removed[10] , double Mean)
{
	int row;
	double VarFx, VarArr[10], Sum;//Declares array for sum of new values

	Sum = 0;

	for (row = 0; row < 10; row++)
	{
		VarArr[row] = (Removed[row] - Mean) * (Removed[row] - Mean);
		//(x-mean)^2
	}

	for (row = 0; row < 10; row++)
	{
		Sum += VarArr[row];// finds sum of new values
	}

	VarFx = (Sum / 9);// n-1 = 9

	return VarFx;
}

double myStDevFx(double Var)
{
	double StDev;

	StDev = sqrt(Var);

	return StDev;
}