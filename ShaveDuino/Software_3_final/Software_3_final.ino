/****************************************************************************************************************/
/*    ______   __                            __              _______                                       __   */
/*   /      \ |  \                          |  \            |       \                                     |  \  */
/*  |  $$$$$$\| $$   __  __    __  _______  | $$   __       | $$$$$$$\  ______    ______    ______    ____| $$  */
/*  | $$___\$$| $$  /  \|  \  |  \|       \ | $$  /  \      | $$__/ $$ /      \  |      \  /      \  /      $$  */
/*   \$$    \ | $$_/  $$| $$  | $$| $$$$$$$\| $$_/  $$      | $$    $$|  $$$$$$\  \$$$$$$\|  $$$$$$\|  $$$$$$$  */
/*   _\$$$$$$\| $$   $$ | $$  | $$| $$  | $$| $$   $$       | $$$$$$$\| $$  | $$ /      $$| $$   \$$| $$  | $$  */
/*  |  \__| $$| $$$$$$\ | $$__/ $$| $$  | $$| $$$$$$\       | $$__/ $$| $$__/ $$|  $$$$$$$| $$      | $$__| $$  */
/*   \$$    $$| $$  \$$\ \$$    $$| $$  | $$| $$  \$$\      | $$    $$ \$$    $$ \$$    $$| $$       \$$    $$  */
/*    \$$$$$$  \$$   \$$  \$$$$$$  \$$   \$$ \$$   \$$       \$$$$$$$   \$$$$$$   \$$$$$$$ \$$        \$$$$$$$  */
/*                                                                                                              */ 
/*                                                                                                              */ 
/*                                                                                                              */
/*   Arduino skunk board software version 2.5 2013                                                              */ 
/*   Authors: Jeroen Nijdam, Arjan Hagting                                                                      */
/*                                                                                                              */ 
/*	 See change log.txt for changes                                                                         */
/*                                                                                                              */
/*   Copyright Philips Consumer Lifestyle 2012 under the Creative Commons Attribution 3.0 Unported (CC BY 3.0)  */ 	
/*                                                                                                              */
/****************************************************************************************************************/


#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

/* Digital I/O definitions*/     
                     
#define   MOTORSENSE1                 A2   /* Analog input for current sensing h-bridge 1   */
#define   MOTORSENSE2                 A1   /* Analog input for current sensing h-bridge 2   */

#define   MOTOR2_H	              5    
#define   M1LT			      9    /* Left upper P-Fet of H-bridge*/ 	
#define   M1RT                        10   /* Right upper P-Fet of H-bridge*/ 	
#define   M1LB                        11   /* Left lower N-Fet of H-bridge*/
#define   M1RB                        6    /* Right lower N-Fet of H-bridge*/

#define   USBDETECT                   2    /* USB available input                           */ 
#define   ONBUTTON                    3    /* Input from button on PCB (active low)         */
#define   LEDPIN                      A0   /* Output connected to led (active high)         */
#define   CHARGEPIN                   4    /* Output to enable the charging (active high)   */   
#define   INTERRUPTPIN                3    /* Button interrupt On/ Off button (work around) */ 	

/* Definitions of the extra unused ports */

/*Digital*/

/*Analog*/
#define   ADC3                        A3
#define   ADC4                        A4
#define   ADC5                        A5
#define   ADC6                        A6
#define   ADC7                        A7

/*Constants */
#define   ADC_SAMPLES                 3     /* Number of samples taken for current measuring */
#define   CLOCKWISE                   1     /* Constant for motor control function           */
#define   COUNTERCLOCKWISE            2     /* Constant for motor control function           */
#define   STOP                        0     /* Constant for motor control function           */
#define   BATTERY_MAX                 4200  /* Max charging voltage battery                  */
#define   CHARGE_TRIGGER              4150  /* Trigger voltage for charing                   */ 
#define   BATTERY_MIN		      3300  /* Battery Shutdown voltage                      */	
#define   SHORT_PRESS                 10    /* Delay * 4mS                                   */
#define   LONG_PRESS                  500   /* Delay * 4mS                                   */
#define   MOTOR1                      1     /* Constant for controlling the bridge           */
#define   MOTOR2                      2     /* Constant for controlling the bridge           */
#define   TRUE                        1     /* Arduino fix                                   */ 
#define   FALSE                       0     /* Arduino fix                                   */ 
#define   SLEEPTIME		      10    /* Sleep timeout in seconds                      */
#define   RESISTORSENSE               0.50  /* Value of the shunt resistor for calculation   */ 


/*Variables needed for basic functions of the shaveduino*/

/*Timing variables*/
int             Second_Counter              =  0;
int             Sleep_Counter               =  0;  
unsigned  long  Loop_Counter                =  0;
boolean         time_hundred_millis         =  FALSE;
boolean         time_one_second             =  FALSE;




/* Timer 1 preset variables                                                                      */
/* interrupt frequency (Hz) = (Arduino clock speed) / (prescaler * (compare match register + 1)) */
/* Timer1_Value = 0..65536                                                                       */           
/* Timer1_Prescaler = 1,8,64,256,1024                                                            */

unsigned  int      Timer1_Value        = 0;
          byte     Timer1_Prescaler    = 0; 
  
/* Timer 2 preset variables*/
/* (255-timer2_value) *(prescaler)/ Clock speed = interrupt*/
          byte     Timer2_Value           = 200;
          byte     Timer2_Prescaler       = 0x04;

/*Motor regulation variables*/
          boolean  Motor1On_Flag        = FALSE; /* FALSE = motor off TRUE = motor on          */
	  boolean  Motor2On_Flag        = FALSE; /* FALSE = motor off TRUE = motor on          */	
	 
/*Battery and Power management*/
unsigned  int     Battery_Voltage     = 0;
unsigned  int     Motor_Current       = 0;
          double  Motor_Current_Temp  = 0;   
          boolean USB_Flag            = FALSE; /* FALSE = USB off  TRUE = USB on              */ 
          boolean Battery_Full_Flag   = FALSE;  /* FALSE = battery empty  TRUE = battery full */          
		  
/*Button variables*/
          boolean Short_Press_Flag    = FALSE;
          boolean Long_Press_Flag     = FALSE;
unsigned  int     Debounce_Counter    = 0;
          boolean Buttonpressed       = FALSE;

/*Serial variables*/
          String  string1,dataserial, readString; 
		  
void setup()
{
    pinMode(ADC4, OUTPUT);
    pinMode(M1LT, OUTPUT);
    pinMode(M1RT, OUTPUT);
    pinMode(M1LB, OUTPUT);
    pinMode(M1RB, OUTPUT);
    pinMode(MOTOR2_H, OUTPUT);
    pinMode(CHARGEPIN, OUTPUT);
    pinMode(LEDPIN, OUTPUT);
    pinMode(ONBUTTON, INPUT);
    pinMode(USBDETECT, INPUT);
    pinMode(INTERRUPTPIN,INPUT);
    pinMode(MOTORSENSE1, INPUT);
    pinMode(MOTORSENSE2, INPUT);
    
    digitalWrite(M1LT, FALSE);
    digitalWrite(M1RT, FALSE);
    digitalWrite(M1LB, FALSE);
    digitalWrite(M1RB, FALSE);
    digitalWrite(MOTOR2_H, FALSE);
    digitalWrite(CHARGEPIN, FALSE);
    analogReference(INTERNAL); 
    
	Serial.begin(9600);
	setPwmFrequency(10,1);
        
    /*Hardware timer interrupt enable or disable*/
    
    /* Note: Timer 1 is used for PWM and there fore disabled */
  
  /* set_interrupt_timer1(); */
	 set_interrupt_timer2(); /* Used for the overall timing of the software */
}

/* ******************************************************************************/ 
/* Function:    loop                                                            */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Main loop                                                       */
/* **************************************************************************** */
void loop()
{
   /*Basic essential functions do not comment*/  
   do_read_buttons();
   serialread();     
 
     if (Loop_Counter >=500)  // checked 100ms       
  {  
  hundredmilli();
  Loop_Counter = 0;
  Second_Counter++;
  }
  
 if (Second_Counter >= 10)
  { 
   one_second();
   Second_Counter = 0;
  }
   /*Space for extra functions*/ 

  if ((Short_Press_Flag == TRUE) && (Motor2On_Flag == FALSE))
  {
   Short_Press_Flag = FALSE;
   do_motor_control(MOTOR2,CLOCKWISE,255);
  }

  if ((Short_Press_Flag == TRUE) && (Motor2On_Flag == TRUE))
  {
   Short_Press_Flag = FALSE;
   do_motor_control(MOTOR2,STOP,0);
  }
} 


/* ******************************************************************************/ 
/* Function:    hundermili                                                      */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Functions that need to be done every hundred milliseconds should */
/*              be placed in this subroutine.                                   */
/* **************************************************************************** */
void hundredmilli(void)
{ 
/*Basic essential functions do not comment*/
 //********************************************************************************************************************************************** 
   
}

/* ******************************************************************************/ 
/* Function:    one_second                                                      */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Functions that need to be done every second should              */
/*              be placed in this subroutine.                                   */ 
/* **************************************************************************** */
void one_second (void)
{   
 
  do_battery_manager();                                                        // perform every second a check on charge status and USB power status 
 
   if((USB_Flag == FALSE) && (Motor1On_Flag == FALSE) && Motor2On_Flag == FALSE && Buttonpressed == FALSE) // sleep mode state check when motors and USB power is off
   { 
     Sleep_Counter++;  
     sleepmode();
   }
   else
   {
     Sleep_Counter=0;
   }  
}

/* ******************************************************************************/ 
/* Function:    do_battery_manager                                              */
/* Input:       USBDETECT                                                       */
/* Output:      CHARGEPIN, LEDPIN                                               */
/* Return:      None                                                            */
/* Remarks:     Handle the battery charging and discharging                      */
/* **************************************************************************** */
void do_battery_manager (void)
{
      Battery_Voltage = readVcc();

      if (digitalRead(USBDETECT))
      {  
        USB_Flag = TRUE;  
		
		if(Battery_Voltage > BATTERY_MAX)
		{
		 digitalWrite(CHARGEPIN,FALSE);
		 digitalWrite(LEDPIN, FALSE);
		 Battery_Full_Flag = TRUE;
		}
		
		if(Battery_Voltage < CHARGE_TRIGGER && Battery_Full_Flag == FALSE)
                {
		 digitalWrite(CHARGEPIN,TRUE);
		 digitalWrite(LEDPIN, TRUE);
		 Battery_Full_Flag = FALSE;			
		} 	
                if(Battery_Voltage < CHARGE_TRIGGER && Battery_Full_Flag == TRUE)
                {
		 digitalWrite(CHARGEPIN,TRUE);
		 digitalWrite(LEDPIN, FALSE);
		 Battery_Full_Flag = FALSE;			
		} 		
        }
	  
	  if (digitalRead(USBDETECT) != TRUE && USB_Flag == TRUE)
	   {
            USB_Flag = FALSE;
            digitalWrite(LEDPIN, FALSE);
            Battery_Full_Flag = FALSE;		
            }	
	   
	  if (Battery_Voltage < BATTERY_MIN && (Motor1On_Flag == TRUE || Motor2On_Flag == TRUE) )
	   {
	    stop_motors();
	    Battery_Full_Flag = FALSE;
	   }		
}

/* ******************************************************************************/ 
/* Function:    stop_motors                                                     */
/* Input:                                                                       */
/* Output:                                                                      */
/* Return:      None                                                            */
/* Remarks:     Stop all the motors                                             */
/* **************************************************************************** */
void stop_motors(void)
{
 do_motor_control(MOTOR1,STOP,0);
 do_motor_control(MOTOR2_H,STOP,0);
 Motor1On_Flag == FALSE;
 Motor2On_Flag == FALSE;
 }

/* ******************************************************************************/ 
/* Function:    set_interrupt_timer1                                            */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Should be called if the timer1 interrupt is needed	        */
/*	        Timer1 can only be enabled if no motor regulation is needed     */	
/* **************************************************************************** */  
void set_interrupt_timer1(void)
{
  cli();                     /* disable global interrupts */
  TCCR1A = 0;                /* set entire TCCR1A register to 0 */
  TCCR1B = 0;                /* same for TCCR1B */
  OCR1A = Timer1_Value;      
  
  switch(Timer1_Prescaler)
  {
   case 1:
          TCCR1B |= (0x01);
   break; 

   case 8:
          TCCR1B |= (0x02);
   break;
  
   case 64:
          TCCR1B |= (0x03);          
   break;
  
   case 256:
          TCCR1B |= (0x04);
   break;
  
   case 1024:
          TCCR1B |= (0x05);  
   break;
  }
  
  TCCR1B |= (1 << WGM12);    /* turn on CTC mode: */
  TIMSK1 |= (1 << OCIE1A);   /* enable timer compare interrupt: */
  sei();                     /* enable global interrupts: */
}

/* ******************************************************************************/ 
/* Function:    TIMER1_COMP_vect                                                */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Function called when timer 1 gets an overflow interrupt         */
/* **************************************************************************** */
ISR(TIMER1_COMPA_vect)
{
 /*Place the code here for the TIMER1 interrupt routine.
 /*Some pwm pins(D9 and D10) won't work anymore after uses of the TIMER1 interrupt routine*/

}  

/* ******************************************************************************/ 
/* Function:    set_interrupt_timer2                                            */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Should be called if the timer2 interrupt is needed		*/
/* Timer2 can only be enabled if no hardware timer is needed		        */	
/* **************************************************************************** */ 
void set_interrupt_timer2(void)
{
  cli();                     /* disable global interrupts */
  TCCR2B = 0x00;             /*Disbale Timer2 while we set it up */
  TCNT2  = Timer2_Value;     /*Reset Timer Count to 130 out of 255 */
  TIFR2  = 0x00;             /*Timer2 INT Flag Reg: Clear Timer Overflow Flag */
  TIMSK2 = 0x01;             /*Timer2 INT Reg: Timer2 Overflow Interrupt Enable */
  TCCR2A = 0x00;             /*Timer2 Control Reg A: Wave Gen Mode normal */
  TCCR2B = Timer2_Prescaler; /*Timer2 Control Reg B: Timer Prescaler set to 128 */
  sei();
}

/* ******************************************************************************/ 
/* Function:    TIMER2_OVF_vect                                                 */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Function called when timer 2 gets an overflow interrupt      	*/	
/* **************************************************************************** */ 
ISR(TIMER2_OVF_vect) 
{
  Loop_Counter ++;
  TCNT2 = Timer2_Value;         
  TIFR2 = 0x00;          //Timer2 INT Flag Reg: Clear Timer Overflow Flag
}

/* ******************************************************************************/ 
/* Function:    setPwmFrequency                                                 */
/* Input:       int pin, int divisor                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Sets the hardware pwm frequency							      	*/	
/* **************************************************************************** */ 

void setPwmFrequency(int pin, int divisor) 
{
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

/* ******************************************************************************/ 
/* Function:    do_read_buttons                                                 */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Read the status of the on/off button. Other buttons should also */
/*              placed in this function                                         */	
/* **************************************************************************** */
void do_read_buttons() 
{ 
  if (!digitalRead(ONBUTTON))
        {
         Buttonpressed = true;
          delay(1);
             if(Debounce_Counter >254)
             {
             Debounce_Counter = 255;
             }
             else
             {
             Debounce_Counter++; 
             }
          } 
   if (digitalRead(ONBUTTON))
       {
   	  Buttonpressed = false; 
            if (Debounce_Counter > SHORT_PRESS)
             {
	         if (Debounce_Counter > LONG_PRESS)
                 {		 
		 Debounce_Counter = 0;   
                 Short_Press_Flag = FALSE;
		 Long_Press_Flag = TRUE;
		 return;		 
                 }			     
	Debounce_Counter = 0;   
        Short_Press_Flag = TRUE;
	Long_Press_Flag = FALSE;	
 	}
     }
}        

/* ******************************************************************************/ 
/* Function:    pinInterrupt                                                    */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Function is a work around to get the processor out of sleep mode*/
/*              when the on/off button is pressed                               */	
/* **************************************************************************** */
void pinInterrupt(void)
{	
	detachInterrupt(1);
 ADCSRA |= (1 << ADEN);
    return;
}

/* *******************************************************************************/ 
/* Function:    readVcc                                                          */
/* Input:       None                                                             */
/* Output:      None                                                             */
/* Return:      Long                                                             */
/* Remarks:     Calculate the battery voltage by measuring the ADC 1.1V reference*/	
/* *******************************************************************************/
unsigned int readVcc() 
{ 
  ADMUX = 0b01001110;
 
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA,ADSC)); // measuring
 
  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
  uint8_t high = ADCH; // unlocks both
 
  long result = (high<<8) | low;
 
  result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000

  return int(result); // Vcc in millivolts
}

/* ******************************************************************************/ 
/* Function:    readMotorcurrent                                                */
/* Input:       byte motor. int Number_Samples                                  */
/* Output:      None                                                            */
/* Return:      Integer                                                         */
/* Remarks:     Reads the actual motor current average with x number of samples */	
/* **************************************************************************** */
int readMotorcurrent(byte motor, int Number_Samples)
{ 
  int i = 0;
  
  if (motor == 1)
  { 
   for (i=0 ; i<Number_Samples; i++)
   {
    Motor_Current = analogRead(MOTORSENSE1) * ((readVcc())/1024);		
    Motor_Current_Temp = Motor_Current_Temp + Motor_Current;
   }
  }
 
  if (motor == 2)
  {
    for (i=0 ; i<Number_Samples; i++)
     {
      Motor_Current = analogRead(MOTORSENSE2) * ((readVcc())/1024);		
      Motor_Current_Temp = Motor_Current_Temp + Motor_Current;
     }
  }
 
 Motor_Current = Motor_Current_Temp/Number_Samples/RESISTORSENSE;
 Motor_Current_Temp = 0;
 return int(Motor_Current);
}

/* ******************************************************************************/
/* Function:    sleepmode                                                       */
/* Input:       unsigned int                                                    */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Puts the processor in sleepmode after a certain amounts of sec  */
/* **************************************************************************** */
void sleepmode()
{
 if (Sleep_Counter >= SLEEPTIME)
  {
   Sleep_Counter = 0;
   Second_Counter = 0;
   time_one_second = FALSE;
 
   for (int z = 0; z < 6; z++)
   {
    digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    delay(200);	
   }
   digitalWrite(LEDPIN, FALSE);
   //digitalWrite(CHARGEPIN,FALSE);           /* turn charger off */
   delay(100);
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);     // Choose our preferred sleep mode: 
   attachInterrupt(1, pinInterrupt, LOW);
   ADCSRA &= ~(1 << ADEN);
   sleep_enable();                          // Set sleep enable (SE) bit:
   sleep_mode();                            // Put the device to sleep:
   sleep_disable();                         // Upon waking up, sketch continues from this point.
   return;
  }
}         

/* ******************************************************************************/ 
/* Function:    motor_control                                                   */
/* Input:       byte motor, byte action, byte speed                             */
/* Output:      M1LB, M1RB, M1LT, M1RT, MOTOR2_H                                */
/* Return:      None                                                            */
/* Remarks:     Control the two motor bridges. (Speed only works for motor2)    */	
/* **************************************************************************** */
void do_motor_control(byte motor, byte action,byte speed)
{
    switch(action){

    case STOP:
           	   
	        if(motor == MOTOR1)
		   {
                        Motor1On_Flag = FALSE;
		        digitalWrite(M1LB, FALSE);
			digitalWrite(M1RB, FALSE);
			analogWrite(M1LT,0);
			analogWrite(M1RT, 0);
		   }	 
   		 if(motor == MOTOR2)
		   {
		    Motor2On_Flag = FALSE;
                    digitalWrite(MOTOR2_H, FALSE);       
		   }
    break;
  
    case COUNTERCLOCKWISE:
		   
		   if(motor == MOTOR1)
		   {
		        Motor1On_Flag = TRUE;
                        digitalWrite(M1LB, FALSE);
			digitalWrite(M1RT, FALSE);
			delay(5);
			digitalWrite(M1RB, TRUE);
			analogWrite(M1LT, speed);
		   }
		   if(motor == MOTOR2)
		   {
                    Motor2On_Flag = TRUE;
                    digitalWrite(MOTOR2_H, TRUE); 
		   }		   
    break;

    case CLOCKWISE:
		 	   
		  if(motor == MOTOR1)
		   {
                        Motor1On_Flag = TRUE;
                        digitalWrite(M1RB, FALSE);
			digitalWrite(M1LT, FALSE);
			delay(5);
			digitalWrite(M1LB, TRUE);
			analogWrite(M1RT, speed); 
		   }
		   if(motor == MOTOR2)
		   {
                      Motor2On_Flag = TRUE;
                      digitalWrite(MOTOR2_H, TRUE);  
                   }
    break;
 }
}

/* ******************************************************************************/ 
/* Function:    serialread                                                      */
/* Input:       None                                                            */
/* Output:      None                                                            */
/* Return:      None                                                            */
/* Remarks:     Function that reads the serial port                             */	
/* **************************************************************************** */
void serialread()
{
 if (Serial.available())
 {
  char char_buffer = tolower(Serial.read());  /*gets one byte from serial buffer and if needed the char is made lowercase */
  
  /* If Cr is recognized in the serial buffer then the build string is read to see if there is a use full command inside */
  /* If there's no command that is used inside, this will we reported and the buffer and string will be emptied */
  /* For every command that is used, there will be made an IF or ELSE IF statement */
  
        if (char_buffer == '$') 
         {
                  Serial.print("$(");
		  Serial.print(readVcc());
		  Serial.print(",");
		  Serial.print(readMotorcurrent(MOTOR2,ADC_SAMPLES));
		  Serial.print(",");
		  Serial.print(Short_Press_Flag);
		  Serial.print(")");
                  Serial.print(digitalRead(USBDETECT));
		  Serial.print(")");
         }
		 else
		 {
		 Serial.flush();
		 }
  }
}












