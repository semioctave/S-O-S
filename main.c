// ***** 0. Documentation Section *****
// Flashes sos when external Switch is pressed
// Author : Harshit Srivastava
// Date: 10th December 2017

// ***** 1. Pre-processor Directives Section *****



// ***** 2. Global Declarations Section *****
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
	
// FUNCTION PROTOTYPES: Each subroutine defined

void Port_Init(void);// Initializes the port
void Delay1ms(unsigned long msec); // Delay function
// ***** 3. Subroutines Section *****

// PE0, PB0, or PA2 connected to positive logic momentary switch using 10k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
// To avoid damaging your hardware, ensure that your circuits match the schematic

void SystemInit(void)
{

}
int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
 
	Port_Init();
  
  while(1){
			int Data ;
			Data = GPIO_PORTE_DATA_R&0x01 ;      
			if ( Data == 0x00 ) // Switch is not Pressed
			{
					GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R | 0x02; // Switch on the LED             
			}
			else // Switch is pressed
			{
				int i;
				for(i=0;i<3;i++)
				{
						GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R | 0x02; // LED Toggles 
						Delay1ms(500);
						GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R &(~0x02); 
						Delay1ms(500);
				}
				
				for(i=0;i<3;i++)
				{
						GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R | 0x02; // LED Toggles 
						Delay1ms(2000);
						GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R &(~0x02); 
						Delay1ms(2000);
				
				}
				
				for(i=0;i<3;i++)
				{
						GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R | 0x02; // LED Toggles 
						Delay1ms(500);
						GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R &(~0x02); 
						Delay1ms(500);
				
				}	
			}
		}
}

void Port_Init(void)
{
		unsigned long int Delay;
		SYSCTL_RCGC2_R = SYSCTL_RCGC2_R | 0x10 ; // Enables Clock for PortE
		Delay = SYSCTL_RCGC2_R ; // Time for Clock to get stabilised
		GPIO_PORTE_AMSEL_R = 0x00; // Disables Analog Funtion
		GPIO_PORTE_AFSEL_R = 0x00; // No Alternate function selected
		GPIO_PORTE_PCTL_R  = 0x00000000; // Clears pin PCTL
		GPIO_PORTE_PUR_R   = 0x00 ; // No Pull up resistor to be activated
		GPIO_PORTE_DEN_R   = 0x03; // Enables Digital Functionality  for PE1 & PE0
		GPIO_PORTE_DIR_R   = 0x02; // Enables PE1 as O/P & PE0 as I/P
	
}

void Delay1ms(unsigned long msec){
	unsigned long i;
  while(msec > 0)
		{
				i = 13333;  // this number means 1ms
				while(i > 0)
				{
					i = i - 1;
				}
				msec = msec - 1; // decrements every 1ms// write this function

		}
}
