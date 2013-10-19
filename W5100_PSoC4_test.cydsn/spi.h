
#define SPI_TxData(Data)		SPI_SpiUartWriteTxData(Data)
#define SPI_WaitForSend()		while( !SPI_SpiUartGetRxBufferSize() )

#define SPI_SendByte(Data)		SPI_TxData(Data);SPI_WaitForSend()
//-----------------------------------------------------------------------------
//IInChip SPI HAL
#define IINCHIP_SpiInit			SPI_Start
#define IINCHIP_SpiSendData		SPI_SendByte	
#define IINCHIP_SpiRecvData		SPI_SpiUartReadRxData

#define IINCHIP_CSInit()		//SPI_CS_Write(1)
#define IINCHIP_CSon()			SPI_CS_Write(1)
#define IINCHIP_CSoff()			SPI_CS_Write(0)
//-----------------------------------------------------------------------------
