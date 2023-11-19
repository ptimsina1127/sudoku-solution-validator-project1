#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> vect_list;
vector <int> sorted_list;

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

void merge_elements(int start1,int end1){
    int start2 = end1+1;
    int end2 = vect_list.size()-1;
    int i = start1; 
    int j = start2;
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

    while (i <= end1){
        sorted_list.push_back(vect_list[i]);
        ++i;
    }
    
    while (j <= end2){
        sorted_list.push_back(vect_list[j]);
        ++j;
    }
    
}

void print_elements(){
    for (int i = 0 ; i < vect_list.size(); ++i)
    cout<<vect_list[i]<<endl;
    }
int main(){
    int n ;
    cout<<"Enter the size"<<endl;
    cin >> n;
    int temp;
    for (int i = 0 ; i < n ; ++i){
        cin>>temp;
        vect_list.push_back(temp);
    }


thread t1(sorting_elements, 0, (n/2)-1);
thread t2(sorting_elements, n/2, n-1);
t1.join();
t2.join();
print_elements();
merge_elements(0,(n/2)-1);

cout<<"After Merging :"<<endl;

for (int i = 0 ; i < sorted_list.size(); ++i){
    cout<<sorted_list[i]<<endl;
    }

return 0;
}


        