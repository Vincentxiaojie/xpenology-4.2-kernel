
/* 
 *  System memory mapping 
 */

/* SDRAM: actual mapping is auto detected */
#define SDRAM_CS0_BASE  0x00000000
#define SDRAM_CS0_SIZE  _256M

#define SDRAM_CS1_BASE  0x10000000
#define SDRAM_CS1_SIZE  _256M

#define SDRAM_CS2_BASE  0x20000000
#define SDRAM_CS2_SIZE  _256M

#define SDRAM_CS3_BASE  0x30000000
#define SDRAM_CS3_SIZE  _256M

/* PEX */
#define PEX0_MEM_BASE 0xe0000000
#define PEX0_MEM_SIZE _128M

#define PEX0_IO_BASE 0xf2000000
#define PEX0_IO_SIZE _1M


/* PCI0: IO and memory space */
#define PCI0_MEM_BASE  0xe8000000
#define PCI0_MEM_SIZE  _128M

#define PCI0_IO_BASE    0xf2100000
#define PCI0_IO_SIZE    _1M

/* Device: CS0 - SRAM, CS1 - RTC, CS2 - UART, CS3 - large flash */
#define DEVICE_CS0_BASE 0xfa000000
#define DEVICE_CS0_SIZE _2M

#define DEVICE_CS1_BASE 0xfb000000
#define DEVICE_CS1_SIZE _16M

#define DEVICE_CS2_BASE 0xfa800000
#define DEVICE_CS2_SIZE _1M

#define BOOTDEV_CS_BASE	0xF4000000
/* BOOTDEV_CS_SIZE per board */
#define BOOTDEV_CS_SIZE_RD_88W8860_DDR1		_16M
#define BOOTDEV_CS_SIZE_RD_88W8860_AP82S 	_8M
#define BOOTDEV_CS_SIZE_DB_88W8860       	_512K



#if defined (CONFIG_MV_INCLUDE_PCI) && defined (CONFIG_MV_INCLUDE_PEX)

#define PCI_IF0_MEM0_BASE 	PEX0_MEM_BASE
#define PCI_IF0_MEM0_SIZE 	PEX0_MEM_SIZE
#define PCI_IF0_IO_BASE 	PEX0_IO_BASE
#define PCI_IF0_IO_SIZE 	PEX0_IO_SIZE

#define PCI_IF1_MEM0_BASE 	PCI0_MEM_BASE
#define PCI_IF1_MEM0_SIZE 	PCI0_MEM_SIZE
#define PCI_IF1_IO_BASE 	PCI0_IO_BASE
#define PCI_IF1_IO_SIZE 	PCI0_IO_SIZE

#elif defined (CONFIG_MV_INCLUDE_PCI)

#define PCI_IF0_MEM0_BASE 	PCI0_MEM_BASE
#define PCI_IF0_MEM0_SIZE 	PCI0_MEM_SIZE
#define PCI_IF0_IO_BASE 	PCI0_IO_BASE
#define PCI_IF0_IO_SIZE 	PCI0_IO_SIZE

#elif defined (CONFIG_MV_INCLUDE_PEX)

#define PCI_IF0_MEM0_BASE 	PEX0_MEM_BASE
#define PCI_IF0_MEM0_SIZE 	PEX0_MEM_SIZE
#define PCI_IF0_IO_BASE 	PEX0_IO_BASE
#define PCI_IF0_IO_SIZE 	PEX0_IO_SIZE

#endif

struct map_desc MEM_TABLE[] = 	{	
  { PCI_IF0_MEM0_BASE,   __phys_to_pfn(PCI_IF0_MEM0_BASE),   PCI_IF0_MEM0_SIZE,  MT_DEVICE },
  { PCI_IF1_MEM0_BASE,   __phys_to_pfn(PCI_IF1_MEM0_BASE),   PCI_IF1_MEM0_SIZE,  MT_DEVICE },
  { INTER_REGS_BASE, __phys_to_pfn(INTER_REGS_BASE), SZ_1M,  	     MT_DEVICE },
  { PCI_IF0_IO_BASE,   __phys_to_pfn(PCI_IF0_IO_BASE),   PCI_IF0_IO_SIZE,  MT_DEVICE },
  { PCI_IF1_IO_BASE,   __phys_to_pfn(PCI_IF1_IO_BASE),   PCI_IF1_IO_SIZE,  MT_DEVICE },	
  { DEVICE_CS1_BASE, __phys_to_pfn(DEVICE_CS1_BASE), DEVICE_CS1_SIZE, MT_DEVICE},				
  { DEVICE_CS0_BASE, __phys_to_pfn(DEVICE_CS0_BASE), DEVICE_CS0_SIZE, MT_DEVICE},
  { DEVICE_CS2_BASE, __phys_to_pfn(DEVICE_CS2_BASE), DEVICE_CS2_SIZE, MT_DEVICE}
};


MV_CPU_DEC_WIN SYSMAP_RD_88W8860_DDR1[] = {
   	/* base low        base high    size       	WinNum     enable */
	{{SDRAM_CS0_BASE ,    0, SDRAM_CS0_SIZE } ,			0xFFFFFFFF,DIS},
	{{SDRAM_CS1_BASE ,    0, SDRAM_CS1_SIZE } ,			0xFFFFFFFF,DIS},
	{{PEX0_MEM_BASE  ,    0, PEX0_MEM_SIZE  } ,			0x2       ,EN},
	{{PEX0_IO_BASE   ,    0, PEX0_IO_SIZE   } ,			0x0       ,EN},
	{{PCI0_MEM_BASE  ,    0, PCI0_MEM_SIZE  } ,			0x3       ,EN},
	{{PCI0_IO_BASE   ,    0, PCI0_IO_SIZE   } ,			0x1       ,EN},
	{{INTER_REGS_BASE,    0, INTER_REGS_SIZE} ,			0x8       ,EN},
	{{DEVICE_CS0_BASE,    0, DEVICE_CS0_SIZE} ,			0x5	  ,DIS},
	{{DEVICE_CS1_BASE,    0, DEVICE_CS1_SIZE} ,			0x6	  ,DIS},
	{{DEVICE_CS2_BASE,    0, DEVICE_CS2_SIZE} ,			0x7	  ,DIS},
	{{BOOTDEV_CS_BASE,    0, BOOTDEV_CS_SIZE_RD_88W8860_DDR1} ,	0x4       ,EN},
	{{TBL_TERM,TBL_TERM, TBL_TERM} ,TBL_TERM  ,TBL_TERM}		
};

MV_CPU_DEC_WIN SYSMAP_RD_88W8660_AP82S_DDR1[] = {
  	 /* base low        base high    size       	WinNum     enable */
	{{SDRAM_CS0_BASE ,    0, SDRAM_CS0_SIZE },			0xFFFFFFFF,DIS},
	{{SDRAM_CS1_BASE ,    0, SDRAM_CS1_SIZE },			0xFFFFFFFF,DIS},
	{{PEX0_MEM_BASE  ,    0, PEX0_MEM_SIZE  },			0x2       ,EN},
	{{PEX0_IO_BASE   ,    0, PEX0_IO_SIZE   },			0x0       ,EN},
	{{PCI0_MEM_BASE  ,    0, PCI0_MEM_SIZE  },			0x3       ,EN},
	{{PCI0_IO_BASE   ,    0, PCI0_IO_SIZE   },			0x1       ,EN},
	{{INTER_REGS_BASE,    0, INTER_REGS_SIZE},			0x8       ,EN},
	{{DEVICE_CS0_BASE,    0, DEVICE_CS0_SIZE},			0x5	  ,DIS},
	{{DEVICE_CS1_BASE,    0, DEVICE_CS1_SIZE},			0x6	  ,DIS},
	{{DEVICE_CS2_BASE,    0, DEVICE_CS2_SIZE},			0x7	  ,DIS},
	{{BOOTDEV_CS_BASE,    0, BOOTDEV_CS_SIZE_RD_88W8860_AP82S},	0x4       ,EN},
	{{TBL_TERM,TBL_TERM, TBL_TERM} ,TBL_TERM  ,TBL_TERM}		
};

MV_CPU_DEC_WIN SYSMAP_DB_88W8660_DDR2[] = {
   	/* base low        base high    size       	WinNum     enable */
	{{SDRAM_CS0_BASE ,    0, SDRAM_CS0_SIZE },			0xFFFFFFFF,DIS},
	{{SDRAM_CS1_BASE ,    0, SDRAM_CS1_SIZE },			0xFFFFFFFF,DIS},
	{{PEX0_MEM_BASE  ,    0, PEX0_MEM_SIZE  },			0x2       ,EN},
	{{PEX0_IO_BASE   ,    0, PEX0_IO_SIZE   },			0x0       ,EN},
	{{PCI0_MEM_BASE  ,    0, PCI0_MEM_SIZE  },			0x3       ,EN},
	{{PCI0_IO_BASE   ,    0, PCI0_IO_SIZE   },			0x1       ,EN},
	{{INTER_REGS_BASE,    0, INTER_REGS_SIZE},			0x8       ,EN},
	{{DEVICE_CS0_BASE,    0, DEVICE_CS0_SIZE},			0x5	  ,EN},
	{{DEVICE_CS1_BASE,    0, DEVICE_CS1_SIZE},			0x6	  ,EN},
	{{DEVICE_CS2_BASE,    0, DEVICE_CS2_SIZE},			0x7	  ,DIS},
	{{BOOTDEV_CS_BASE,    0, BOOTDEV_CS_SIZE_DB_88W8860},		0x4       ,EN},
	{{TBL_TERM,TBL_TERM, TBL_TERM} ,TBL_TERM  ,TBL_TERM}		
};


