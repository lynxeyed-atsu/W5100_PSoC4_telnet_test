// telnet loop back

extern "C" {
  #include "types.h"
  #include <project.h>
}
#include "Ethernet.h"

// Network Settigs
uint8 mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xA0, 0x8A };
uint8 ip[] = { 169, 254, 22, 31 };

// use port 23:Telnet
Server server = Server(23);

void setup()
{
	// Caution! UART in this Sample is not Arduino compatible layout(See Topesign.cysch) : RX=P4.0, TX= P4.1 
	UART_1_Start();
	UART_1_UartPutString("CY8CKIT-042 W5100 Test");

	// initialize W5100
	Ethernet.begin(mac, ip);
	
	// listen
	server.begin();
	
}

void loop()
{
  Client client = server.available();
  if (client) {
  	uint8 cc = client.read();
  	server.write( cc );
  }
}


int main(void)
{
	setup();
    SPI_CS_Write(1);
	
	for (;;)
		loop();
        
	return 0;
}
