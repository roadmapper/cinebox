#include <altera_up_ps2_keyboard.c>
#include <altera_up_avalon_ps2.c>
#include <stdio.h>
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "altera_up_avalon_video_character_buffer_with_dma.h"

alt_up_ps2_dev * ps2_keyboard;
alt_up_char_buffer_dev * char_buf_dev;
alt_up_pixel_buffer_dma_dev * pixel_buf_dev;

KB_CODE_TYPE *kb;
alt_u8 *buf;
unsigned char *byte;
char *ascii;
volatile int * red_LED_ptr = (int *) 0x00021020; // red LED address
volatile int coordinateX, coordinateY;

static alt_u32 alt_alarm_func(void* isr_context, void* alt_u32);
static unsigned char translate_code(int code);

void main(void) {
//	*alarm = &a2;

// Prints a generic print statement to indicate that main is running
	printf("Welcome to DES2-115\n");
	*(red_LED_ptr) ^= 0x1; // Blinks LED0 using software delay

	// Open the PS2 port
	ps2_keyboard = alt_up_ps2_open_dev(PS2_NAME);

//	alt_printf("Reseting Keyboard...%d", reset_keyboard());

	if (ps2_keyboard == NULL)
		alt_printf("Error: could not open character PS2 device\n");
	else
		alt_printf("Opened character PS2 device\n");

	// Initialize keyboard
	alt_up_ps2_init(ps2_keyboard);
	alt_u8 rate;
	rate = 0x00;
	set_keyboard_rate(ps2_keyboard, rate);

//	printf("Device Type: %i\n", ps2_keyboard->device_type);

	alt_up_ps2_enable_read_interrupt(ps2_keyboard);

	alt_irq_register(PS2_IRQ, NULL, alt_alarm_func);

	//VGA

	char_buf_dev = alt_up_char_buffer_open_dev("/dev/char_buffer");
	// open the Char Buffer port
	if (char_buf_dev == NULL)
		alt_printf("Error: could not open char buffer device \n");
	else
		alt_printf("Opened char buffer device \n");

	alt_up_char_buffer_clear(char_buf_dev);
//	alt_up_char_buffer_string(char_buf_dev, "ECE4440 Team MSB", 5, 5);
	coordinateX = 5;
	coordinateY = 5;

		// open the Pixel Buffer port
		pixel_buf_dev = alt_up_pixel_buffer_dma_open_dev("/dev/pixel_buffer");
		if (pixel_buf_dev == NULL)
			alt_printf("Error: could not open pixel buffer device \n");
		else
			alt_printf("Opened pixel buffer device \n");
		//Clear and draw a blue box on the screen
		alt_up_pixel_buffer_dma_clear_screen(pixel_buf_dev, 0);
		alt_up_pixel_buffer_dma_swap_buffers(pixel_buf_dev);

	while (1) {

	}
}

static alt_u32 alt_alarm_func(void* isr_context, void* alt_u32) {
	alt_up_ps2_disable_read_interrupt(ps2_keyboard);

//	unsigned int ctrl_reg;
//	ctrl_reg = IORD_ALT_UP_PS2_PORT_CTRL_REG(ps2_keyboard->base);
//	printf("Old RI: %d...", read_RI_bit(ctrl_reg));
//	alt_up_ps2_clear_interrupt_flag(ps2_keyboard);
//	ctrl_reg = IORD_ALT_UP_PS2_PORT_CTRL_REG(ps2_keyboard->base);
//	printf("New RI: %d...\n", read_RI_bit(ctrl_reg));

	buf = (alt_u8 *) malloc(sizeof(alt_u8));
	byte = (unsigned char *) malloc(sizeof(unsigned char));
	ascii = (char *) malloc(sizeof(char));

	int status = alt_up_ps2_read_data_byte(ps2_keyboard, byte);
//	printf("Byte: %c, Status: %d...\n", *byte, status);

	int num = decode_scancode(ps2_keyboard, kb, buf, ascii);
//	printf("String: %s, Status: %d\n\n", *ascii, num);

//	printf("Char: %c\nHex: %d\n", *byte, *byte);
	unsigned char translated;
	translated = translate_code((int) (*byte));

	if (translated != '\0') {
		printf("%c", translated);
		alt_up_char_buffer_draw(char_buf_dev, translated, coordinateX, coordinateY);
		coordinateX+=1;
	}

	free(buf);
	free(byte);
	free(ascii);

	volatile int i;
	for (i = 0; i < 1000000; i++) {

	}
	alt_up_ps2_enable_read_interrupt(ps2_keyboard);

	return 0;
}

static unsigned char translate_code(int code) {
	switch (code) {
	case 21:
		return 'q';
		break;
	case 29:
		return 'w';
		break;
	case 36:
		return 'e';
		break;
	case 45:
		return 'r';
		break;
	case 44:
		return 't';
		break;
	case 53:
		return 'y';
		break;
	case 60:
		return 'u';
		break;
	case 67:
		return 'i';
		break;
	case 68:
		return 'o';
		break;
	case 77:
		return 'p';
		break;
	case 28:
		return 'a';
		break;
	case 27:
		return 's';
		break;
	case 35:
		return 'd';
		break;
	case 43:
		return 'f';
		break;
	case 52:
		return 'g';
		break;
	case 51:
		return 'h';
		break;
	case 59:
		return 'j';
		break;
	case 66:
		return 'k';
		break;
	case 75:
		return 'l';
		break;
	case 26:
		return 'z';
		break;
	case 34:
		return 'x';
		break;
	case 33:
		return 'c';
		break;
	case 42:
		return 'v';
		break;
	case 50:
		return 'b';
		break;
	case 49:
		return 'n';
		break;
	case 58:
		return 'm';
		break;
	case 22:
		return '1';
		break;
	case 30:
		return '2';
		break;
	case 38:
		return '3';
		break;
	case 37:
		return '4';
		break;
	case 46:
		return '5';
		break;
	case 54:
		return '6';
		break;
	case 61:
		return '7';
		break;
	case 62:
		return '8';
		break;
	case 70:
		return '9';
		break;
	case 69:
		return '0';
		break;
	case 117:
		return 'â†‘';
		break;
	case 107:
		return 'â†�';
		break;
	case 114:
		return 'â†“';
		break;
	case 116:
		return 'â†’';
		break;
	case 41:
		return ' ';
		break;
	case 73:
		return '.';
		break;
	case 65:
		return ',';
		break;
	case 74:
		return '?';
		break;
	case 18:
		return '!';
		break;
	case 90:
		return '\n';
		break;
	default:
		return '\0';
	}
}
