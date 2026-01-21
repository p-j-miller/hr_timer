/* simple test program for hr_timer.c

 Written by Peter Miller, 1/2026
 
To compile under Windows using winlibs gcc 15.2.0 (the changes for Linux should be obvious):
  C:\winlibs\winlibs-x86_64-posix-seh-gcc-15.2.0-mingw-w64ucrt-13.0.0-r2\mingw64\bin\gcc -Wall -m64 -fexcess-precision=standard -Ofast  -std=gnu99 -I. test.c hr_timer.c -static -o test.exe
 
Expected output is shown below (actual timings will vary on each run, but should always be close to 2 seconds) :
Slept for 2 secs.
 read_HR_Timer()    gave duration as 2.009981 secs
 read_HR_Timer_ms() gave duration as 2009 ms
 read_HR_Timer_us() gave duration as 2009981 us

  
*/
/*----------------------------------------------------------------------------
 * MIT License:
 *
 * Copyright (c) 2016,2020,2026 Peter Miller
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHOR OR COPYRIGHT HOLDER BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "hr_timer.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
void Sleep(int sleep_ms) // Windows already has this function 
{ usleep(sleep_ms ms); // usleep argument in us 
}
#endif



int main(int argc, char *argv[]) {
double dstart_t,dend_t;
uint64_t istart_t_ms,iend_t_ms,istart_t_us,iend_t_us;
init_HR_Timer();
dstart_t=read_HR_Timer();
istart_t_ms=read_HR_Timer_ms();
istart_t_us=read_HR_Timer_us();

// now wait a while
Sleep(2000);// wait 2 secs
dend_t=read_HR_Timer();
iend_t_ms=read_HR_Timer_ms();
iend_t_us=read_HR_Timer_us();
printf("Slept for 2 secs.\n read_HR_Timer()    gave duration as %.6f secs\n read_HR_Timer_ms() gave duration as %zd ms\n read_HR_Timer_us() gave duration as %zd us\n",dend_t-dstart_t,
	diff_time(iend_t_ms,istart_t_ms), diff_time(iend_t_us,istart_t_us) );
	
return 0;
}