#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

int medianofthree(vector<int>&data,int left,int right){
    int mid,tmp;
    mid = (left + right)/2;
    if (data[right] < data[left]){
        tmp=data[right];
        data[right]=data[left];
        data[left]=tmp;
    }       
    if (data[mid] < data[left]){
        tmp=data[mid];
        data[mid]=data[left];
        data[left]=tmp;
    }
    if (data[right] < data[mid]){
        tmp=data[right];
        data[right]=data[mid];
        data[mid]=tmp;
    }
    return mid;
}

//leftmost-longer first
void quicksort(vector<int> &data,int left,int right){
    int pivot,l,r;
    if(left<right){
        l=left;
        r=right+1;
        pivot=data[left];
        do{
            do l++;while(data[l]<pivot);
            do r--;while(data[r]>pivot);
            if(l<r){
                int temp=data[l];
                data[l]=data[r];
                data[r]=temp;
            }
        }while(l<r);
        int temp=data[left];
        data[left]=data[r];
        data[r]=temp;
        if(r-left>right-r){
            quicksort(data,left,r-1);
            quicksort(data,r+1,right);
        }else{ 
            quicksort(data,r+1,right);
            quicksort(data,left,r-1);
        }
    }
}

//leftmost-shorter first
void quicksort2(vector<int> &data,int left,int right){
    int pivot,l,r;
    if(left<right){
        l=left;
        r=right+1;
        pivot=data[left];
        do{
            do l++;while(data[l]<pivot);
            do r--;while(data[r]>pivot);
            if(l<r){
                int temp=data[l];
                data[l]=data[r];
                data[r]=temp;
            }
        }while(l<r);
        int temp=data[left];
        data[left]=data[r];
        data[r]=temp;
        if(r-left<right-r){
            quicksort2(data,left,r-1);
            quicksort2(data,r+1,right);
        }else{ 
            quicksort2(data,r+1,right);
            quicksort2(data,left,r-1);
        }
    }
}

//leftmost-original
void quicksort3(vector<int> &data,int left,int right){
    int pivot,l,r;
    if(left<right){
        l=left;
        r=right+1;
        pivot=data[left];
        do{
            do l++;while(data[l]<pivot);
            do r--;while(data[r]>pivot);
            if(l<r){
                int temp=data[l];
                data[l]=data[r];
                data[r]=temp;
            }
        }while(l<r);
        int temp=data[left];
        data[left]=data[r];
        data[r]=temp;
        quicksort3(data,left,r-1);
        quicksort3(data,r+1,right);
    }
}

//median of theree-longer first
void quicksort4(vector<int> &data,int left,int right){
    int pivot,l,r;
    if(left<right){
        l=left;
        r=right+1;
        pivot=data[medianofthree(data,left,right)];
        do{
            do l++;while(data[l]<pivot);
            do r--;while(data[r]>pivot);
            if(l<r){
                int temp=data[l];
                data[l]=data[r];
                data[r]=temp;
            }
        }while(l<r);
        int temp=pivot;
        pivot=data[r];
        data[r]=temp;        
        if(r-left>right-r){
            quicksort4(data,left,r-1);
            quicksort4(data,r+1,right);
        }else{ 
            quicksort4(data,r+1,right);
            quicksort4(data,left,r-1);
        }
    }
}

//median of theree-shorter first
void quicksort5(vector<int> &data,int left,int right){
    int pivot,l,r;
    if(left<right){
        l=left;
        r=right+1;
        pivot=data[medianofthree(data,left,right)];
        do{
            do l++;while(data[l]<pivot);
            do r--;while(data[r]>pivot);
            if(l<r){
                int temp=data[l];
                data[l]=data[r];
                data[r]=temp;
            }
        }while(l<r);
        int temp=pivot;
        pivot=data[r];
        data[r]=temp;        
        if(r-left<right-r){
            quicksort5(data,left,r-1);
            quicksort5(data,r+1,right);
        }else{ 
            quicksort5(data,r+1,right);
            quicksort5(data,left,r-1);
        }
    }
}

//median of theree-original
void quicksort6(vector<int> &data,int left,int right){
    int pivot,l,r;
    if(left<right){
        l=left;
        r=right+1;
        pivot=data[medianofthree(data,left,right)];
        do{
            do l++;while(data[l]<pivot);
            do r--;while(data[r]>pivot);
            if(l<r){
                int temp=data[l];
                data[l]=data[r];
                data[r]=temp;
            }
        }while(l<r);
        int temp=pivot;
        pivot=data[r];
        data[r]=temp;        
        quicksort6(data,left,r-1);
        quicksort6(data,r+1,right);
    }
}


int main(){
    //read file
    ifstream fin;
    fin.open("hw10.txt");
    int num;
    vector<int>data;
    while(fin>>num){
        data.push_back(num);
    }
    fin.close();

    //time
    clock_t start,start2,start3,start4,start5,start6,
            end,end2,end3,end4,end5,end6;
    double time_used1,time_used2,time_used3,time_used4,time_used5,time_used6;
    int length=data.size();

    data.push_back(99999);
    
    vector<int>cdata=data;
    vector<int>ddata=data;
    vector<int>edata=data;
    vector<int>fdata=data;
    vector<int>gdata=data;
    //
    start=clock();
    quicksort(data,0,length-1);
    end=clock();
    //
    start2=clock();
    quicksort2(cdata,0,length-1);
    end2=clock();
    //
    start3=clock();
    quicksort3(ddata,0,length-1);
    end3=clock();
    //
    start4=clock();
    quicksort4(edata,0,length-1);
    end4=clock();
    //
    start5=clock();
    quicksort5(fdata,0,length-1);
    end5=clock();
    //
    start6=clock();
    quicksort6(gdata,0,length-1);
    end6=clock();

    time_used1 = ((double) (end-start)) / CLOCKS_PER_SEC;
    time_used2 = ((double) (end2-start2)) / CLOCKS_PER_SEC;
    time_used3 = ((double) (end3-start3)) / CLOCKS_PER_SEC;
    time_used4 = ((double) (end4-start4)) / CLOCKS_PER_SEC;
    time_used5 = ((double) (end5-start5)) / CLOCKS_PER_SEC;
    time_used6 = ((double) (end6-start6)) / CLOCKS_PER_SEC;

    cout<<"use leftmost and longer first execution time: "<<time_used1<<endl<<endl;
    cout<<"use leftmost and shorter first execution time: "<<time_used2<<endl<<endl;
    cout<<"use leftmost and original execution time: "<<time_used3<<endl<<endl;
    cout<<"use median of three and longer first execution time: "<<time_used4<<endl<<endl;
    cout<<"use median of three and shorter first execution time: "<<time_used5<<endl<<endl;
    cout<<"use median of three and original execution time: "<<time_used6<<endl<<endl;
}
