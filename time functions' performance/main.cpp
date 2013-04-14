//	Copyright (C) 2010, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of time functions' performance.
 *
 *	time functions' performance is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	time functions' performance is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with time functions' performance.  If not, see <http://www.gnu.org/licenses/>.
 */

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
