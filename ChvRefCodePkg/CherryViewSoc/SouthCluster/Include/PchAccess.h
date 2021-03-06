/** @file
  Macros that simplify accessing PCH devices's PCI registers.

  ** NOTE ** these macros assume the PCH device is on BUS 0

  Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _PCH_ACCESS_H_
#define _PCH_ACCESS_H_

#include "PchRegs.h"

#ifndef STALL_ONE_MICRO_SECOND
#define STALL_ONE_MICRO_SECOND 1
#endif
#ifndef STALL_ONE_SECOND
#define STALL_ONE_SECOND 1000000
#endif

///
/// Memory Mapped PCI Access macros
///
///
/// PCI Device MM Base
///
#ifndef MmPciAddress
#define MmPciAddress(Segment, Bus, Device, Function, Register) \
  ((UINTN) PcdGet64 (PcdPciExpressBaseAddress) + \
   (UINTN) (Bus << 20) + \
   (UINTN) (Device << 15) + \
   (UINTN) (Function << 12) + \
   (UINTN) (Register) \
  )
#endif
///
/// Pch Controller PCI access macros
///
#define PCH_RCRB_BASE ( \
  MmioRead32 (MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  PCI_FUNCTION_NUMBER_PCH_LPC), \
  R_PCH_LPC_RCBA)) & B_PCH_LPC_RCBA_BAR \
  )

///
/// Device 0x1b, Function 0
///
#define PchAzaliaPciCfg32(Register) \
  MmioRead32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register) \
  )

#define PchAzaliaPciCfg32Or(Register, OrData) \
  MmioOr32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  OrData \
  )

#define PchAzaliaPciCfg32And(Register, AndData) \
  MmioAnd32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  AndData \
  )

#define PchAzaliaPciCfg32AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  OrData \
  )

#define PchAzaliaPciCfg16(Register) \
  MmioRead16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register) \
  )

#define PchAzaliaPciCfg16Or(Register, OrData) \
  MmioOr16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  OrData \
  )

#define PchAzaliaPciCfg16And(Register, AndData) \
  MmioAnd16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  AndData \
  )

#define PchAzaliaPciCfg16AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  AndData, \
  OrData \
  )

#define PchAzaliaPciCfg8(Register)  MmioRead8 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_AZALIA, 0, Register))

#define PchAzaliaPciCfg8Or(Register, OrData) \
  MmioOr8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  OrData \
  )

#define PchAzaliaPciCfg8And(Register, AndData) \
  MmioAnd8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  AndData \
  )

#define PchAzaliaPciCfg8AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_AZALIA, \
  0, \
  Register), \
  AndData, \
  OrData \
  )

///
/// Device 0x1f, Function 0
///
#define PchLpcPciCfg32(Register)  MmioRead32 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_LPC, 0, Register))

#define PchLpcPciCfg32Or (Register, OrData) \
  MmioOr32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  OrData \
  )

#define PchLpcPciCfg32And(Register, AndData) \
  MmioAnd32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  AndData \
  )

#define PchLpcPciCfg32AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  AndData, \
  OrData \
  )

#define PchLpcPciCfg16(Register)  MmioRead16 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_LPC, 0, Register))

#define PchLpcPciCfg16Or(Register, OrData) \
  MmioOr16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  OrData \
  )

#define PchLpcPciCfg16And(Register, AndData) \
  MmioAnd16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  AndData \
  )

#define PchLpcPciCfg16AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  AndData, \
  OrData \
  )

#define PchLpcPciCfg8(Register) MmioRead8 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_LPC, 0, Register))

#define PchLpcPciCfg8Or(Register, OrData) \
  MmioOr8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  OrData \
  )

#define PchLpcPciCfg8And(Register, AndData) \
  MmioAnd8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  AndData \
  )

#define PchLpcPciCfg8AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_LPC, \
  0, \
  Register), \
  AndData, \
  OrData \
  )

#ifdef SATA_SUPPORT
///
/// SATA device 0x13, Function 0
///
#define PchSataPciCfg32(Register) MmioRead32 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_SATA, PCI_FUNCTION_NUMBER_PCH_SATA, Register))

#define PchSataPciCfg32Or(Register, OrData) \
  MmioOr32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  OrData \
  )

#define PchSataPciCfg32And(Register, AndData) \
  MmioAnd32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  AndData \
  )

#define PchSataPciCfg32AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr32 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  AndData, \
  OrData \
  )

#define PchSataPciCfg16(Register) MmioRead16 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_SATA, PCI_FUNCTION_NUMBER_PCH_SATA, Register))

#define PchSataPciCfg16Or(Register, OrData) \
  MmioOr16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  OrData \
  )

#define PchSataPciCfg16And(Register, AndData) \
  MmioAnd16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  AndData \
  )

#define PchSataPciCfg16AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr16 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  AndData, \
  OrData \
  )

#define PchSataPciCfg8(Register)  MmioRead8 (MmPciAddress (0, DEFAULT_PCI_BUS_NUMBER_PCH, PCI_DEVICE_NUMBER_PCH_SATA, PCI_FUNCTION_NUMBER_PCH_SATA, Register))

#define PchSataPciCfg8Or(Register, OrData) \
  MmioOr8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  OrData \
  )

#define PchSataPciCfg8And(Register, AndData) \
  MmioAnd8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  AndData \
  )

#define PchSataPciCfg8AndThenOr(Register, AndData, OrData) \
  MmioAndThenOr8 ( \
  MmPciAddress (0, \
  DEFAULT_PCI_BUS_NUMBER_PCH, \
  PCI_DEVICE_NUMBER_PCH_SATA, \
  PCI_FUNCTION_NUMBER_PCH_SATA, \
  Register), \
  AndData, \
  OrData \
  )

#endif

///
/// Root Complex Register Block
///
#define PchMmRcrb32(Register)                           MmioRead32 (PCH_RCRB_BASE + Register)

#define PchMmRcrb32Or(Register, OrData)                 MmioOr32 (PCH_RCRB_BASE + Register, OrData)

#define PchMmRcrb32And(Register, AndData)               MmioAnd32 (PCH_RCRB_BASE + Register, AndData)

#define PchMmRcrb32AndThenOr(Register, AndData, OrData) MmioAndThenOr32 (PCH_RCRB_BASE + Register, AndData, OrData)

#define PchMmRcrb16(Register)                           MmioRead16 (PCH_RCRB_BASE + Register)

#define PchMmRcrb16Or(Register, OrData)                 MmioOr16 (PCH_RCRB_BASE + Register, OrData)

#define PchMmRcrb16And(Register, AndData)               MmioAnd16 (PCH_RCRB_BASE + Register, AndData)

#define PchMmRcrb16AndThenOr(Register, AndData, OrData) MmioAndThenOr16 (PCH_RCRB_BASE + Register, AndData, OrData)

#define PchMmRcrb8(Register)                            MmioRead8 (PCH_RCRB_BASE + Register)

#define PchMmRcrb8Or(Register, OrData)                  MmioOr8 (PCH_RCRB_BASE + Register, OrData)

#define PchMmRcrb8And(Register, AndData)                MmioAnd8 (PCH_RCRB_BASE + Register, AndData)

#define PchMmRcrb8AndThenOr(Register, AndData, OrData)  MmioAndThenOr8 (PCH_RCRB_BASE + Register, AndData, OrData)

#endif
