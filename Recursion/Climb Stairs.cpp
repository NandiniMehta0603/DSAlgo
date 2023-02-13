//ALERT: this gives TLE as this is the recursive solution. We can remove TLE using dp

//steps: travel backward
//you can either go downward 1 step
//or you can go downward 2 steps
#include <bits/stdc++.h> 
#define mod 1000000007
int countDistinctWays(int nStairs) {
    //base case 1
    if(nStairs==0){
        return 1;
    }
    if(nStairs<0){
        return 0;
    }

    int count=countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
    return count;
}
