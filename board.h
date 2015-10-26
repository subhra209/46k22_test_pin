#ifndef __BOARD__
#define __BOARD__

/*
*------------------------------------------------------------------------------
* board.h
*
* Include file for port pin assignments
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: board.h
*------------------------------------------------------------------------------
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include <p18f46k22.h>
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"


/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/




// HeartBeat Association
#define		HEART_BEAT				PORTEbits.RE0			// high - OFF, Low - ON
#define		HEART_BEAT_DIR			TRISEbits.TRISE0




//  UART  Association

#define 	SER1_TX					PORTCbits.RC6 		// serial transmit
#define		SER1_TX_DIR				TRISCbits.TRISC6
#define 	SER1_RX					PORTCbits.RC7			// serial receive
#define		SER1_RX_DIR				TRISCbits.TRISC7


#define 	PIN_2					PORTAbits.RA0
#define 	PIN_2_DIR				TRISAbits.TRISA0
#define 	PIN_3 					PORTAbits.RA1 
#define 	PIN_3_DIR				TRISAbits.TRISA1
#define		PIN_4					PORTAbits.RA2
#define 	PIN_4_DIR				TRISAbits.TRISA2
#define 	PIN_5 					PORTAbits.RA3 
#define 	PIN_5_DIR				TRISAbits.TRISA3
#define 	PIN_6 					PORTAbits.RA4 
#define 	PIN_6_DIR				TRISAbits.TRISA4
#define 	PIN_7 					PORTAbits.RA5
#define 	PIN_7_DIR				TRISAbits.TRISA5

#define		PIN_40					PORTBbits.RB7		
#define		PIN_40_DIR				TRISBbits.TRISB7
#define		PIN_39					PORTBbits.RB6		
#define		PIN_39_DIR				TRISBbits.TRISB6
#define		PIN_38					PORTBbits.RB5		
#define		PIN_38_DIR				TRISBbits.TRISB5
#define		PIN_37					PORTBbits.RB4		
#define		PIN_37_DIR				TRISBbits.TRISB4
#define		PIN_36					PORTBbits.RB3		
#define		PIN_36_DIR				TRISBbits.TRISB3
#define		PIN_35					PORTBbits.RB2		
#define		PIN_35_DIR				TRISBbits.TRISB2
#define		PIN_34					PORTBbits.RB1		
#define		PIN_34_DIR				TRISBbits.TRISB1
#define		PIN_33					PORTBbits.RB0		
#define		PIN_33_DIR				TRISBbits.TRISB0

#define 	PIN_15					PORTCbits.RC0 	
#define		PIN_15_DIR				TRISCbits.TRISC0
#define 	PIN_16					PORTCbits.RC1		
#define		PIN_16_DIR				TRISCbits.TRISC1
#define 	PIN_17					PORTCbits.RC2 	
#define		PIN_17_DIR				TRISCbits.TRISC2
#define 	PIN_18					PORTCbits.RC3		
#define		PIN_18_DIR				TRISCbits.TRISC3
#define 	PIN_23					PORTCbits.RC4 	
#define		PIN_23_DIR				TRISCbits.TRISC4
#define 	PIN_24					PORTCbits.RC5		
#define		PIN_24_DIR				TRISCbits.TRISC5


#define		PIN_30					PORTDbits.RD7 			
#define		PIN_30_DIR				TRISDbits.TRISD7
#define		PIN_29					PORTDbits.RD6 			
#define		PIN_29_DIR				TRISDbits.TRISD6
#define		PIN_28					PORTDbits.RD5 			
#define		PIN_28_DIR				TRISDbits.TRISD5
#define		PIN_27					PORTDbits.RD4			
#define		PIN_27_DIR				TRISDbits.TRISD4
#define		PIN_22					PORTDbits.RD3 			
#define		PIN_22_DIR				TRISDbits.TRISD3
#define		PIN_21					PORTDbits.RD2 			
#define		PIN_21_DIR				TRISDbits.TRISD2
#define		PIN_20					PORTDbits.RD1			
#define		PIN_20_DIR				TRISDbits.TRISD1
#define		PIN_19					PORTDbits.RD0			
#define		PIN_19_DIR				TRISDbits.TRISD0


#define		PIN_9					PORTEbits.RE1	
#define		PIN_9_DIR				TRISEbits.TRISE1
#define		PIN_10					PORTEbits.RE2	
#define		PIN_10_DIR				TRISEbits.TRISE2

			
/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Macros
*------------------------------------------------------------------------------
*/



#define SYSTEM_CLOCK			(16000000UL)	// 16MHz internal oscillator	

#define PERIPHERAL_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERAL_CLOCK_PERIOD 	(1 / PERIPHERAL_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(BOOL)(0xFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)

#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()

#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;// Disable global interrupt bit.


#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;// Enable global interrupt bit.

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1



#define DISABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 0
#define ENABLE_UART2_TX_INTERRUPT()		PIE3bits.TX2IE = 1

#define DISABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 0
#define ENABLE_UART2_RX_INTERRUPT()		PIE3bits.RC2IE = 1

#define DISABLE_UART1_TX_INTERRUPT()	PIE1bits.TX1IE = 0
#define ENABLE_UART1_TX_INTERRUPT()		PIE1bits.TX1IE = 1

#define DISABLE_UART1_RX_INTERRUPT()	PIE1bits.RC1IE = 0
#define ENABLE_UART1_RX_INTERRUPT()		PIE1bits.RC1IE = 1

#define ENB_485_TX()	TX_EN = 1;
#define ENB_485_RX()	TX_EN = 0

#define Delay10us(us)		Delay10TCYx(((GetInstructionClock()/1000000)*(us)))
#define DelayMs(ms)												\
	do																\
	{																\
		unsigned int _iTemp = (ms); 								\
		while(_iTemp--)												\
			Delay1KTCYx((GetInstructionClock()+999999)/1000000);	\
	} while(0)

/*
*------------------------------------------------------------------------------
* Public Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables (extern)
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Public Constants (extern)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Function Prototypes (extern)
*------------------------------------------------------------------------------
*/

extern void BOARD_init(void);

#endif
/*
*  End of device.h
*/