/* 
 * File:   macros.h
 * Author: Sun
 *
 * Created on February 6, 2012, 9:27 PM
 */

#ifndef MACROS_H
#define	MACROS_H

#include "FlightInfo.h"


#define NEW_FLIGHT(flight_id) f=make_new_flight(#flight_id); flight_id
#define ROUTE ;*r=make_new_route();
#define FROM  (*r)
#define TO to;(*r)
#define PRICE ; f.price = 
#define EUROS ; insert(f); 

#define TIME(time) parse_time(#time)
#define DATE d*

#define SEARCH for(i=flights.begin();i!=flights.end();i++) { int x=0; x=0
#define END ; check(x,i->second); x=0;}

#define FLIGHT(city1, city2) +fromto(#city1,#city2,i->second)
#define AT(date) +atdate(#date,i->second)
#define BUDGET(amount,euro) +budget(amount,i->second)
#define DIRECT +direct(i->second)
#define INDIRECT(min_stops) +indirect(min_stops,i->second)
#define DURATION(dur,type) +duration(dur,type,i->second)

#define MINS 0
#define HOURS 1

#endif	/* MACROS_H */

