/**************************************************************************
在FSM2.c中，使用函数调用的方式进行状态之间的切换，看上去很好的实现了功能，也简化了代码，
但在实际的应用，首先，FSM的状态数可能会有许多，每个状态实现的功能也会完全不同，在这种情
况下，使用FSM2中方法就会显得力不从心，FSM的运行效率也会变得很低。在本例中，尝试使用函数
指针数组的方法来实现此功能。
**************************************************************************/
void xpc_delay(int num)
{
    int i, j = 0;
    for(i = 0; i < 10000; i++)
      for(j = 0; j < num; j++);
    
    return;
}

int funcA(void)
{
    printf("A, Today is good day!\n");   

    return 1;
}

int funcB(void)
{
    printf("B, Tommorrow is good day!\n");     
    return 1;
}

int funcC(void)
{
    printf("C, Everyday is good day!\n");      
    return 1;
}

int (*function[3])(void) = {funcA,funcB,funcC};    //使用函数指针数组

int main (void)
{
    static int state = 0;
    printf("Let begin!\n");
    
    while(1)
    {
        xpc_delay(1000);
        
        if(state > 2)    //数组溢出风险判断
        {
            state = 0;
        }
        
        function[state]();    //函数指针数组的使用
        state++;
        
    }   
    return 0;
}


