/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan        **********************/
/****************    Layer     : MCAL                  *********************/
/****************    SWC       : USART                 ********************/
/****************    version   : 1.0                   *******************/
/************************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "USART_config.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_register.h"



void USART_voidInit(void){
	
	/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Another way to INIT USART $$$$$$$$$$$$$$$$$$$$$$$$$*/
	
	/*
	
	// fosc : 16 MHZ , baud rate : 9600 (bps) , double speed mode
	
	UBRRL = 102;
	
	UBRRH = 0;
	
	// Set Frame Format -> 8 data, 1 stop, No Parity
	
	UCSRC = 0x86;
	
	// Enable RX and TX
	
	UCSRB = 0x18; 
	
	*/
	  
	/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
	
	// Set Frame Format -> 8 data, 1 stop, No Parity
	
	u8 Local_u8UCSRCValue = 0;
	
	// 1 stop Bit
	
	CLR_BIT(Local_u8UCSRCValue,UCSRC_USPS);
	
	// Enable UCSRC Register to write values
	
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);
	
	// no parity check
	
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	
	// asynchronous mode
	
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
	
	// no interrupts
	
	
	
	// Set to 8 bit transmit data ( character size ) 
	
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	
	UCSRC = Local_u8UCSRCValue;
	
	// Disable double speed transmission mode 
	
	CLR_BIT(UCSRA,UCSRA_U2X);
	
	// TX , RX ENABLE
	
	SET_BIT(UCSRB,UCSRB_TXEN);
	
	SET_BIT(UCSRB,UCSRB_RXEN);
	
	// fosc : 8 MHZ , baud rate : 9600 (bps) , normal mode 
	
	UBRRL = 51;

	
	
	
	
}
	
void USART_voidSendData(u8 copy_u8Data){
	
	// polling wait untill Transmit buffer is empty
	
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	
	UDR = copy_u8Data;
	
}
	
u8 USART_u8ReceiveData(void){
	
	// polling wait untill RX flag is set
	
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	
	return UDR;
}
	
	
