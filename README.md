MES Week 5 Assignment

This project ports https://github.com/eleciawhite/reusable.git into an STM32 project using a Virtual COM Port for i/o. 

The command handler found at USB_DEVICE/App/usbd_cdc_if.c was edited to do nothing. (CDC_Receive_FS())
Instead, ConsoleIOReceive() calls USBD_CDC_ReceivePacket() to fill the console read buffer. 
Commands were added to the CLI interface to aid in debugging. 
