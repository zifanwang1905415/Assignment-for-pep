#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include <cmath>

using std::ostream;
using namespace std;

// TODO: your code goes here

class TimeAndCaseData{

    private:
    int time;
    int cases; 

    public:

    TimeAndCaseData(int timee, int casess):
    time(timee), cases(casess)
    {}

    int getTime()
    {
        return time;
    }

    int getNumberOfCases()
    {
        return cases;
    }



};

class CovidCaseMap{
    private:
    vector <CovidCase> covidlist;
    vector <TimeAndCaseData> map1;

    public:
    
    void addCase(CovidCase Co)
    {
        covidlist.push_back(Co);
    }

    double rad(double d)
    {
        return d * M_PI /180.0;
    }

    double getRoute(double temlat, double temlong, double temlat2, double temlong2)
{
    double dlon = 0;
    double lon1 = temlong;
    double lon2 = temlong2;
    double dlat = 0;
    double lat1 = temlat;
    double lat2 = temlat2;
    double result = 0;
    double finall = 0;
    double distance = 0; 

    lon1 = lon1 * M_PI / 180;
    lon2 = lon2 * M_PI / 180;
    lat1 = lat1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;


    dlon = lon2 - lon1;
    dlat = lat2 - lat1;
    result = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2);
    finall = 2 * atan2(sqrt(result), sqrt(1-result));
    distance = 3960 * finall;

    return distance;
}


    bool isExist(vector<double> tem, double temdouble)
    {
        for(int a = 0; a < tem.size(); a++)
        {
            if(tem[a] == temdouble)
            {
                return false;
                break;
            }

            else
            {
                continue;
            }
        }
        return true;
    }

    double supportVisitGreedyTSP(double temlatitude, double temlongitude, int temtime, int temperiod)
    {
        vector<double> temcovidlist;
        temcovidlist.push_back(100000);

        double startlat = temlatitude;
        double startlong = temlongitude;
        double endlat = 0;
        double endlong = 0;
        double totalroute = 0;
        double temroute = 0;
        double minroute;
        bool ex = true;
        double endlatt;
        double endlongg;

        while(temcovidlist.size() <= covidlist.size() )
        {
            minroute = 100000;
            for(int i = 0; i < covidlist.size(); i++)
            {
                ex = isExist(temcovidlist, covidlist[i].getLatitude());


                if(ex == true)
                {

                    if(covidlist[i].getTime() > temtime || covidlist[i].getTime() + temperiod < temtime)
                    {
                        temcovidlist.push_back(covidlist[i].getLatitude());
                    }

                    else{
                        endlat = covidlist[i].getLatitude();
                        endlong = covidlist[i].getLongitude();
                        temroute = getRoute(startlat, startlong, endlat, endlong);

                        if(temroute < minroute)
                        {
                            minroute = temroute;
                            endlatt = endlat;
                            endlongg = endlong;
                            
                        }

                        else
                        {
                            continue;
                        }

                    }

                }

                else
                {
                    continue;
                }
            }

            startlat = endlatt;
            startlong = endlongg;
        
            totalroute = totalroute + minroute;
            temcovidlist.push_back(startlat);
        }

        totalroute = totalroute + getRoute(startlat, startlong, temlatitude, temlongitude);
        return totalroute;
    }

    vector <TimeAndCaseData>  getCasesOverTime(int numm)
    {
        int totalcase = 0;
        queue <int> activetime;
        map1.push_back(TimeAndCaseData(0,0));

        for(int i = 0; i < covidlist.size(); i++)
        {   
            activetime.push(covidlist[i].getTime()+numm);
            for(int j = 0; j<i; j++)
            {
                if(covidlist[i].getTime() >= activetime.front())
                {
                    totalcase = totalcase - 1;
                    map1.push_back(TimeAndCaseData(activetime.front(), totalcase));
                    activetime.pop();
                }
            }

            totalcase = totalcase + 1;
            map1.push_back(TimeAndCaseData(covidlist[i].getTime(), totalcase));

            if(i == covidlist.size()-1 && !activetime.empty())
            {
                activetime.push(covidlist[i].getTime()+numm);

                for(int k = 0; k < activetime.size()+1; k++)
                {
                    totalcase = totalcase - 1;
                    map1.push_back(TimeAndCaseData(activetime.front(), totalcase));
                    activetime.pop();
                }

            }

        }

        return map1;
    }

};



// don't write any code below this line

#endif

