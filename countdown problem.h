#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>


using namespace std;

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:

#include <vector>
#include <iostream> 
#include <string>
#include <stack> 
#include <algorithm>

using namespace std;

double evaluateCountdown(string rpn)
{
    string snum = ""; 
    double num = 0;
    double result = 0;
    double top = 0;
    double down = 0;
    string space = "";
    stack <double> nums;

    for(int i = 0; i < rpn.length()+1; i++)
    {
        snum = snum + rpn[i];

        if (rpn[i] == ' ')
        {
            if(snum[0] == ' ')
            {
                snum = "";
            }

            else
            {
                num = stod(snum);
                nums.push(num);
                snum = space;
            }

        }


        else if(rpn[i] == '+')
        {
            top = nums.top();
            nums.pop();
            down = nums.top();
            nums.pop();
            result = down + top;
            nums.push(result);
            snum = "";
        }

        else if(rpn[i] == '-')
        {
            top = nums.top();
            nums.pop();
            down = nums.top();
            nums.pop();
            result = down - top;
            nums.push(result);
            snum = "";
        }

        else if(rpn[i] == '/')
        {
            top = nums.top();
            nums.pop();
            down = nums.top();
            nums.pop();
            result = down / top;
            nums.push(result);
            snum = "";
        }

        else if(rpn[i] == '*')
        {
            top = nums.top();
            nums.pop();
            down = nums.top();
            nums.pop();
            result = down * top;
            nums.push(result);
            snum = "";
        }
    }
    num = 0;
    return result;
}

CountdownSolution solveCountdownProblem(vector<int> numbers, int targetnum)
{
    string tem;
    double result;
    string algo = "+-*/";
    sort(numbers.begin(), numbers.end());
    while(next_permutation(numbers.begin(),numbers.end())){
        for(int a = 0; a < 4; a++)
        {
            for(int b = 0; b < 4; b++)
            {
                for(int c = 0; c < 4; c++)
                {
                            tem = intToString(numbers[0])+ " " + intToString(numbers[1]) + " " + intToString(numbers[2]) + " " + intToString(numbers[3]) + " " + algo[a] + " " + algo[b] + " " + algo[c];
                            result = evaluateCountdown(tem);
                            if(result == targetnum)
                            {
                                cout<<tem<<endl;
                                return CountdownSolution(tem, result);
                            }
                }
            }
        }
    }

    while(next_permutation(numbers.begin(),numbers.end())){
        for(int a = 0; a < 4; a++)
        {
            for(int b = 0; b < 4; b++)
            {
                for(int c = 0; c < 4; c++)
                {
                    for(int d = 0; d < 4; d++)
                    {
                            tem = intToString(numbers[0])+ " " + intToString(numbers[1]) + " " + intToString(numbers[2]) + " " + intToString(numbers[3]) + " " + intToString(numbers[4]) + " " + algo[a] + " " + algo[b] + " " + algo[c] + " " + algo[d];
                            result = evaluateCountdown(tem);
                            if(result == targetnum)
                            {
                                cout<<tem<<endl;
                                return CountdownSolution(tem, result);
                            }
                    }
                }
            }
        }
    }

    while(next_permutation(numbers.begin(),numbers.end())){
        for(int a = 0; a < 4; a++)
        {
            for(int b = 0; b < 4; b++)
            {
                for(int c = 0; c < 4; c++)
                {
                    for(int d = 0; d < 4; d++)
                    {
                        for(int e = 0; e < 4; e++)
                        {
                            tem = intToString(numbers[0])+ " " + intToString(numbers[1]) + " " + intToString(numbers[2]) + " " + intToString(numbers[3]) + " " + intToString(numbers[4]) + " " + intToString(numbers[5]) + " " + algo[a] + " " + algo[b] + " " + algo[c] + " " + algo[d] + " " + algo[e];
                            result = evaluateCountdown(tem);
                            if(result == targetnum)
                            {
                                cout<<tem<<endl;
                                return CountdownSolution(tem, result);
                            }
                        }
                    }
                }
            }
        }
    }

    return CountdownSolution(tem, result);
}


// Do not edit below this line


#endif
