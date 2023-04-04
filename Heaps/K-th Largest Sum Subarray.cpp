//in brute force approach--> we store all the addition answers
//with the help of priority queues, we will store only the "k" smallest addition answers
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	
	priority_queue<int,vector<int>, greater<int>> mini;
	for(int i=0;i<arr.size();i++){
		int sum=0;
		//initialise a sum=0 for each round;
		for(int j=i;j<arr.size();j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}
