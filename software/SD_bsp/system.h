/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2' in SOPC Builder design 'nios2'
 * SOPC Builder design path: C:/ECE4440/DE2_115_Final/nios2.sopcinfo
 *
 * Generated: Thu Dec 05 01:13:40 EST 2013
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x303820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "small"
#define ALT_CPU_DATA_ADDR_WIDTH 0x16
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x280020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0x16
#define ALT_CPU_NAME "nios2"
#define ALT_CPU_RESET_ADDR 0x280000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x303820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_DATA_ADDR_WIDTH 0x16
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x280020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0x16
#define NIOS2_RESET_ADDR 0x280000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_UP_AVALON_PARALLEL_PORT
#define __ALTERA_UP_AVALON_PS2
#define __ALTERA_UP_AVALON_SRAM
#define __ALTERA_UP_AVALON_USB
#define __ALTERA_UP_AVALON_VIDEO_CHARACTER_BUFFER_WITH_DMA
#define __ALTERA_UP_AVALON_VIDEO_PIXEL_BUFFER_DMA
#define __ALTERA_UP_SD_CARD_AVALON_INTERFACE


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x3048b8
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x3048b8
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x3048b8
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios2"


/*
 * char_buffer_avalon_char_buffer_slave configuration
 *
 */

#define ALT_MODULE_CLASS_char_buffer_avalon_char_buffer_slave altera_up_avalon_video_character_buffer_with_dma
#define CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_BASE 0x300000
#define CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_IRQ -1
#define CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_NAME "/dev/char_buffer_avalon_char_buffer_slave"
#define CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_SPAN 8192
#define CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_TYPE "altera_up_avalon_video_character_buffer_with_dma"


/*
 * char_buffer_avalon_char_control_slave configuration
 *
 */

#define ALT_MODULE_CLASS_char_buffer_avalon_char_control_slave altera_up_avalon_video_character_buffer_with_dma
#define CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_BASE 0x3048c0
#define CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_IRQ -1
#define CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_NAME "/dev/char_buffer_avalon_char_control_slave"
#define CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_SPAN 8
#define CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_TYPE "altera_up_avalon_video_character_buffer_with_dma"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x3048b8
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * led_green configuration
 *
 */

#define ALT_MODULE_CLASS_led_green altera_up_avalon_parallel_port
#define LED_GREEN_BASE 0x3048a0
#define LED_GREEN_IRQ -1
#define LED_GREEN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_GREEN_NAME "/dev/led_green"
#define LED_GREEN_SPAN 16
#define LED_GREEN_TYPE "altera_up_avalon_parallel_port"


/*
 * onchip_mem configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_mem altera_avalon_onchip_memory2
#define ONCHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_BASE 0x280000
#define ONCHIP_MEM_CONTENTS_INFO ""
#define ONCHIP_MEM_DUAL_PORT 0
#define ONCHIP_MEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_INIT_CONTENTS_FILE "nios2_onchip_mem"
#define ONCHIP_MEM_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_INSTANCE_ID "NONE"
#define ONCHIP_MEM_IRQ -1
#define ONCHIP_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEM_NAME "/dev/onchip_mem"
#define ONCHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_SINGLE_CLOCK_OP 0
#define ONCHIP_MEM_SIZE_MULTIPLE 1
#define ONCHIP_MEM_SIZE_VALUE 307200
#define ONCHIP_MEM_SPAN 307200
#define ONCHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_WRITABLE 1


/*
 * pixel_buffer configuration
 *
 */

#define ALT_MODULE_CLASS_pixel_buffer altera_up_avalon_video_pixel_buffer_dma
#define PIXEL_BUFFER_BASE 0x304890
#define PIXEL_BUFFER_IRQ -1
#define PIXEL_BUFFER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIXEL_BUFFER_NAME "/dev/pixel_buffer"
#define PIXEL_BUFFER_SPAN 16
#define PIXEL_BUFFER_TYPE "altera_up_avalon_video_pixel_buffer_dma"


/*
 * ps2 configuration
 *
 */

#define ALT_MODULE_CLASS_ps2 altera_up_avalon_ps2
#define PS2_BASE 0x3048b0
#define PS2_IRQ 4
#define PS2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PS2_NAME "/dev/ps2"
#define PS2_SPAN 8
#define PS2_TYPE "altera_up_avalon_ps2"


/*
 * sd_card_interface configuration
 *
 */

#define ALT_MODULE_CLASS_sd_card_interface Altera_UP_SD_Card_Avalon_Interface
#define SD_CARD_INTERFACE_BASE 0x304000
#define SD_CARD_INTERFACE_IRQ -1
#define SD_CARD_INTERFACE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SD_CARD_INTERFACE_NAME "/dev/sd_card_interface"
#define SD_CARD_INTERFACE_SPAN 1024
#define SD_CARD_INTERFACE_TYPE "Altera_UP_SD_Card_Avalon_Interface"


/*
 * sram configuration
 *
 */

#define ALT_MODULE_CLASS_sram altera_up_avalon_sram
#define SRAM_BASE 0x0
#define SRAM_IRQ -1
#define SRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SRAM_NAME "/dev/sram"
#define SRAM_SPAN 2097152
#define SRAM_TYPE "altera_up_avalon_sram"


/*
 * usb configuration
 *
 */

#define ALT_MODULE_CLASS_usb altera_up_avalon_usb
#define USB_BASE 0x304880
#define USB_IRQ 3
#define USB_IRQ_INTERRUPT_CONTROLLER_ID 0
#define USB_NAME "/dev/usb"
#define USB_SPAN 16
#define USB_TYPE "altera_up_avalon_usb"

#endif /* __SYSTEM_H_ */
