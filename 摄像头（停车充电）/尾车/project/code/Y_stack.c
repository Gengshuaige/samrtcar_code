/*
 * Y_stack.c
 *
 *  Created on: 2023年3月18日
 *      Author: 耿帅哥
 */

#include "zf_common_headfile.h"


//-------------------------------------------------------------------------------------------------------------------
//  主题:      模拟堆栈
//  功能:      push入栈,pop出栈
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void push_stack(uint8 stack[],uint8 element,uint8 *top) {
    stack[++*top] = element;
}

void pop_stack(uint8 stack[],uint8 *top) {
    uint8 i;
    if(*top==-1)return;
    if(*top==0) {
        stack[0] = 0;
        *top = -1;
    }else {
        for(i=0;i<*top;i++){
            stack[i] = stack[i+1];
        }
        *top--;
    }
}
