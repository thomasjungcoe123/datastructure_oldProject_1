
using namespace std;

int strlen2(const char* str) 
{
	const char *x = str;
	while (*x) x++;
	return x - str;
}

char* strdup2(const char* str) 
{
	int len = strlen2(str) + 1;
	char *ret = new char[len];
	for (int i = 0; i < len; i++) ret[i] = str[i];
	return ret;
}

//Note: Assumes new len is big enough to hold old contents!
char* resizeStr2(char *old, int oLen, int len) 
{
	char *ret = new char[len];
	for (int i = 0; i < oLen; i++) ret[i] = old[i];
	delete[] old;
	return ret;
}
