#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr = malloc(sizeof(int));
    int val = 2;
    ptr = &val;
    printf("%x \n",*ptr);
    //According to GDB there is segmentation fault.
    /*
    Program received signal SIGSEGV, Segmentation fault.
    0x0000555555555161 in main ()
    */
   //According to valgrind we have leaked memory. We had one allocation but 0 frees.
   /*
   ==23565== HEAP SUMMARY:
    ==23565==     in use at exit: 4 bytes in 1 blocks
    ==23565==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
    ==23565== 
    ==23565== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==23565==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==23565==    by 0x10915E: main (t2.c:6)
    ==23565== 
    ==23565== LEAK SUMMARY:
    ==23565==    definitely lost: 4 bytes in 1 blocks
    ==23565==    indirectly lost: 0 bytes in 0 blocks
    ==23565==      possibly lost: 0 bytes in 0 blocks
    ==23565==    still reachable: 0 bytes in 0 blocks
    ==23565==         suppressed: 0 bytes in 0 blocks
    ==23565== 
    ==23565== For lists of detected and suppressed errors, rerun with: -s
    ==23565== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

   */
}