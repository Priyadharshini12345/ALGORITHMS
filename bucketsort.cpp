#include<iostream>
#include<vector>
#include<algorithm>
void display(float* array,int n){
	int i;
	for(i=0;i<n;i++)
	std::cout<<array[i]<<std::endl;
}
void bucketsort(float* arr,int n){
	std::vector<float>bucket[n];
	int i;
		for(i=0;i<n;i++)
	bucket[int(n*arr[i])].push_back(arr[i]);
	for(i=0;i<n;i++)
	sort(bucket[i].begin(),bucket[i].end());
	int index=0;
	for(i=0;i<n;i++){
		while(!bucket[i].empty()){
			arr[index++]=*(bucket[i].begin());
			bucket[i].erase(bucket[i].begin());
					}
	}
	
}

int main(){
	int n,i;
	std::cout<<"Enter the number of elements"<<std::endl;
	std::cin>>n;
	float arr[n];
	std::cout<<"Enter the array elements"<<std::endl;
	for(i=0;i<n;i++)
	std::cin>>arr[i];
	std::cout<<"Before sorting:"<<std::endl;
	display(arr,n);
	bucketsort(arr,n);
	std::cout<<"After sorting"<<std::endl;
	display(arr,n);
}
