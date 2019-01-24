#pragma once

using namespace std;

extern int strlen2(const char* str);

extern char* strdup2(const char* str);

//Note: Assumes new len is big enough to hold old contents!
extern char* resizeStr2(char *old, int oLen, int len);
