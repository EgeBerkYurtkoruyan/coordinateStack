//
//  coordinateStack.hpp
//
//  Created by Ege Berk Yurtkoruyan on 22.03.2020.
//  Copyright © 2020 Ege Berk Yurtkoruyan. All rights reserved.
//

#ifndef coordinateStack_hpp
#define coordinateStack_hpp
#include <iostream>

struct node_stack{
//    THESE NODES WILL BE THE ELEMENT OF MY STACK CLASS.
    int x , y;
    node_stack* next;
    
    node_stack() // default constructor.
        :x(0), y(0) , next(NULL)
    {}
    
    node_stack(int xx, int yy) // constructor.
        :x(xx) , y(yy) , next(NULL)
    {}
    
};

class stack_coords{   // stack_coords will be our stack.
    
    public:
    
        stack_coords();  //constructor
        ~stack_coords();  //destructor
        void push(int x , int y );
        void pop(int & x , int & y);
        bool isEmpty();
//        IN MY ALGORITHM THERE WAS NO NEED FOR COPY CONSTRUCTOR SO I DID NOT USE IT.
    private:
        node_stack* top;
        
        
};

#endif /* coordinateStack_hpp */
