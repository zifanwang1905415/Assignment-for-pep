#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
using std::string;


// TODO: your code goes here:
#include <iostream>
#include <vector>

using namespace std;

int stringConstruction(string target, int copycost, int appendcost)
{
    int result = 0;
    int firstsize;
    int secondsize;
    int size = target.length();
    string first = target.substr(0,size/2);
    string second = target.substr(size/2, size-size/2);

    while(first.length() > 1)
    {
        while(second.length() > 1)
        {
            if(first.find(second) != std::string::npos)
            {
                if(copycost < appendcost *second.length())
                {
                    result = result + copycost;
                    second = "";
                }

                else
                {
                    result = result + appendcost * second.length();
                    second = "";
                }
            }


            else
            {
                first = first + second[0];
                secondsize = second.length();
                second = second.substr(1,secondsize-1);

            }
        }

        if(second.length() == 1)
        {
            if(copycost<appendcost)
            {
                if(first.find(second) != std::string::npos)
                {
                    result = result + copycost;
                    firstsize = first.length();
                    first = first.substr(0, firstsize/2);
                    second = target.substr(firstsize/2, firstsize - firstsize/2);
                }
                
                else
                {
                    result = result + appendcost;
                    firstsize = first.length();
                    first = first.substr(0, firstsize/2);
                    second = target.substr(firstsize/2, firstsize - firstsize/2);
                }
            }

            else
            {
                result = result + appendcost;
                firstsize = first.length();
                first = first.substr(0, firstsize/2);
                second = target.substr(firstsize/2, firstsize - firstsize/2);
            }

        }

        else
        {
            firstsize = first.length();
            first = first.substr(0, firstsize/2);
            second = target.substr(firstsize/2, firstsize - firstsize/2);
        }

    }
    if(first.length() == 1 && second.length() == 1)
    {
        result = result + appendcost + appendcost;
    }

    if(first.length() == 1 && second.length() == 0)
    {
        result = result + appendcost;
    }
    if(first.length() == 1 && second.length() == 2)
    {
        result = result + appendcost*3;
    }

    return result;

}




// do not write or edit anything below this line

#endif
