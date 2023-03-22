#include <iostream>
#include <cmath>
#include <string>

std::string secondsToTime(int seconds)
{
    /* GETTING HOURS */
    double hrsMinsSecs = (float)seconds/3600;
    int hr = hrsMinsSecs;
    int whole_hr = hr;
    if(hr >= 24)
    {
        int mult = hr / 24;
        if(mult > 0)    
        {
            for(int i =0; i < mult; ++i) { hr = hr - 24; }
        }
    }

    std::string str_hr, str_mins, str_secs;
    if (hr < 10) { str_hr = "0" + std::to_string(hr); }
    else { str_hr = std::to_string(hr); }

    /* GETTING MINUTES */
    double minsSecs = (hrsMinsSecs - whole_hr) * 60;
    int mins = minsSecs;
    if (mins < 10) { str_mins = "0" + std::to_string(mins); }
    else { str_mins = std::to_string(mins); }

    /* GETTING SECONDS */
    int secs = round(((minsSecs - mins) * 60));
    if (secs < 10) { str_secs = "0" + std::to_string(secs); }
    else { str_secs = std::to_string(secs); }

    /* CREATE TIME STRING */
    std::string time = str_hr + ":" + str_mins + ":" + str_secs;

    /* RETURN */
    return time;
}

int main(int argc, char** argv)
{
    std::string time = secondsToTime(std::stoi(argv[1]));
    std::cout<< time;
}
