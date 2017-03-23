#include <stdio.h>

#include "drvSup.h"
#include <epicsExport.h>


#include "drvledPi.h"


struct {
    long number;
    DRVSUPFUN report;
    DRVSUPFUN init;
} drvledPi = {
    2,
    pi_report,
    pi_init
};

epicsExportAddress(drvet, drvledPi);

long pi_report(){
    printf("---> pi_report in drvledPi <----\n");
}

long pi_init(){
    printf("----> pi_init in drvledPi <----\n");
}

