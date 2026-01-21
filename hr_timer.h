/* hr_timer.h

  header file for Windows high resolution timer functions
  
  Peter Miller 10/7/2016
  See hr_timer.c for details.
  
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
 
#ifndef _hr_timer_h
#define _hr_timer_h
#ifdef _WIN32
 #include <windows.h>
#endif
#include <stdint.h>
 #ifdef __cplusplus
 extern "C" {
#endif
 
#define ms *1000  /* scaling factors for times to us */
#define us *1
#define sec *1000000

void init_HR_Timer( void) ; // initialise the high resolution timer
double read_HR_Timer( void) ;  // read the timer , returns the time (secs) between last reset and now to ~ uS resolution
uint64_t read_HR_Timer_ms( void) ; // read the timer, result in ms as an integer
uint64_t read_HR_Timer_us( void) ; // read the timer, result in us as an integer, overflows in ~ 584 thousand years
int64_t diff_time(uint64_t a, uint64_t b); // returns a-b valid if a, b within 2^63 of each other
										 // note returns an int64_t as time_us may be unsigned and the result has to be signed
 #ifdef __cplusplus
    }
 #endif										 
#endif /* _hr_timer_h */
