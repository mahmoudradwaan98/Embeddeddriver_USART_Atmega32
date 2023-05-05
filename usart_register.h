/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : USART                *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/





#ifndef USART_register_H_

 #define USART_register_H_ 

	#define UCSRA                    *((volataile u8*)0x2B)   /* USART control status REGISTER A */
	#define UCSRA_RXC                7                        /* Receive complete */
	#define UCSRA_TXC                6                        /* Transmit complete */
	#define UCSRA_UDRE               5                        /* Data register empty */
	#define UCSRA_FE                 4                        /* Frame error flag bit */
	#define UCSRA_DOR                3                        /* Data overrun flag */
	#define UCSRA_PE                 2                        /* parity error flag */
	#define UCSRA_U2X                1                        /* Double speed mode */
	#define UCSRA_MBCM               0                        /* Multi processor communication bit */
 
	#define UCSRB                    *((volataile u8*)0x2A)   /* USART control status REGISTER B */
	#define UCSRB_RX                 7 
	#define UCSRB_TX                 6 
	#define UCSRB_UDRIE              5 
	#define UCSRB_RXEN               4                        /* Enable reciever */
	#define UCSRB_TXEN               3                        /* Enable transmitter */
	#define UCSRB_UCSZ2              2                        /* Character size combined with UCSZ0 , UCSZ1 , UCSRC */
	#define UCSRB_RXB8               1                        /* Used in 9 bit mode */
	#define UCSRB_TXB8               0                        /* Used in 9 bit mode */
 
 
	#define UCSRC                    *((volataile u8*)0x40)   /* USART control status REGISTER C */ 
	#define UCSRC_URSEL              7 
	#define UCSRC_UMSEL              6 
	#define UCSRC_UPM1               5 
	#define UCSRC_UPM0               4 
	#define UCSRC_USPS               3 
	#define UCSRC_UCSZ1              2 
	#define UCSRC_UCSZ0              1
	#define UCSRC_UCPOL              0 

	#define UBRRL                    *((volataile u8*)0x29)
	
    #define UBRRH	                 *((volataile u8*)0x40)
 	
	#define UDR                      *((volataile u8*)0x2C)
	
 
	
	
	
#endif