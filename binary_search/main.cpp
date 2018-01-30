#include <iostream>

//Abdullah Shahriar
//January 31,2018

using namespace std;

int comparison=0;

int Binary_Search_Recursion(int x,int arr[],int n,int low,int high)
{

    int mid;
    mid=low+(high-low)/2;

    while(low<=high)
    {

        if(arr[mid]==x)
        {
            comparison++;
            return mid;
            break;
        }
        else
        {

            if(arr[mid]>x)
            {
                comparison++;
                return Binary_Search_Recursion(x,arr,n/2,low,mid-1);
            }
            else if(arr[mid]<x)
            {
                comparison++;
                return Binary_Search_Recursion(x,arr,n/2,mid+1,high);
            }
        }

        return -1;
    }


}

int Binary_Search_Loop(int x,int arr[],int n)
{
    int low,mid,high;

    low=0;
    high=n-1;
    mid=low+(high-low)/2;

    while(low<=high)
    {
        mid=low+(high-low)/2;

        if(arr[mid]==x)
        {
            comparison++;
            return mid;
            break;
        }
        else
        {
            if(arr[mid]>x)
            {
                comparison++;
                high=mid-1;
            }
            else
            {
                comparison++;
                low=mid+1;
            }
        }
    }
    return -1;
}


int main()
{


    int data[]= {1,2,3,4,5,6,7};
    int query,index_r,index_l;

    //sort data[] before binary search

    cout<< "Enter a number to search: ";
    cin>>query;

    //bin_search_recursion(what_to_search,where_to_search,size_of_array,lower_bound,upper_bound);
    index_r=Binary_Search_Recursion(query,data,7,0,6);
    index_l=Binary_Search_Loop(query,data,7);

    if(index_r!=-1 && index_l!=-1)
    {
        cout << "Recursion-"<<endl<< query << " found at index " << index_r << endl << endl;
        cout <<"Loop-" << endl << query << " found at index " << index_l << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    cout << endl << "Comparisons: " << comparison/2 << endl << endl;


    return 0;
}
