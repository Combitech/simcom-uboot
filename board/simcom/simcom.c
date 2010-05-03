/*
 * (C) Copyright 2009
 * David Kiland, Combitech AB, david.kiland@combitech.se
 * Tobias Waldekranz, Combitech AB, tobias.waldekranz@combitech.se
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <asm/arch/pxa-regs.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <common.h>
#include <nand.h>
#include <netdev.h>

DECLARE_GLOBAL_DATA_PTR;

/* Ethernet */

int board_eth_init(bd_t *bis)
{
	return dm9000_initialize(bis);
}

/* Ethernet */

/* NAND */

#define	MASK_ALE	(1 << 21)	/* our ALE is AD21 */
#define	MASK_CLE	(1 << 20)	/* our CLE is AD22 */

static void simcom_nand_hwcontrol(struct mtd_info *mtd, int cmd,
	    unsigned int ctrl)
{
	struct nand_chip *this = mtd->priv;
	ulong IO_ADDR_W = (ulong) this->IO_ADDR_W;

	if (ctrl & NAND_CTRL_CHANGE) {
		IO_ADDR_W &= ~(MASK_ALE|MASK_CLE);
		if(ctrl & NAND_CLE)	IO_ADDR_W |= MASK_CLE;
		if(ctrl & NAND_ALE)	IO_ADDR_W |= MASK_ALE;

		this->IO_ADDR_W = (void *) IO_ADDR_W;
	}
	if (cmd != NAND_CMD_NONE)	{
		writeb(cmd, this->IO_ADDR_W);
	}
}

int board_nand_init(struct nand_chip *nand)
{
	nand->ecc.mode = NAND_ECC_SOFT;
	nand->cmd_ctrl = simcom_nand_hwcontrol;
	nand->chip_delay = 12;
	return 0;
}

/* NAND */

/* DRAM */

int dram_init (void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size  = PHYS_SDRAM_1_SIZE;
	return 0;
}

/* DRAM */

/* Board */

int board_init (void)
{
	CCCR = CONFIG_SYS_CPUSPEED;
	MSC0 = CONFIG_SYS_MSC0_VAL;
	MSC1 = CONFIG_SYS_MSC1_VAL;
	MSC2 = CONFIG_SYS_MSC2_VAL;

	gd->bd->bi_arch_number = MACH_TYPE_SIMCOM;
	gd->bd->bi_boot_params = CONFIG_SYS_DRAM_BASE + 0x100;
	return 0;
}

/* Board */
