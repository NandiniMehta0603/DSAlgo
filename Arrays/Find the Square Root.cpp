class Solution {
public:
    long long int binarySearch(int n)
    {
        int l=0;
        int h=n;
        long long int mid=l+(h-l)/2;
        int ans=0;
        while(l<=h)
        { long long int square=mid*mid;
          if(square>n)
          {
            h=mid-1;
          }
          else if(square<n)
          {
              ans=mid;
              l=mid+1;
          }
         else if(square==n)
            {
                return mid;
            }
         mid=l+(h-l)/2;
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};
