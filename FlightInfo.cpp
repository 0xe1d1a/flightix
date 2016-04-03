/* 
 * File:   FlightInfo.cpp
 * Author: Sun
 * 
 * Created on February 6, 2012, 1:27 PM
 */
#include "FlightInfo.h"
/**
 * @class Date
 * 
 */
Date::Date()
{
    day=0;
    month=0;
    year=0;
}
/**
 * @class Time
 * 
 */
Time::Time()
{
    ;
}
/**
 * @class Info
 * 
 */

Flight f;
bool from = true;

Info::Info()
{
    ;
}


Info::Info(const char *city,Date date)
{
    this->city = city;
    this->date = date;
}

/**
 * @class Flight
 * 
 */
Flight::Flight() 
{
    ;
}

Flight::Flight(string id)
{
    this->id = id;
}


/**
 * @class Route
 * 
 */
Route::Route()
{
    ;
}

Route::Route(Info i)
{
    this->info = i;
}



Route *Route::operator [](Info i)
{
    if (from)
    {
        from = false;
        this->info = i;
        return this;
    }
    else
    {
        from = true;
        this->to = i;
        f.path.push_back(*this);
        return NULL;
    }
}
