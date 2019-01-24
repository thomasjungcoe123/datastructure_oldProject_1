using namespace std;

class DataFrame {
protected:
	int**	table;
	int	noRows, noCols;
	char**	colNames;
	char**	rowNames;
public:
	//Constructors
	DataFrame();
	DataFrame(int rows, int cols);

	//Output Method
	void display();

	//Setters
	void setRowName(int row, const char* name);
	void setColName(int col, const char* name);
	int* operator[] (int i); //get row i;

							 //Getters
	char** getRowNames();
	char** getColNames();
	int getNumberRows();
	int getNumberCols();
	DataFrame* getColumns(int* columns, int cLen);
	DataFrame* getRows(int* rows, int rLen);
	DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen);

	//Destructor
	~DataFrame();
};
