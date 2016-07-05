/*
* AD-Converter I2C Interface
*/

/*
***********************************************************************
*
*  pcf8591.h - handle a PCF8591-module
*             	an ADC/DAC with I2C-Bus interface
*
*  Copyright (C) 2013 Dreamshader (Dirk Schanz)
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*
*
***********************************************************************
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
// #include <getopt.h>
#include <math.h>
#include <sys/types.h>
// #include <linux/i2c-dev.h> 

extern unsigned char pressureVoltageReading, lambdaVoltageReading, angleVoltageReading;

class Adc
{
public:
	Adc();
	~Adc();

	int readLambda();
	int readPressure();
	int readAngle();

	/* 
	*PI functions

	int dev_open(int bus_no, int slave_address, int force_slave);
	void dev_close(int dev_fd);
	static unsigned short pcf8591_read_value(int client, unsigned char reg); 
	static int pcf8591_write_value(int client, unsigned char reg, unsigned short value);
	

	*/
};