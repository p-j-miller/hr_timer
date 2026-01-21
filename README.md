# hr_timer
high resolution timer for Windows and Linux, with us resolution.

It Provides the following functions:
~~~
  void init_HR_Timer( void) ; // initialise the high resolution timer
  double read_HR_Timer( void) ;  // read the timer , returns the time (secs) between last reset and now to ~ uS resolution
  uint64_t read_HR_Timer_ms( void) ; // read the timer, result in ms as an integer
  uint64_t read_HR_Timer_us( void) ; // read the timer, result in us as an integer, overflows in ~ 584 thousand years
  int64_t diff_time(uint64_t a, uint64_t b); // returns a-b valid if a, b within 2^63 of each other
											 // note returns an int64_t as time_us may be unsigned and the result has to be signed
~~~
# Installation
It is recommended that these files are installed in a directory called hr_timer

A test program is provided called test.c

To compile under Windows using winlibs gcc 15.2.0 (the changes for Linux should be obvious):
~~~
  C:\winlibs\winlibs-x86_64-posix-seh-gcc-15.2.0-mingw-w64ucrt-13.0.0-r2\mingw64\bin\gcc -Wall -m64 -fexcess-precision=standard -Ofast  -std=gnu99 -I. test.c hr_timer.c -static -o test.exe
~~~
Expected output is shown below (actual timings will vary on each run, but should always be close to 2 seconds) :
~~~
Slept for 2 secs.
 read_HR_Timer()    gave duration as 2.009981 secs
 read_HR_Timer_ms() gave duration as 2009 ms
 read_HR_Timer_us() gave duration as 2009981 us
~~~
It has been tested using:

* Winlibs gcc 15.2.0 for W64 and W32 under UCRT and MSVCRT under Windows 11
* Gcc 13.3.0 under Ubuntu (Linux) 24.04 LTS via wsl2
* Embarcadero C++ Builder 12.1 Community edition Version 29.0.52631.8427

  
