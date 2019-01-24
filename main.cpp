#include <iostream>
#include "DataFrame.h"
#include "string.h"
using namespace std;

char *readUntil(char delim) {
	int len = 0, max = 80;
	char *ret = new char[max];
	while (1) {
		int c = cin.get();
		if (c == -1) {
			cerr << "Unexpected EOF!" << endl;
			c = delim;
		}
		if (c == delim) {
			ret = resizeStr2(ret, len, len + 1);
			ret[len] = '\0';
			return ret;
		}
		if (len == max) ret = resizeStr2(ret, len, max *= 2);
		ret[len++] = (char)c;
	}
}

int main() {

	int c, r;
	int selectC[3];
	int selectR[10];

	// Read the dataframe from input
	// First line: two numbers seperated by space; 
	//             first number is the number of rows (r) and 
	//             second number is the number of columns (c)

	cin >> r >> c;
	DataFrame* firstDF = new DataFrame(r, c);

	// Second line: strings seperated by a comma (c of them); representing column names
	// Third line: strings seperated by a comma (r of them); representing row names
	// Fourth line and more: c number of integers in each of the r rows (seperated by)
	//	a space between integers in the same row.

	delete[] readUntil('\n');
	char *s;
	int i;
	for (i = 0; i < c - 1; i++) {
		s = readUntil(',');
		firstDF->setColName(i, s);
		delete[] s;
	}
	//Final column name is treated different
	s = readUntil('\n');
	firstDF->setColName(i, s);
	delete[] s;
	for (i = 0; i < r - 1; i++) {
		s = readUntil(',');
		firstDF->setRowName(i, s);
		delete[] s;
	}
	//Final row name is treated different
	s = readUntil('\n');
	firstDF->setRowName(i, s);
	delete[] s;
	//Now read main table data
	for (i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> (*firstDF)[i][j];
		}
	}

	// using the display method, print (in the same format as the input):
	// - the column names of the dataframe
	// - the row names of the dataframe
	// - the contents of the table in dataframe

	firstDF->display();

	// Execute the following code

	// Read the column numbers that you want to extract
	for (int i = 0; i < 3; i++)
		cin >> selectC[i];

	DataFrame* tempColumns = (*firstDF).getColumns(selectC, 3);

	(*tempColumns).display();

	// Change the row names of select rows

	(*tempColumns).setRowName(2, "Jack");
	(*tempColumns).setRowName(3, "Peter");

	(*tempColumns).display();

	// Read the row numbers that you want to extract

	for (int i = 0; i < 10; i++)
		cin >> selectR[i];

	DataFrame* tempRows = (*firstDF).getRows(selectR, 10);

	(*tempRows).display();

	// Change the column names of selected columns

	(*tempRows).setColName(2, "Scores");
	(*tempRows).setColName(3, "Values");

	(*tempRows).display();

	// Extract the rows in SelectR and columns in SelectC

	DataFrame* tempColsRows = (*firstDF).getRowsCols(selectR, 10, selectC, 3);

	(*tempColsRows).display();

	delete tempRows;
	delete tempColumns;
	delete tempColsRows;

	// Sample Code for you and you must execute this

	DataFrame* myTable = new DataFrame(5, 5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			(*myTable)[i][j] = i * j;
		}
	}

	(*myTable).display();

	delete myTable;
}
