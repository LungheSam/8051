#include <reg51.h>
sbit relay=P2^3;
sbit switcH=P1^3;
sbit led=P1^4;
void main(void){
	led=0;
	while(1){
		relay=switcH?0:1;
		led=switcH?0:1;
	}
}