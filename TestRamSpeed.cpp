#include "scripttimer.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
int TestRamSpeed()
{ 
    static const int howmany = 524288;
    float fourgb = (float)howmany * 8192;
    struct Script_Timer cTimer;

	printf("#Sizing Buffer To 512KB...\n",howmany);
	char buffer[howmany];
	printf("#Filling Buffer with '!'...\n");
	memset(buffer,33,howmany);

	printf("#Press any key to start.\n");
	scanf("%*c");

	printf("#Reading Through Buffer For 4GB Worth Of Data...\n");
	Start_ST(&cTimer);
	__asm
	{
		mov     ecx, 8192
		run_again:
		LEA     esi,buffer //Get the address of buffer
		MOV		ebx,howmany //Set the loop number
		buf_loop:           //Lable for beginning of loop
		mov     eax, [esi]  //Copy buffer[x] to eax
		//mov     arr,al     //copy al to arr
		inc     esi         //Increment buffer address
		dec     ebx         //Decrement loop count
		jnz     buf_loop     //jump to buf_loop if(ebx>0)
		dec     ecx
		jnz     run_again
	}
	End_ST(&cTimer);
	
	printf("[[READ SPEED]]\n");
	printf("Took: %d seconds \n", cTimer.seconds);
	printf("MB per millisecond: %f \n",((float)fourgb/(float)cTimer.milliseconds)/(float)1000000);
	printf("MB per second: %f \n",((float)fourgb/(float)cTimer.seconds)/(float)1000000);
	printf("\n");
	printf("Press any key to quit.");
	scanf("%*c");

	return 0;
}