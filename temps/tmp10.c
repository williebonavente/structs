#include <stdio.h>

typedef struct
{
    int hour, minute, second;
} my_time_t;


my_time_t new_time(my_time_t time_of_day, int elapsed_secs);

int main(void)
{
    my_time_t time_now = {21, 58, 32}; // initialize to midnight
    int secs = 97;

    time_now = new_time(time_now, secs);

    printf("Time after %d seconds: %02d:%02d:%02d\n", secs, time_now.hour, time_now.minute, time_now.second);

    return 0;
}


my_time_t new_time(my_time_t time_of_day, int elapsed_secs)
{
    int new_hr, new_min, new_sec;
    

    new_sec = time_of_day.second + elapsed_secs;
    time_of_day.second = new_sec % 60;
    new_min = time_of_day.minute + new_sec / 60;
    time_of_day.minute = new_min % 60;
    new_hr = time_of_day.hour + new_min / 60;
    time_of_day.hour = new_hr % 24;

    return time_of_day;
}
