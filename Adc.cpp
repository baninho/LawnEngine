#include "Adc.h"

unsigned char pressureVoltageReading, lambdaVoltageReading, angleVoltageReading = 0u;


Adc::Adc()
{
}


Adc::~Adc()
{
}

int Adc::readLambda()
{
	lambdaVoltageReading = 0u;

	return 0;
}

int Adc::readPressure()
{
	pressureVoltageReading = 0u;

	return 0;
}

int Adc::readAngle()
{
	angleVoltageReading = 0u;

	return 0;
}


/*
* PI CODE BELOW



// ***********************************************************************
// compile as follows:
// gcc -o pcf8591 pcf8591.c -lrt
// ***********************************************************************

// ***********************************************************************
// int dev_open( struct pgm_opt_t *pgm_ctl, int bus_no, int slave_address, int force_slave)
// where pgm_ctl is a pointer to program run options
//       bus_no is 1 per default for Raspberry Pi Model B
//       slave_address is 0x48 per default
//       force means a flag to grab the device even it is under
//         control of the kernel
//
// opens a communication channel to an I2C device
//
// returns handle to device or a negative value
//
// ***********************************************************************


int Adc::dev_open(int bus_no, int slave_address, int force_slave)
{
	int dev_fd;
	char filename[40];

	sprintf(filename, "/dev/i2c-%d", bus_no);
	dev_fd = open(filename, O_RDWR);
#ifdef DEBUG
	fprintf(stderr, "open: fd=%d, errno=%d\n", dev_fd, errno);
	perror("open");
#endif // DEBUG 

	if (dev_fd > 0)
	{
		if (ioctl(dev_fd, force_slave ? I2C_SLAVE_FORCE : I2C_SLAVE,
			slave_address) < 0)
		{
#ifdef DEBUG
			fprintf(stderr, "ioctl: errno=%d\n", errno);
			perror("ioctl");
#endif // DEBUG 
			close(dev_fd);
			dev_fd = -1;
		}
	}

	return(dev_fd);
}

// ***********************************************************************
// void dev_close(int dev_fd)
// where dev_fd is a handle to an I2C device
//
// closes the communication channel
//
// returns nothing
//
// ***********************************************************************
void dev_close(int dev_fd)
{
	if (dev_fd >= 0)
	{
		close(dev_fd);
	}
}


// ***********************************************************************
// static unsigned short pcf8591_read_value(int client, unsigned char reg)
// where client is a handle returned by dev_open()
//       reg is the register to read 
// 
// read content of a specific register of an I2C device
//
// ***********************************************************************
static unsigned short pcf8591_read_value(int client, unsigned char reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}
// ***********************************************************************
// static int pcf8591_write_value(int client, unsigned char reg, 
//                               unsigned int value)
// where client is a handle returned by dev_open()
//       reg is the register to write 
//       value is the value to write to the register
// 
// ***********************************************************************
static int pcf8591_write_value(int client, unsigned char reg, unsigned short value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}


//
// main loop
// open device read registers
// print results
// 

#define BUS_NO			1
#define PCF8591_SLAVE_ADDR	0x48
#define REG_CTL			0x40
#define REG_DAC_LED		0x40
#define REG_ADC_LIGHT		0x42
#define REG_ADC_TEMP		0x41
#define REG_ADC_POT		0x43
#define REG_ADC_NC		0x44
#define FORCE			0

main(int argc, char **argv)
{
	int fail;
	int dev_fd;
	int i;
	unsigned short res;
	unsigned short pot, temp, light, nc;
	unsigned char aValue;


	if ((dev_fd = dev_open(BUS_NO, PCF8591_SLAVE_ADDR, FORCE)) >= 0)
	{
		aValue = 0;

		pcf8591_write_value(dev_fd, REG_CTL, 0x43); // ctl byte

		for (aValue = 0; aValue != 250; aValue += 10)
		{
			printf("\n");
			for (i = 0; i <= 3; i++)
			{
				res = pcf8591_read_value(dev_fd, 0x40 + i);
				switch (i)
				{
				case 0:
					printf("reg %02x [%5.5s] = %02x [=%d]\n",
						0x40 + i, "light", res, res);
					break;
				case 1:
					printf("reg %02x [%5.5s] = %02x [=%d]\n",
						0x40 + i, "nc", res, res);
					break;
				case 2:
					printf("reg %02x [%5.5s] = %02x [=%d]\n",
						0x40 + i, "poti", res, res);
					break;
				case 3:
					printf("reg %02x [%5.5s] = %02x [=%d]\n",
						0x40 + i, "temp", res, res);
					break;
				}
			}

			pcf8591_write_value(dev_fd, REG_DAC_LED, aValue);
			printf("analog ......: = %02x [=%d]\n", aValue, aValue);
			sleep(1);
		}

		pcf8591_write_value(dev_fd, REG_DAC_LED, 0);


		dev_close(dev_fd);
		fail = 0;

	}
	else
	{
		perror("open dev");
		fail = 1;
	}

	return(fail);
}





*/