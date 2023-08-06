/* 
* This class is based on code by Owen Soft, found at:
* https://owensoft.net/project/code/
*/
#include "utils/timer.h"

u64 timer_get_time(){	
    return (gettime() / TB_TIMER_CLOCK);
}

bool timer( u64 wait_time, u64 *current_time ) { 
    u64 timer_temp=timer_get_time(); 
    if( *current_time==0 ){ 
        *current_time=timer_temp;
        // Prevent line from below firing on first check
        return false;
    } 
    if( timer_temp > ( *current_time + wait_time ) ) {  
        *current_time=timer_temp;
        return true;
    }
    return false;
}

void timer_reset( u64 *current_time ){
    *current_time=0; 
}