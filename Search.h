#include "FlightInfo.h"

class Search
{
public:
	virtual bool evaluate(const Flight &flight)=0;
	Search(void);
};

class FromTo : Search
{
public:
	bool evaluate (const Flight &flight);
	FromTo(string from,string to);

	string from;
	string to;
};

class AtDate : Search
{
public:
    bool evaluate(const Flight &flight);
    AtDate(const char *date);
    Date d;
};

class Budget : Search
{
public:
    bool evaluate(const Flight &flight);
    Budget(float price);
    
    float price;
};

class Direct : Search
{
public:
    bool evaluate(const Flight &flight);
    Direct();
};

class Indirect
{
public:
    Indirect(int min);
    bool evaluate(const Flight &flight);
    
    int min_stops;
};

class Duration
{
public:
    Duration(float duration, int type);
    bool evaluate(const Flight &flight);
    float duration;
    int type;
};
