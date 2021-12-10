// TODO: Replace this file with your CovidCase.h from Part1
// then extend as per the instructions in README.md

#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::ostream;
using namespace std;

// TODO: your code  goes here

class CovidCase{
    private:

    double latitude;
    double longitude;
    string name;
    int age;
    int time;

    public:

    CovidCase(double latitudedou, double longitudedou, string namest, int ageint, int timeint)
    :latitude(latitudedou), longitude(longitudedou), name(namest), age(ageint), time(timeint)
    {}

    CovidCase(string s)
    {
        string tem;
        int count = 0;

        for(int i = 0; i<s.length();i++)
        {

            

            if (s[i] == ',')
            {
                if(count == 0)
                {
                    latitude = stod(tem);
                    count = count + 1;
                    tem = "";
                }

                else if(count == 1)
                {
                    longitude = stod(tem);
                    count = count + 1;
                    tem = "";
                }

                else if(count == 2)
                {
                    tem = tem.substr(1);
                    name = tem;
                    count = count + 1;
                    tem = "";
                }

                else if(count == 3)
                {
                    age = stoi(tem);
                    count = count + 1;
                    tem = "";
                }

            }

            else if(i == s.length()-1)
                {
                    tem = tem + s[i];
                    time = stoi(tem);
                }

            

            else{
                if(s[i] == '"')
            {
                continue;
            }
                tem = tem + s[i];
            }

        }

    }

    bool operator==(CovidCase &c)
    {
        if(this->latitude == c.latitude && this->longitude == c.longitude && this->name == c.name && this->age == c.age && this->time == c.time)
        {
            return true;
        }
        return false;
    }

    double getLatitude() const 
    {
        return latitude;
    }

    double getLongitude() const 
    {
        return longitude;
    }

    string getName() const 
    {
        return name;
    }

    int getAge() const 
    {
        return age;
    } 

    int getTime() const 
    {
        return time;
    } 


    double distanceTo(CovidCase b)
{
    double dlon = 0;
    double lon1 = getLongitude();
    double lon2 = b.getLongitude();
    double dlat = 0;
    double lat1 = getLatitude();
    double lat2 = b.getLatitude();
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

};

ostream & operator<<(ostream & o, const CovidCase & s)
    {
        o<<"{"<<s.getLatitude()<<", "<<s.getLongitude()<<", \""<<s.getName()<<"\", "<<s.getAge()<<", "<<s.getTime()<<"}";
        return o;
    }




// don't write any code below this line

#endif