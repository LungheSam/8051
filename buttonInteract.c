#include <reg51.h>
sbit led=P2^3;
sbit sWitch=P2^4;
void main(void){
//	P2=0x00;
	while(1){
		if (sWitch==1){
			led=0;
		}
		else{
			led=1;	
		}
	}			
}