// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include "consoleIo.h"
#include "usbd_cdc_if.h"
#include "usbd_cdc.h"
#include <stdio.h>

extern USBD_HandleTypeDef hUsbDeviceFS;

eConsoleError ConsoleIoInit(void)
{
	return CONSOLE_SUCCESS;
}
eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	//uint32_t i = 0;
	
	if (USBD_CDC_ReceivePacket(&hUsbDeviceFS) == USBD_OK)
	{
		CDC_Transmit_FS(buffer, (strlen(buffer)));
	}

	*readLength = (strlen(buffer));

	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoSendString(const char *buffer)
{
	CDC_Transmit_FS(buffer, (strlen(buffer)));
	return CONSOLE_SUCCESS;
}

