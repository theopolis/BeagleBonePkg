/** @file

  Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __AM335X_H__
#define __AM335X_H__

#include "Am335xGpio.h"
#include "Am335xInterrupt.h"
#include "Am335xPrcm.h"
#include "Am335xTimer.h"
#include "Am335xUart.h"
#include "Am335xUsb.h"
#include "Am335xMMCHS.h"
#include "Am335xI2c.h"
#include "Am335xPadConfiguration.h"
#include "Am335xGpmc.h"
#include "Am335xDma.h"


//CONTROL_PBIAS_LITE
#define CONTROL_PBIAS_LITE    0x48002520
#define PBIASLITEVMODE0       BIT0
#define PBIASLITEPWRDNZ0      BIT1
#define PBIASSPEEDCTRL0       BIT2
#define PBIASLITEVMODE1       BIT8
#define PBIASLITEWRDNZ1       BIT9

#endif // __AM335X_H__

