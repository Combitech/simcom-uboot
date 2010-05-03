/*
 * (C) Copyright 2009
 * David Kiland, Combitech AB, <david.kiland@combitech.se>
 * Tobias Waldekranz, Combitech AB, <tobias.waldekranz@combitech.se>
 *
 * Configuration settings for the Simcom module.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/sizes.h>


/*
 * CPU
 */
#define CONFIG_PXA27X
#define CONFIG_SKIP_LOWLEVEL_INIT	/* 1st stage loader does this */
#define CONFIG_SYS_HZ				1000
#define CONFIG_SYS_CPUSPEED			0x00000290
#define CONFIG_SYS_MSC0_VAL			0x349c3bc8
#define CONFIG_SYS_MSC1_VAL			0x7ff05894
#define CONFIG_SYS_MSC2_VAL			0x7ff07ff0

/*
 * DRAM
 */
#define PHYS_SDRAM_1				0xa0000000
#define PHYS_SDRAM_1_SIZE			SZ_64M
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_DRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_DRAM_SIZE		PHYS_SDRAM_1_SIZE


/*
 * NOR
 */
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_FLASH_BASE				0x00000000
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_PROTECTION
#define CONFIG_SYS_FLASH_BASE			CONFIG_FLASH_BASE
#define CONFIG_SYS_FLASH_CFI_WIDTH		FLASH_CFI_16BIT
#define CONFIG_SYS_MAX_FLASH_BANKS		1
#define CONFIG_SYS_MAX_FLASH_SECT		(8 + 63)


/*
 * NAND
 */
#define CONFIG_JFFS2_NAND
#define CONFIG_JFFS2_CMDLINE
#define CONFIG_SYS_NAND_BASE 			0x04000000
#define CONFIG_SYS_MAX_NAND_DEVICE		1


/*
 * UART
 */
#define CONFIG_PXA_SERIAL
#define CONFIG_FFUART
#define CONFIG_BAUDRATE				38400
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }


/*
 * Ethernet
 */
#define CONFIG_NET_MULTI
#define CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_BASE	0x08000000
#define DM9000_IO			(CONFIG_DM9000_BASE)
#define DM9000_DATA			(CONFIG_DM9000_BASE + 0x4)


/*
 * Nor Flash Layout / Environment
 */
#define CONFIG_SYS_MONITOR_BASE		(CONFIG_FLASH_BASE + 0x00050000)
#define CONFIG_SYS_MONITOR_LEN		0x00030000
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_ADDR			(CONFIG_SYS_MONITOR_BASE + \
								CONFIG_SYS_MONITOR_LEN)
#define CONFIG_ENV_SIZE			SZ_4K
#define CONFIG_ENV_SECT_SIZE	SZ_64K
#define CONFIG_ENV_ADDR_REDUND	(CONFIG_ENV_ADDR+CONFIG_ENV_SECT_SIZE)
#define CONFIG_ENV_SIZE_REDUND	(CONFIG_ENV_SIZE)


/*
 * Environment Variables
 */
#define CONFIG_BOOTDELAY	1
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.0.21
#define CONFIG_SERVERIP		192.168.0.200
#define CONFIG_BOOTARGS				\
	"console=ttySA0,38400 "							\
	"root=/dev/mtdblock0 rootfstype=jffs2 "			\
	"ip=off quiet lpj=2596864 cpufreq_pxa2xx.pxa27x_maxfreq=520 "
#define CONFIG_BOOTCOMMAND			\
	"cp.w 0x100000 0xa0007fc0 0x100000; bootm 0xa0007fc0"
#define CONFIG_EXTRA_ENV_SETTINGS	\
	"unlock=yes\0"


/*
 * Commands
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_DHCP
#define CONFIG_CMD_JFFS2
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING


/*
 * Commandline
 */
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_PROMPT			"simcom# "
#define CONFIG_SYS_PROMPT_HUSH_PS2	"simcom> "
#define CONFIG_SYS_DEVICE_NULLDEV
#define CONFIG_SYS_CBSIZE			0x100
#define CONFIG_SYS_PBSIZE			(CONFIG_SYS_CBSIZE + \
									sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS			16
#define CONFIG_SYS_BARGSIZE			CONFIG_SYS_CBSIZE


/*
 * Miscellaneous
 */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_STACKSIZE			SZ_128K
#define CONFIG_SYS_MALLOC_LEN	    (CONFIG_ENV_SIZE + SZ_128K)
#define CONFIG_SYS_GBL_DATA_SIZE	128
#define CONFIG_SYS_MEMTEST_START	0xa0000000
#define CONFIG_SYS_MEMTEST_END		0xa0FFFFFF
#define CONFIG_SYS_LOAD_ADDR		0xa0000000

#endif	/* __CONFIG_H */
