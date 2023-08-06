/* 
* This class is based on code by Owen Soft, found at:
* https://owensoft.net/project/code/
*/
#ifndef timer_h
#define timer_h

// Needed for gettime and ticks_to_millisecs
#include <ogc/lwp_watchdog.h>

/**
 * @brief Test if the wait_time has passed.
 * Determine if a certain amount of time has passed in relation to current_time.
 * updates current time. Return true if currtime < (ct + wt) has elapsed
 * 
 * @param wait_time 
 * @param current_time 
 * @return true 
 * @return false 
 */
bool timer(u64 wait_time, u64 *current_time);  //test if the wait_time has passed. 1000=1sec

/**
 * @brief Reset timer
 * 
 * @param current_time 
 */
void timer_reset(u64 *current_time);

/**
 * @brief Get current time
 * 
 * @return u64 
 */
u64 timer_get_time();
#endif