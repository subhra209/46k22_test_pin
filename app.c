
/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/
#include "config.h"
#include "board.h"
#include "timer.h"
#include "communication.h"
#include "app.h"
#include "string.h"
#include "eep.h"


typedef struct _PIN
{
UINT8 pinNo;
UINT8 pinStatus;
UINT8 pinFlag;
}PIN;


typedef struct _APP
{
	PIN pins[MAX_SIZE];
	UINT8 pinindex; 
}APP;

#pragma idata APPDATA
APP app ={0};
#pragma idata



UINT8 APP_comCallBack( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket);



void APP_init(void)
{



COM_init(CMD_SOP , CMD_EOP ,RESP_SOP , RESP_EOP , APP_comCallBack);



}

void APP_task(void)
{
	UINT8 i;
	UINT8 temp = 0;

	for(i =0; i< MAX_SIZE ; i++)
	{
		if(app.pins[i].pinFlag == 1)
		{
			app.pins[i].pinFlag = 0;
			temp = app.pins[i].pinNo;
			switch(temp)
			{

					case 0x02:PIN_2 = app.pins[i].pinStatus;
					break;
					case 0x03:PIN_3 = app.pins[i].pinStatus;
					break;
					case 0x04:PIN_4 = app.pins[i].pinStatus;
					break;
					case 0x05:PIN_5 = app.pins[i].pinStatus;
					break;
					case 0x06:PIN_6 = app.pins[i].pinStatus;
					break;
					case 0x07:PIN_7 = app.pins[i].pinStatus;
					break;
					case 0x09:PIN_9 = app.pins[i].pinStatus;
					break;
					case 0x0A:PIN_10 = app.pins[i].pinStatus;
					break;
					case 0x0F:PIN_15 = app.pins[i].pinStatus;
					break;
					case 0x10:PIN_16 = app.pins[i].pinStatus;
					break;
					case 0x11:PIN_17 = app.pins[i].pinStatus;
					break;
					case 0x12:PIN_18 = app.pins[i].pinStatus;
					break;
					case 0x13:PIN_19 = app.pins[i].pinStatus;
					break;
					case 0x14:PIN_20 = app.pins[i].pinStatus;
					break;
					case 0x15:PIN_21 = app.pins[i].pinStatus;
					break;
					case 0x16:PIN_22 = app.pins[i].pinStatus;
					break;
					case 0x17:PIN_23 = app.pins[i].pinStatus;
					break;
					case 0x18:PIN_24 = app.pins[i].pinStatus;
					break;
					case 0x1B:PIN_27 = app.pins[i].pinStatus;
					break;
					case 0x1C:PIN_28 = app.pins[i].pinStatus;
					break;
					case 0x1D:PIN_29 = app.pins[i].pinStatus;
					break;
					case 0x1E:PIN_30 = app.pins[i].pinStatus;
					break;
					case 0x21:PIN_33 = app.pins[i].pinStatus;
					break;
					case 0x22:PIN_34 = app.pins[i].pinStatus;
					break;
					case 0x23:PIN_35 = app.pins[i].pinStatus;
					break;
					case 0x24:PIN_36 = app.pins[i].pinStatus;
					break;
					case 0x25:PIN_37 = app.pins[i].pinStatus;
					break;
					case 0x26:PIN_38 = app.pins[i].pinStatus;
					break;
					case 0x27:PIN_39 = app.pins[i].pinStatus;
					break;
					case 0x28:PIN_40 = app.pins[i].pinStatus;
					break;
					
					default:
					break;	
			}
		}
	}
}

UINT8 APP_comCallBack( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket)
{

	UINT8 i;

	UINT8 rxCode = rxPacket[0];
	UINT8 data = rxPacket[1];
	UINT8 length = 0;
	*txCode = rxCode;

	app.pins[app.pinindex].pinNo = rxCode;
	app.pins[app.pinindex].pinStatus = data;
	app.pins[app.pinindex].pinFlag = TRUE;
	app.pinindex++;
	
	if(app.pinindex >= MAX_SIZE)
	{
		app.pinindex = 0;
	}



}

	