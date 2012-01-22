#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <iomanip>
using std::fixed;
using std::setprecision;

#include <cstdlib>
using std::system;

#include <ctime>
using std::clock;

#include <windows.h>
#include <GL/glut.h>
#include <CPU Clock.h>


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	int t;
	double time;
	int iterations = 250;

	//cin >> iterations;
	//if(argc == 2)
		cout << "success? " << (timeBeginPeriod(1)==TIMERR_NOERROR) << endl;

	LARGE_INTEGER clockFrequency;
	QueryPerformanceFrequency(&clockFrequency);
	cout << "f = " << clockFrequency.QuadPart << " Hz" << endl;
	cout << "T = " << 1000.0/clockFrequency.QuadPart << " ms" << endl;

	LARGE_INTEGER start,stop;
	QueryPerformanceCounter(&start);
	for(int c = 0 ; c < iterations ; c++)
		;
	QueryPerformanceCounter(&stop);
	cout << stop.QuadPart-start.QuadPart << endl;

	time = CPUclock::currentTime();
	for(int c = 0 ; c < iterations ; c++)
		;
	cout << CPUclock::currentTime()-time << endl;

	t = timeGetTime();
	for(int c = 0 ; c < iterations ; c++)
		cout << '.';
	cout << timeGetTime()-t << endl;

	t = clock();
	for(int c = 0 ; c < iterations ; c++)
		cout << '.';
	cout << clock()-t << endl;

	t = glutGet(GLUT_ELAPSED_TIME);
	for(int c = 0 ; c < iterations ; c++)
		cout << '.';
	cout << glutGet(GLUT_ELAPSED_TIME)-t << endl;

	//if(argc == 2)
		timeEndPeriod(1);
	system("PAUSE");
	return 0;
} // end function main
