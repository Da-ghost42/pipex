#include<stdio.h>
# include<fcntl.h>

void  do_some(int tmp)
{
    

}
int main()
{
    int tmp = open (".hello", O_RDWR | O_CREAT | O_TRUNC,0644);
    if (tmp < 0)
        return 0;
    
}