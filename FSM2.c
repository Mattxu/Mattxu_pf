/***************************************************************************************
在FSM1.c中使用switch-case实现了状态切换，观察A,B,C三个分支的执行情况，会发现其中都是打印当前状态，并
切换下一个状态，是一段功能相同的代码，本段使用函数的方式进行优化。
****************************************************************************************/
void xpc_delay(int num)
{
    int i, j = 0;
    for(i = 0; i < 10000; i++)
      for(j = 0; j < num; j++);
    
    return;
}

int func(char *state)
{
    printf("I am %s.\n", state);
    *state = *state + 1;
    if('D' == *state)
    {
        *state = *state - 3;
    }
    
    return 1;
}

int main (void)
{
    static char state = 'A';
    printf("Let's begin!\n");
    
    while(1)
    {
        switch(state)
        {
            case 'A':

            case 'B':

            case 'C':
            {
                func(&state);
            }
            default:
              break;
        } 
        xpc_delay(1000);
    }
    
    return 0;
}

