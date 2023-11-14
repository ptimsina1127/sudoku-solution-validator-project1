#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
using namespace std::chrono;

bool col = true, row = true, subgrid = true; 

bool column_check(int array[][9]){
    cout<<"column check";
  for (int i = 0 ; i < 9 ; ++i){
    for(int j = 0 ; j < 9 ; ++j){
        for (int k = j+1 ; k < 9 ; ++k ){
            cout<<"1";
            if (array[j][i] == array[k][i]){
                col = false;
                return false;
            }
        }
    }
  }
  cout<<"finished1 ";
  return true;
}

bool row_check(int array[][9]){
    cout<<"row check";
  for (int i = 0 ; i < 9 ; ++i){
    for(int j = 0 ; j < 9 ; ++j){
        for (int k = j+1 ; k < 9 ; ++k ){
            cout<<"2";
            if (array[i][j] == array[i][k]){
                row = false;
                return false;
            }
        }
    }
  }
  cout<<"finished2 ";
  return true;
}

bool subgrid_check(int array[][9]){
    cout<<"subgrid check";
    for (int i = 0 ; i < 3 ; ++i){
        for (int j = 0 ; j < 3 ; ++j){
            int first_row = i*3;
            int first_column = j*3;
            int temp_arr[9] ;

            int index = 0;
            for(int x=0; x<3; x++)
            {
                for (int y= 0; y<3; y++)
                {
                    temp_arr[index] = array[x][y];
                    index++;
                }
            }

            for (int a = 0; a < 9; ++a ){
                for (int b = a+1 ; b<9; ++b){
                    cout<<"3";
                    if (temp_arr[a] == temp_arr[b]){
                        subgrid = false;
                        return false;
                    }
                }
            }
        }
    }
    cout<<"finished3 ";
    return true;
}

float measure_time(){
    

}


int main (){
    int sudoku[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

auto start = high_resolution_clock::now();

bool check =column_check(sudoku) && row_check(sudoku) && subgrid_check(sudoku);

auto end = high_resolution_clock::now();
auto dur = duration_cast<milliseconds>(end-start);

cout << check << endl;

cout<<"\ntotal time required = "<< dur.count();

return 0;
}