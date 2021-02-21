//
//  coordinateStack.cpp
//
//  Created by Ege Berk Yurtkoruyan on 22.03.2020.
//  Copyright © 2020 Ege Berk Yurtkoruyan. All rights reserved.
//

#include "coordinateStack.hpp"

// THE PART BELOW IS THE CONSTRUCTOR FOR STACK CLASS.

stack_coords::stack_coords(){
    top = NULL;
}

// THE PART BELOW IS THE PUSH FUNCTION. THIS FUNCTION ADDS THE REFERANCE VALUE ON TOP OF THE STACK.

void stack_coords::push(int x , int y){
    
    node_stack* ptr;
    ptr = new node_stack(x, y);
    
    if(isEmpty())
        top = ptr;
    
    else{
        ptr->next = top;
        top = ptr;
    }
}

// THE PART BELOW IS POP FUNCTION. THIS FUNCTION DELETES THE TOP ELEMENT OF THE STACK WHILE CHANGING THE REFERANCE VALUES TO THE DELETED ELEMENT'S VALUES.

void stack_coords::pop(int & x, int & y){
    
    if(isEmpty()){
        
        std::cout << "Stack is empty" << std::endl;
        
    }else{
        
        node_stack* temp = top;
        x = temp->x;
        y = temp->y;
        top = top->next;
        delete temp;
    }
}

// THE PART BELOW IS THE .isEmpty() FUNCTION. THIS FUNCTION RETURNS TRUE IF THE STACK IS EMPTY AND RETURNS FALSE OTHERWISE.

bool stack_coords::isEmpty(){
    
    if(top == NULL)
        return true;
    else
        return false;
    
}

stack_coords::~stack_coords(){
    int a, b;
    
    while(top != NULL){
        pop(a, b);
    }
    
    delete top;
}
