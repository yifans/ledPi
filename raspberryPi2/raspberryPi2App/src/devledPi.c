#include <stdio.h>

#include "boRecord.h"
#include "devSup.h"


//#include "alarm.h"
//#include "cvtTable.h"
//#include "dbDefs.h"
//#include "dbAccess.h"
//#include "recGbl.h"
#include "recSup.h"
//#include "link.h"
#include "epicsExport.h"

#include <devledPi.h>

struct { /* binary output dset */
    long        number;
    DEVSUPFUN   dev_report;
    DEVSUPFUN   init;
    DEVSUPFUN   init_record;  /*returns:(0,2)=>(success,success no convert*/
    DEVSUPFUN   get_ioint_info;
    DEVSUPFUN   write_bo;/*returns: (-1,0)=>(failure,success)*/
} devledPi ={
    5,
    NULL,
    init_bo,
    init_record,
    NULL,
    write_bo
};
epicsExportAddress(dset, devledPi);

long init_record()
{
    printf("devledPi init record.\n");
    return 0;
}
long init_bo()
{
    if(wiringPiSetupGpio() == -1)
    {
        printf("Setup wiringPi failed!");
        return -1;
    }
    pinMode(GPIO_PIN, OUTPUT);
    printf("devledPi init bo.\n");
    return 0;
}
long write_bo(boRecord * precord) 
{
    int value = precord->rval;
    if(value == 0)
    {
        printf("value == %d\n",value);
        digitalWrite(GPIO_PIN, 0);
    }
    else
    {
        printf("value == %d\n",value);
        digitalWrite(GPIO_PIN, 1);
    }
        
    printf("devledPi write bo.\n");
    return 0;
}
