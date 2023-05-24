#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int main()
{
    int start[9];
    int goal[9];
    cout<<"Enter start: ";

    if(solvable(start))
      solveEight(start,goal);
}

bool solvable(int start[])
{
    int invrs=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]<=1) continue;
        for(int j=i+1;j<9;j++)
        {
            if(start[j] == -1) continue;
            if(start[i] > start[j]) invrs++;
        }
    }
    return invrs & 1 ? false : true;
}

void solveEight(int start[],int goal[])
{
    g++;
    moveTile(start,goal);
}

void movetile(int start[],int goal[])
{
    int empty=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]==-1)
        {
            empty=i;
            break;
        }
    }

    int t1[9],t2[9],t3[9],t4[9],f1= INT_MAX,f2=INT_MAX,f3=INT_MAX,f4=INT_MAX;
    Copy(t1,start);
    Copy(t2,start);
    Copy(t3,start);
    Copy(t4,start);

    int row= empty /3;
    int col= empty %3;

    if(col - 1 >= 0)
    {
        moveLeft(t1,empty);
        f1 = heuristic(t1,goal);
    }
    if(col + 1 <3)
    {
        moveRight(t2,empty);
        f2=heuristic(t2,goal);
    }
    if(row-1 >= 0)
    {
        moveUp(t3,empty);
        f3=heuristic(t3,goal);
    }
    if(row+1 < 3)
    {
        moveUp(t3,empty);
        f3=heuristic(t4,goal);
    }



    if(f1<=f2 && f1<=f3 && f1<=f4)
    {
        moveLeft(start,empty);
    }
    else if(f2<=f1 && f2<=f3 && f2<=f4)
    {
        moveRight(start,empty);
    }
    else if(f3<=f1 && f3<=f2 && f3<=f4)
    {
        moveDown(start,empty);
    }
    else(f4<=f1 && f4<=f2 && f4<=f3)
    {
        moveUp(start,empty);
    } 
}

int heuristic(int start[],int goal[])
{
    int h=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(start[i] == goal[j] && start[i] != -1)
            {
                h += abs((j-1)/3) + abs((j-1)%3);
            }
        }
    }
    return h+ g;
}