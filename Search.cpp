#include "Search.h"
#include <string>
#include <cstring>
#include <ctime>

Search::Search(void)
{
}


FromTo::FromTo(string from,string to)
{
    this->from=from;
    this->to=to;
}

bool FromTo::evaluate(const Flight &f)
{
    return !(this->from.compare(f.path.front().info.city) || this->to.compare(f.path.back().to.city));
}

AtDate::AtDate(const char* date)
{   
    this->d.day = atoi(date);
    char *tmp = strchr((char*)date, '/');
    this->d.month = atoi(tmp+1);
    tmp = strchr(tmp+1,'/');
    this->d.year = atoi(tmp+1);
}
bool AtDate::evaluate(const Flight& flight)
{
    if (flight.path.front().info.date.day == this->d.day)
    {
        if (flight.path.front().info.date.month == this->d.month)
        {
            if (flight.path.front().info.date.year == this->d.year)
            {
                return true;
            }
        }
    }
    return false;
}

Budget::Budget(float i)
{
    this->price =i;
}

bool Budget::evaluate(const Flight& flight)
{
    return this->price >= flight.price;
}

Direct::Direct()
{
    ;
}

bool Direct::evaluate(const Flight& flight)
{
    return flight.path.size()==1;
}

Indirect::Indirect(int min)
{
    this->min_stops=min;
}

bool Indirect::evaluate(const Flight& flight)
{
    return flight.path.size() >= min_stops;
}

Duration::Duration(float duration, int type)
{
    this->duration=duration;
    this->type=type;
}

bool Duration::evaluate(const Flight& flight)
{
    struct std::tm a = {0, 
                        flight.path.back().to.time.min,
                        flight.path.back().to.time.hour,
                        flight.path.back().to.date.day,
                        flight.path.back().to.date.month-1,
                        flight.path.back().to.date.year-1900
                       };
   struct std::tm b = { 0, 
                        flight.path.front().info.time.min,
                        flight.path.front().info.time.hour,
                        flight.path.front().info.date.day,
                        flight.path.front().info.date.month-1,
                        flight.path.front().info.date.year-1900
                       }; 
   
   std::time_t x = std::mktime(&a);
   std::time_t y = std::mktime(&b);
   if (this->type==0)
   {
       if (std::difftime(x,y)/60 >= this->duration) return true;
       else return false;
   }
   else
   {
       if (std::difftime(x,y)/(60*60) >= this->duration) return true;
       else return false;
   }
    
}
