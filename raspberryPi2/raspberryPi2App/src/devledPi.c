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

long init_record();
long init_bo();
long write_bo();

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
    printf("devledPi init bo.\n");
    return 0;
}
long write_bo() 
{
    printf("devledPi write bo.\n");
    return 0;
}
