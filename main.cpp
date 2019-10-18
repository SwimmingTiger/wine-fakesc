#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// log sc arguments, run sc.ori.exe and exit with code 0.
int main(int argc, const char * argv[])
{
	string cmd = "sc.ori.exe";
	for (int i = 1; i < argc; i++) {
		cmd += " \"";
		cmd += argv[i];
		cmd += "\"";
	}
	cmd += " >> C:\\Users\\Public\\sc.log 2>&1";
	string echo = "echo [exec] " + cmd;
	system(echo.c_str());
	system(cmd.c_str());
	return 0;
}

