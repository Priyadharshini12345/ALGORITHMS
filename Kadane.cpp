int maxSubarraySum(int arr[], int n){
    
   int sum=0,ans=-999,i;
   for(i=0;i<n;i++){
       sum=sum+arr[i];
       if(sum>ans)
       ans=sum;
       if(sum<0)
       sum=0;
   }
   return ans;
    
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<maxSubarraySum(a,n)<<endl;
	}
	return 0;
}