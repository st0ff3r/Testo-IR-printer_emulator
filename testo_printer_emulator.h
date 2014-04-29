#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
	(byte & 0x80 ? 1 : 0), \
	(byte & 0x40 ? 1 : 0), \
	(byte & 0x20 ? 1 : 0), \
	(byte & 0x10 ? 1 : 0), \
	(byte & 0x08 ? 1 : 0), \
	(byte & 0x04 ? 1 : 0), \
	(byte & 0x02 ? 1 : 0), \
	(byte & 0x01 ? 1 : 0)

#define sleep() __asm sleep __endasm

//#define TIMER0_RELOAD 0xFCC8	// 427us @ 8MHz
//#define TIMER0_RELOAD 0xF000	// ~ 2ms @ 8MHz
#define TIMER0_RELOAD 0xF323	// ~ 4 * 427us @ 8MHz
#define TIMER0_RS232_2400	0xfcf2
#define TIMER0_FSK			0xF99F	// @ 8MHz
//#define TIMER0_FSK			0xF00F
//#define TIMER0_RELOAD 0x0000
#define TIMER1_RELOAD 0xF853    // 1 ms @ 8MHz
#define TIMER2_RELOAD	0x00	// ~ 5 ms @ 8Mhz
#define TIMER3_RELOAD	0x0000	// ~ 131 ms @ 4MHz

#define SOFT_MODEM_BAUD_RATE	(1225)
#define SOFT_MODEM_LOW_FREQ		(4900)
#define SOFT_MODEM_HIGH_FREQ	(7350)

#define OUTPUT_STATE 0
#define INPUT_STATE 1

#define TRIS_COMP1		TRISAbits.RA0
#define TRIS_COMP2		TRISAbits.RA1
#define COMP1_PIN		PORTAbits.RA0
#define COMP2_PIN		PORTAbits.RA1

#define TRIS_IR_PIN		TRISBbits.RB0

#define TRIS_DEBUG_PIN	TRISBbits.RB1 
#define DEBUG_PIN		PORTBbits.RB1

#define TRIS_DEBUG2_PIN	TRISBbits.RB2
#define DEBUG2_PIN		PORTBbits.RB2

#define TRIS_DEBUG3_PIN	TRISBbits.RB3
#define DEBUG3_PIN		PORTBbits.RB3

#define TRIS_PWM_PIN	TRISCbits.RC1
#define PWM_PIN			PORTCbits.RC1

#define TRIS_RX_PIN		TRISCbits.RC7
#define RX_PIN			PORTCbits.RC7

#define TRIS_TX_PIN		TRISCbits.RC6
#define TX_PIN			PORTCbits.RC6

#define TICK 855
#define TICK_ADJ 200

void sleep_ms(unsigned long ms);

void init_system();

void my_usart_open();

unsigned char reverse(unsigned char b);

unsigned char valid_err_corr(unsigned int c);

void testo_ir_enable();
void testo_ir_disable();

void rs232_tx_enable();
void rs232_tx_disable();

void fsk_tx_enable();
void fsk_tx_disable();

void fsk_rx_enable();
void fsk_rx_disable();

void send_fsk_high(void);
void send_fsk_low(void);
void send_fsk_test(void);

unsigned int fifo_in_use();
unsigned char fifo_put(unsigned char c);
unsigned char fifo_get(unsigned char  *c);
unsigned char fifo_snoop(unsigned char *c, unsigned int pos);

void _debug();
void _debug2();

