
#include<reg51.h>

	sbit rs=P2^0;
	sbit en=P2^1;
	sbit fan=P2^2;
	sbit bulb=P2^3;
	sbit led=P2^4;
	sbit buzzer=P2^5;
	
	sbit r1 = P3^0;
	sbit r2 = P3^7;
	sbit r3 = P3^2;
	sbit r4 = P3^3;
	sbit c1 = P3^4;
	sbit c2 = P3^5;
	sbit c3 = P3^6;

	unsigned int i;
	unsigned char a[100];
	sfr ldata=0x90;//port1 
	unsigned char input;

	void delay(unsigned int i);
	void lcd_cmd(unsigned char a);
	void lcd_data(unsigned char b);
	void lcd_init(void);
	void lcd_str(unsigned char *str);
	void clear(void);
	





void main()
{
	
	buzzer=0;
	lcd_init();
	lcd_cmd(0x80);
	lcd_str(" AUTOMATIC ROOM ");
	lcd_cmd(0xc0);
	lcd_str("    CONTROL ");	
	delay(65000);
	delay(65000);
	delay(65000);
	
	while(1)
		{
			buzzer=0;
			lcd_cmd(0x80);
			lcd_str(" PRESS KEYS     ");
			lcd_cmd(0xc0);
			lcd_str("   1-8        ");
			r1 = 0;
			if(c1 == 0)
			{
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" FAN is OFF ");
				lcd_cmd(0xc0);
				fan=1;          //fan off
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			if(c2 == 0)
			{
				lcd_cmd(0x01);
				fan=0;          //fan on
				lcd_cmd(0x80);
				lcd_str(" FAN is ONN ");
				lcd_cmd(0xc0);
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			if(c3 == 0)
			{
				// bulb=1;          //bulb off
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" BULB is OFF ");
				lcd_cmd(0xc0);
				bulb=1;          //bulb off
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			r2 = 0; 
			r1 = 1;
			if(c1 == 0)
			{
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" BULB is on ");
				lcd_cmd(0xc0);
				bulb=0;         // bulb on
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			if(c2 == 0)
			{
				// led=1;          //led off
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" led is OFF ");
				lcd_cmd(0xc0);
				led=1;         // led off
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			if(c3 == 0)
			{
				//led=0;        //led on
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" led is on ");
				lcd_cmd(0xc0);
				led=0;         // led on
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			r3 = 0; 
			r2 = 1;
			if(c1 == 0)
			{
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" Everything is ON ");
				lcd_cmd(0xc0);
				fan=bulb=led=0;  // all r on
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
			}
			if(c2 == 0)
			{
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str(" Everything is off ");
				lcd_cmd(0xc0);
				fan=bulb=led=1;  // all r off
				buzzer=1;
				delay(5000);
				buzzer=0;
				delay(65000);
					
			}
		}

	
}




void lcd_init()
{
 	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}


void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<i;j++);
	for(k=0;k<980;k++);
}

void lcd_cmd(unsigned char a)
{
  	rs=0;
	ldata=a;
	en=1;
	delay(5);
	en=0;
	delay(5);
}

void lcd_data(unsigned char b)
{
  	rs=1; 
	ldata=b;
	en=1;
	delay(5);
	en=0;
	delay(5);
}

void lcd_str(unsigned char *str)
{
	while(*str)
	{
		lcd_data(*str++);
	}

}



