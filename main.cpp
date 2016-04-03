#include "FlightInfo.h"
#include "macros.h"
#include "Search.h"
#include <cstring>

map<string,Flight> flights;
map<string, Flight>::iterator i;
extern Flight f;
Route *r = new Route;
Route *t;
Route to_insert;
Date d;

Date operator *(Date d,int i)
{
    Date date;
    date.day = i;
    return date;
}

Date operator /(Date d,int i)
{
    if (d.month==0)
    {
        d.month = i;
    }
    else
        d.year = i;
    return d;
}

Info operator ,(const char *city, Date date)
{
    Info i(city,date);
    return i;
}

Info operator ,(Info i,Time time)
{
    i.time = time;
    return i;
}

Flight make_new_flight(string id)
{
    Flight temp(id);
    return temp;
}

Route make_new_route()
{
    Route temp;
    return temp;
}

Time parse_time(string time)
{
    Time t;
    char *tm =(char*) time.data();
    t.hour = atoi(tm);
    char *tm2 = strchr(tm+1,':');
    t.min = atoi(tm2);
    return t;
}

void insert(Flight f)
{
    flights.insert(pair<string,Flight>(f.id,f));
}

int fromto(string from,string to,Flight &fl)
{
    FromTo temp(from,to);
    return !temp.evaluate(fl);
}

int atdate(const char *d,Flight &fl)
{
    AtDate temp(d);
    return !temp.evaluate(fl);
}

int budget(float b,Flight &fl)
{
    Budget temp(b);
    return !temp.evaluate(fl);
}

int direct(Flight &fl)
{
    Direct temp;
    return !temp.evaluate(fl);
}

int indirect(int min,Flight &fl)
{
    Indirect temp(min);
    return !temp.evaluate(fl);
}

int duration(float dur,int type,Flight &fl)
{
    Duration temp(dur,type);
    return !temp.evaluate(fl);
}

void check(int x,Flight &fl)
{
    if (x==0)
    {
        cout <<endl<< "Found flight that meets criteria:" << endl;
        cout << "Flight id: "<< fl.id<<endl;
        cout << "Price "<<fl.price<<endl;
        cout << "Routes:" << endl;
        
        vector<Route>::iterator it;
        for ( it=fl.path.begin() ; it < fl.path.end(); it++ )
        {
            cout <<"From "<< it->info.city << " At "<< it->info.date.day <<"/" << it->info.date.month<<
                   "/" << it->info.date.year <<","<<it->info.time.hour<<":";
            if (it->info.time.min <10) cout<<"0"<<it->info.time.min;
            else cout<<it->info.time.min;
              
            cout <<" To "<< it->to.city << " At "<< it->to.date.day <<"/" << it->to.date.month<<
                   "/" << it->to.date.year <<","<<it->to.time.hour<<":";
            if (it->to.time.min <10) cout<<"0"<<it->to.time.min;
            else cout<<it->to.time.min;
            cout <<endl;
        }
    }
}

int main(int argc, char** argv) 
{   
    NEW_FLIGHT(oa1523):
    ROUTE
        FROM["ATH",DATE 1/11/2012,TIME(15:00)]->
        TO["FRA",DATE 2/11/2012,TIME(15:32)]   
    ROUTE
        FROM["FRA",DATE 2/11/2012,TIME(15:00)]->
        TO["SCH",DATE 2/11/2012,TIME(15:32)]
    PRICE 250 EUROS;
    
            
    NEW_FLIGHT(test):
    ROUTE
        FROM["MAD",DATE 1/11/2012,TIME(06:00)]->
        TO["NY",DATE 1/11/2012,TIME(11:00)]
    PRICE 300 EUROS;

    SEARCH AT(1/11/2012) DURATION(4,HOURS)  DIRECT END;
}

