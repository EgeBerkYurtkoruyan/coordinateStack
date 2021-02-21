//
//  main.cpp
//  CS_204_HW4
//
//  Created by Ege Berk Yurtkoruyan on 12.03.2020.
//  Copyright © 2020 Ege Berk Yurtkoruyan. All rights reserved.
//

#include "coordinateStack.hpp"   // <iostream> is already included in the "coordinateStack.hpp"
#include <fstream>


using namespace std;

void print_matrix(char** matrix , int rows , int columns){
//    THIS FUNCTION WILL PRINT THE MATRIX CHARACTER BY CHARACTER.
    cout << endl;
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < columns ; c++){
            cout << matrix[r][c] << " " ;
        }
        cout << endl;
    }
}

int valid_input(string s){
//   I used this function to check row input and column input since they both have the same requirements. s refers to "columns" or "rows".
    int input;
    bool loop = true;
    
    do{
        cout << "Enter the number of " << s << ": ";
        cin >> input;
        string error;
        
        if(!cin){
            cin.clear();
            cin >> error;
            cout << error << " is not valid!" << endl;
            error = "";
        }else if(input < 3){
            cout << input << " is not valid!" << endl;
            
        }else
            loop = false;
    
    }while(loop);
    
    return input;
}


void fill_matrix(char** & matrix , int row , int column , char input){
//      THIS FUNCTION WILL FILL THE EMPTY MATRIX PART WITH THE GIVEN INPUT STARTING FROM THE GIVEN INPUT.
    stack_coords s;
    matrix[row][column] = input;
    s.push(row, column);
    
    int x = row, y =  column;
 
        while(!s.isEmpty()){
            
//            these if statements below pushes the empty x and y values to the struct while filling them with the character.
            
            if(matrix[x+1][y] == ' '){
                s.push(x+1 , y);
                matrix[x+1][y] = input;
            }
            if(matrix[x][y+1] == ' '){
                s.push(x , y+1);
                matrix[x][y+1] = input;
            }
            if(matrix[x-1][y] == ' '){
                s.push(x-1 , y );
                matrix[x-1][y] = input;
            }
            if(matrix[x][y-1] == ' '){
                s.push(x , y-1);
                matrix[x][y-1] = input;
            }
            
            s.pop(x,y);  // the values of x and y will be changing after this expression. since it is a pass by referance function.
        }
}

int main(){
    
    int row_num , col_num;
    
    row_num = valid_input("rows");   // this func gets the row input from the user until the input is a valid one.
    col_num = valid_input("columns");   // this func gets the column input from the user until the input is a valid one.
    
    char** matrix;
    matrix = new char* [row_num];
    for (int i = 0 ; i < row_num ; i++)
        matrix[i] = new char [col_num];
//    this part will create a 2D array a.k.a. the matrix.
    
    
    ifstream file;
    string file_name;
    
    do {
        cout << "Please enter file name: " ;
        cin >> file_name;
        file.open(file_name.c_str());
        
        if(!file)
            cout << "Cannot open a file named " << file_name << endl;
        
    } while (!file);
    
    int row_count = 0 ;
    string line;
    
    while (getline(file,line)) {    // this part will read the file line by line and fill the matrix with the (x) characters and spaces.
        
        for(int i = 0 ; i < line.length() ; i++){
            matrix[row_count][i] = line[i];
        }
        
        row_count++;
        
    }
    
    int row_input, col_input;
    bool invalid ;
    string error;
    
    do {
        cout << "Enter the starting point: ";
        cin >> row_input;
        
        bool error_bool = false;
        
        if(cin.fail()){
            cin.clear();
            cin >> error;
            error_bool = true;
        }
        
        cin >> col_input;
        
        if(cin.fail()){
            cin.clear();
            cin >> error;
            error_bool = true;
        }
        
        if (!error_bool && row_input > 0 && col_input > 0 && row_input < row_num && col_input < col_num){
            
            if(matrix[row_input][col_input] == 'X'){
                   cout << "Starting point is already occupied." << endl;
                   cout << "Terminating..." << endl;
               }else{
                   
                   char chr_input;
                   
                   do{
                       cout << "Enter the filling char: " ;
                       cin >> chr_input;
                       
                       if (chr_input =='x' || chr_input == 'X')
                           cout << "Filling char is not valid!" << endl;
                       
                   }while(chr_input == 'x' || chr_input == 'X');
                   
                   fill_matrix(matrix, row_input, col_input, chr_input);
                   print_matrix(matrix, row_num, col_num);
               }
            
            invalid = false;
        }else if ( !error_bool && (col_input < 0 || row_input < 0) ){
            invalid = true;
        }else{
            invalid = true;
        }
        
        
        if(invalid)
            cout << "Invalid coordinate!" << endl;
        
    } while (invalid);
  
    return 0;
}
