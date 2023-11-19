#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Global vectors to store the original and sorted lists
vector<int> vect_list;
vector <int> sorted_list;

// Function to perform sorting on a portion of the vector
void sorting_elements(int start,int end){
    for (int i = start ; i <= end-1; ++i ){
        int temp_min = vect_list[i];
        for (int j = i +1 ; j <= end;++j){
            if (temp_min > vect_list[j]){
                int temp = temp_min;
                temp_min = vect_list[j];
                vect_list[j]= temp;
            }
        }
        vect_list[i] = temp_min;
    }
}

// Function to merge two sorted portions of the vector
void merge_elements(int start1,int end1){
    int start2 = end1+1;
    int end2 = vect_list.size()-1;
    int i = start1; 
    int j = start2;

    // Merge the two sorted portions into a new sorted_list
    while(i <= end1 && j <=end2){
        if(vect_list[i] < vect_list[j]){
            sorted_list.push_back(vect_list[i]);
            ++i;
        }
        else{
            sorted_list.push_back(vect_list[j]);
            ++j;
        }
    }

    // Add any remaining elements from the first portion
    while (i <= end1){
        sorted_list.push_back(vect_list[i]);
        ++i;
    }
    
    // Add any remaining elements from the second portion
    while (j <= end2){
        sorted_list.push_back(vect_list[j]);
        ++j;
    }
    
}
// Function to print elements in the original vector
void print_elements(){
    for (int i = 0 ; i < vect_list.size(); ++i)
    cout<<vect_list[i]<<endl;
    }

int main(){
    int n ;
    cout<<"Enter the size"<<endl;
    cin >> n;
    int temp;

    // Input elements into the vector
    for (int i = 0 ; i < n ; ++i){
        cin>>temp;
        vect_list.push_back(temp);
    }

// Create two threads to sort two halves of the vector
thread t1(sorting_elements, 0, (n/2)-1);
thread t2(sorting_elements, n/2, n-1);

// Wait for both threads to finish
t1.join();
t2.join();

// Print the elements after sorting the halves
print_elements();

// Merge the sorted halves
merge_elements(0,(n/2)-1);

cout<<"After Merging :"<<endl;

// Print the elements after merging
for (int i = 0 ; i < sorted_list.size(); ++i){
    cout<<sorted_list[i]<<endl;
    }

return 0;
}