#ifndef _Logs_H_
#define _Logs_H_

#ifndef _LOGS_FILENAME_
#define _LOGS_FILENAME_ "Logs.txt"
#endif

#ifndef _LOGS_DIR_
#define _LOGS_DIR_ "./"
#endif




/*
|===============================================================

|creates log file in current directory named as Logs.txt     

|===============================================================

|this function Log works as a normal printf
|ex.    Log("inside function foo, got parameter a: %d", a);

|===============================================================
*/
void Log(char* format, ...);



#endif