#include <reg51.h>

sbit rs=P2^0;
sbit en=P2^1;
//data is on P3 (P3.0 -> P3.7)
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_print(unsigned char *str);
void set_cursor(unsigned int row, unsigned int column);
void lcd_clear();
void delay(unsigned int time){
	unsigned int i,j;
	for (i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}
void main(){
	lcd_init();
	//lcd_data('S');
	//lcd_data('a');
	//lcd_data('m');
	//lcd_data('u');
	//lcd_data('e');
	//lcd_data('l');
	lcd_print("Hello World");
	delay(1000);
	set_cursor(2,4);
	lcd_print("Samuel Lunghe");
	delay(1000);
	lcd_clear();
	set_cursor(1,1);
	lcd_print("8051 uC");
	while (1);
}
void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
} 
void lcd_cmd(unsigned char cmd){
	rs=0;
	P3=cmd;
	en=1;
	delay(5);
	en=0;
}
void lcd_data(unsigned char dat){
	rs=1;
	P3=dat;
	en=1;
	delay(5);
	en=0;
}
void lcd_print(unsigned char *str){
	while (*str != '\0'){
		lcd_data(*str);
		str++;
	}
}
void set_cursor(unsigned int row, unsigned int column){
	switch(row){
		case 1:
			lcd_cmd(0x80+column-1);
			break;
		case 2:
			 lcd_cmd(0xC0+column-1);
			 break;
		default:
			lcd_cmd(0x80);
		  break;
	}
}
void lcd_clear(){
	lcd_cmd(0x01);
}