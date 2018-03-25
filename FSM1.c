/* 一个简单的例子介绍FSM的工作情况，根据不同的状态，实现状态之间连续的切换*/
void xpc_delay(int num)
{
    int i, j = 0;
    for(i = 0; i < 10000; i++)
      for(j = 0; j < num; j++);
    
    return;
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
            {
                printf("I am A.\n");
                state = 'B';
                break;
            }
            case 'B':
            {
                printf("I am B.\n");
                state = 'C';
                break;
            }
            case 'C':
            {
                printf("I am C.\n");
                state = 'A';
                break;
            }
            default:
              break;
        } 
        xpc_delay(1000);
    }
    
    return 0;
}
