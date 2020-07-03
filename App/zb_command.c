#include "zb_command.h"
#include <string.h>
#include "../Mid/ncp/ncp.h"
#include "../Mid/common/xor.h"

#include "../Mid/fingerprint/fingerprint.h"

static void ZB_SendFirstTime(u8 type,u8 *buff, u8 len);
static void ZB_SendFirstTime1(u8 type,u8 *buff, u8 len);
static void ZB_SendFirstTime2(u8 type,u8 *buff, u8 len);

static void ZB_DeviceAnnounce(u8 type,u8 *buff, u8 len);

static void ZB_JoinNetworkResult(u8 type,u8 *buff, u8 len);
static void ZB_ToggleNetwork(u8 type,u8 *buff, u8 len);
static void ZB_GetNetworkInfo(u8 type,u8 *buff, u8 len);

static void ZB_ChangeLockState(u8 type,u8 *buff, u8 len);
static void ZB_FingerPrint(u8 type,u8 *buff, u8 len);
static void ZB_SetLock(u8 type,u8 *buff, u8 len);
static void ZB_GetLock(u8 type,u8 *buff, u8 len);

static void ZB_GetBatterry(u8 type,u8 *buff, u8 len);
static void ZB_ChangeLanguage(u8 type,u8 *buff, u8 len);
static void ZB_UpdateLanguage(u8 type,u8 *buff, u8 len);

static void ZB_SetFingerPrint(u8 type,u8 *buff, u8 len);
static void ZB_ClearFingerPrint(u8 type,u8 *buff, u8 len);
static void ZB_UpdateFingerPrint(u8 type,u8 *buff, u8 len);

static void ZB_GetPinCode(u8 type,u8 *buff, u8 len);
static void ZB_SetPinCode(u8 type,u8 *buff, u8 len);
static void ZB_ClearPinCode(u8 type,u8 *buff, u8 len);
static void ZB_UpdatePinCode(u8 type,u8 *buff, u8 len);
static void ZB_GetAllPinCode(u8 type,u8 *buff, u8 len);
static void ZB_ChangeMasterCode(u8 type,u8 *buff, u8 len);

static void ZB_UserTestFinger(u8 type,u8 *buff, u8 len);

static u8 zb_sequenceNumber=0;

static const ZB_CommandInfo_t zbListCommand[]=
{
    {SEND_FIRST_TIME        ,ZB_SendFirstTime},
    {SEND_FIRST_TIME_1      ,ZB_SendFirstTime1},
    {SEND_FIRST_TIME_2      ,ZB_SendFirstTime2},
    {JOIN_NETWORK_RESULT_CMD,ZB_JoinNetworkResult},
    {TOGGLE_NETWORK_CMD     ,ZB_ToggleNetwork},
    {GET_NETWORK_INFO_CMD   ,ZB_GetNetworkInfo},
    {CHANGE_LOCK_STATE_CMD  ,ZB_ChangeLockState},
    {FINGER_PRINT_LOCK_CMD  ,ZB_FingerPrint},
    {DEVICE_ANNOUNCE        ,ZB_DeviceAnnounce},
    {SET_LOCK_CMD           ,ZB_SetLock},
    {GET_LOCK_CMD           ,ZB_GetLock},
    {GET_BATTERY_CMD        ,ZB_GetBatterry},
    {CHANGE_LANGUAGE_CMD    ,ZB_ChangeLanguage},
    {UPDATE_LANGUAGE_CMD    ,ZB_UpdateLanguage},
    {SET_FINGERPRINT_CMD    ,ZB_SetFingerPrint},
    {UPDATE_FINGERPRINT_CMD ,ZB_UpdateFingerPrint},
    {CLEAR_FINGERPRINT_CMD  ,ZB_ClearFingerPrint},
    {GET_PIN_CODE_CMD       ,ZB_GetPinCode},
    {SET_PIN_CODE_CMD       ,ZB_SetPinCode},
    {UPDATE_PIN_CODE_CMD    ,ZB_UpdatePinCode},
    {CLEAR_PIN_CODE_CMD     ,ZB_ClearPinCode},
    {CHANGE_MASTER_CODE_CMD ,ZB_ChangeMasterCode},
    {USE_TEST_FINGER_PRINT  ,ZB_UserTestFinger}
};

void ZB_CheckCommandExitsAndExecute(u8 command, u8 type,u8* buff, u8 len)
{
    for(int i=0;i<sizeof(zbListCommand)/sizeof(ZB_CommandInfo_t);i++)
    {
        if(command==zbListCommand[i].cmdId)
        {
            if(zbListCommand[i].cmdHandle!=NULL)
            {
                zbListCommand[i].cmdHandle(type,buff,len);
            }
        }
    }
}

void ZB_CommandRespond(u8 command, u8 type,u8* buff, u8 len)
{
    u8 sendBuff[NCP_COMMAND_HEADER_SIZE+NCP_COMMAND_MAX_LENGH+1];

    sendBuff[0]=command;
    sendBuff[1]=type;
    sendBuff[2]=zb_sequenceNumber++;
    sendBuff[3]=len;

    memcpy(&sendBuff[4],buff,len);
    sendBuff[len+4]=XOR_Caculator(sendBuff,0,len+4);

    NCP_Send(sendBuff,len+5);
}
                        
static void ZB_JoinNetworkResult(u8 type,u8 *buff, u8 len)
{

  
}

static void ZB_ToggleNetwork(u8 type,u8 *buff, u8 len)
{
 
}

static void ZB_GetNetworkInfo(u8 type,u8 *buff, u8 len)
{
  
}

static void ZB_ChangeLockState(u8 type,u8 *buff, u8 len)
{

}

static void ZB_FingerPrint(u8 type,u8 *buff, u8 len)
{

}

static void ZB_SetLock(u8 type,u8 *buff, u8 len)
{

}

static void ZB_GetLock(u8 type,u8 *buff, u8 len)
{

}

static void ZB_GetBatterry(u8 type,u8 *buff, u8 len)
{

}
static void ZB_ChangeLanguage(u8 type,u8 *buff, u8 len)
{

}
static void ZB_UpdateLanguage(u8 type,u8 *buff, u8 len)
{

}

static void ZB_SetFingerPrint(u8 type,u8 *buff, u8 len)
{

}

static void ZB_ClearFingerPrint(u8 type,u8 *buff, u8 len)
{

}
static void ZB_UpdateFingerPrint(u8 type,u8 *buff, u8 len)
{

}

static void ZB_GetPinCode(u8 type,u8 *buff, u8 len)
{

}

static void ZB_SetPinCode(u8 type,u8 *buff, u8 len)
{
    
}

static void ZB_ClearPinCode(u8 type,u8 *buff, u8 len)
{

}
static void ZB_UpdatePinCode(u8 type,u8 *buff, u8 len)
{

}
static void ZB_GetAllPinCode(u8 type,u8 *buff, u8 len)
{

}
static void ZB_ChangeMasterCode(u8 type,u8 *buff, u8 len)
{
}
  
static void ZB_SendFirstTime(u8 type,u8 *buff, u8 len)
{

}
static void ZB_SendFirstTime1(u8 type,u8 *buff, u8 len)
{

}
static void ZB_SendFirstTime2(u8 type,u8 *buff, u8 len)
{

}

static void ZB_DeviceAnnounce(u8 type,u8 *buff, u8 len)
{

}

static void ZB_UserTestFinger(u8 type,u8 *buff, u8 len)
{
    u16 userID=0;

    switch (type)
    {
        case 0x00:
            NCP_Send("Start HandShake\n",17);
            FingerPrint_HandShakeCmd();
            break; 
        case 0x01:
            NCP_Send("Start Enroll\n",14);
            userID=(u16)(buff[0]<<8)+(u16)buff[1];
            FingerPrint_EnrollFingercmd(userID);
            break;
        case 0x02:
            NCP_Send("Start Search\n",14);
            FingerPrint_Search();
            break;
    default:
        break;
    }
}