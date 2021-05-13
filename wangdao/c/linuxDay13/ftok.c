#include <func.h>

int main(int argc, char* argv[])
{
    key_t key =ftok(argv[1],1);
    printf("key=%d\n",key);
 
}

