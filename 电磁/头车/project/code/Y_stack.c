/*
 * Y_stack.c
 *
 *  Created on: 2023��3��18��
 *      Author: ��˧��
 */

#include "zf_common_headfile.h"


//-------------------------------------------------------------------------------------------------------------------
//  ����:      ģ���ջ
//  ����:      push��ջ,pop��ջ
//  ����:      ��
//  ����:      ��˧��
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
