#include "fingerprint_app.h"
#include "ncp.h"
#include "stdio.h"
#include "../Mid/fingerprint/fingerprint.h"


void FingerPrint_AppHandle(u8 event, u8* par, u8 par_len)
{
    u8 errCode=ERROR_SUCCESS;

    errCode=par[0];

    switch (event)
    {
        case FINGERPRINT_HANDSHAKE_END:        
            if(errCode==ERROR_SUCCESS)
            {
                NCP_Send("HandShake_OK\n",14);
            }else
            {
                NCP_Send("HandShake_ER\n",14);
            }       
            break;
        case FINGERPRINT_ENROLL_END:
            if(errCode==ERROR_SUCCESS)
            {
                NCP_Send("ENROLL_OK\n",11);
            }else
            {
                NCP_Send("ENROLL_ER\n",11);
            }
            break;
        case FINGERPRINT_SEARCH_END:
            if(errCode==ERROR_SUCCESS)
            {   
                char buff[15];
                u16 userID=0;

                userID=(u16)(par[1]<<8)+ (u16)par[2];
                snprintf(buff,15,"SEARCH_ID %d\n",userID);
                NCP_Send(buff,15);
                
            }else
            {
                NCP_Send("SEARCH_ER\n",11);
            }
            break;
        default:
            break;
    }
}






