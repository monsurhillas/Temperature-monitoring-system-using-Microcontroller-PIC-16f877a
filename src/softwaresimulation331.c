// Lcd pinout settings
sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D7 at RB5_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D4 at RB2_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D7_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB2_bit;
int vref = 5 ; // its your applied voltage change if 3.3 or 3.7 etc
int tmp;   // intialzie variable int as tmp
int temp_celcius;
char tmp1[3]; // intialize char to store a string of 3 chars
void main() {


LCD_Init(); //Intializes the LCD modules
DElay_ms(250);
ADC_Init(); // Initializes the ADC Module for ADC Conversions
Delay_ms(250);
TRISD = 0x00;
PORTD=0x00;


LCD_OUT(1,1, " CSE331 ");// LCD Will display at row 1 column 1 Learning.
LCD_OUT(2,2, "PROJECT"); // LCD Will display at row column 2 Microcontrollers.
Delay_ms(2000); // Will display this for 2 seconds
Lcd_Cmd(_LCD_CLEAR); // Will clear LCD for new valuse to be displayed
LCD_OUT(1,1, " TEMPERATURE ");// LCD Will display at row 1 column 1 Learning.
LCD_OUT(2,2, " CONTROL "); // LCD Will display at row column 2 Microcontrollers.
Delay_ms(2000); // Will display this for 2 seconds
Lcd_Cmd(_LCD_CLEAR); // Will clear LCD for new valuse to be displayed
while(1) // Needed for operations its an internal loop which keeps on executing
{
tmp = ADC_Read(0); // ADC read from pin AN 0
Delay_ms(50);

temp_celcius = ( tmp * vref )/ 10 ;
delay_ms(20);


IntToStr(temp_celcius, tmp1);// will convert values of tmp to tmp1
delay_ms(20);

// Now we can display this string on LCD

Lcd_Cmd(_LCD_CLEAR); // Precaution clear for readings to be displayed
if(temp_celcius>35)
{
 PORTD.f6=1;
}
else 
{
 PORTD.f6=0;
}

 LCD_OUT(1,1, "Temp = ");
 LCD_OUT(1,10,tmp1); // I changed column number to display result after above helping string
 Delay_ms(800);

Lcd_Cmd(_LCD_CLEAR); // Then clear LCD for new values




}

}