#include <iostream>
#include "DataFrame.h"
#include "string.h"

using namespace std;

DataFrame::DataFrame() :DataFrame(4, 4) {}

DataFrame::DataFrame(int rows, int cols) {
	noRows = rows;
	noCols = cols;
	table = new int*[rows];
	rowNames = new char*[rows]; // Will be initialized to NULL
	colNames = new char*[cols];
	for (int i = 0; i < rows; i++) {
		table[i] = new int[cols];
		rowNames[i] = NULL;
		for (int j = 0; j < cols; j++) table[i][j] = 0;
	}
	for (int i = 0; i < cols; i++) colNames[i] = NULL;
}

void DataFrame::display() {
	for (int i = 0; i < noCols; i++) {
		if (i) cout << ",";
		if (colNames[i]) cout << colNames[i];
	}
	cout << endl;
	for (int i = 0; i < noRows; i++) {
		if (i) cout << ",";
		if (rowNames[i]) cout << rowNames[i];
	}
	cout << endl;
	for (int i = 0; i < noRows; i++) {
		for (int j = 0; j < noCols; j++) {
			if (j) cout << " ";
			cout << table[i][j];
		}
		cout << endl;
	}
}

void DataFrame::setRowName(int row, const char* name) {
	delete[] rowNames[row];
	rowNames[row] = strdup2(name);
}

void DataFrame::setColName(int col, const char* name) {
	delete[] colNames[col];
	colNames[col] = strdup2(name);
}

int* DataFrame::operator[] (int i) {
	return table[i];
}

char** DataFrame::getRowNames() { return rowNames; }
char** DataFrame::getColNames() { return colNames; }

int DataFrame::getNumberRows() { return noRows; }
int DataFrame::getNumberCols() { return noCols; }

DataFrame* DataFrame::getColumns(int* columns, int cLen) {
	DataFrame* ret = new DataFrame(noRows, cLen);
	for (int i = 0; i < noRows; i++) {
		ret->setRowName(i, rowNames[i]);
		for (int j = 0; j < cLen; j++) {
			(*ret)[i][j] = table[i][columns[j]];
		}
	}
	for (int i = 0; i < cLen; i++) ret->setColName(i, colNames[columns[i]]);
	return ret;
}

DataFrame* DataFrame::getRows(int *rows, int rLen) {
	DataFrame* ret = new DataFrame(rLen, noCols);
	for (int i = 0; i < rLen; i++) {
		int i2 = rows[i];
		ret->setRowName(i, rowNames[i2]);
		for (int j = 0; j < noCols; j++) {
			(*ret)[i][j] = table[i2][j];
		}
	}
	for (int i = 0; i < noCols; i++) ret->setColName(i, colNames[i]);
	return ret;
}

DataFrame* DataFrame::getRowsCols(int* rows, int rLen, int* cols, int cLen) {
	//Could me more efficient, but this is easier to read!
	DataFrame* tmp = getRows(rows, rLen);
	DataFrame* ret = tmp->getColumns(cols, cLen);
	delete tmp;
	return ret;
}

DataFrame::~DataFrame() {
	for (int i = 0; i < noRows; i++) {
		delete[] rowNames[i];
		delete[] table[i];
	}
	for (int i = 0; i < noCols; i++) {
		delete[] colNames[i];
	}
	delete[] rowNames;
	delete[] colNames;
	delete[] table;
}
