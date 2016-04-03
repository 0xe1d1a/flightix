/* 
 * File:   FlightInfo.h
 * Author: Sun
 *
 * Created on February 6, 2012, 1:27 PM
 */

#ifndef FLIGHTINFO_H
#define	FLIGHTINFO_H
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

class Date
{
public:
    Date();
    int day;
    int month;
    int year;
};

class Time
{
public:
    Time();
    int min;
    int hour;
};

class Info
{
public:
    Info();
    Info (const char *city,Date date);
    
    Date date;
    const char *city;
    Time time;
};

class Route
{ 
public:
    Route();
    Route(Info i);
    Route *operator[](Info i);
    Info to;
    Info info;
private:
};

class Flight 
{
public:
    Flight();
    Flight(string id);
    
    vector<Route> path;
    string id;
    double price;
};

#endif	/* FLIGHTINFO_H */

