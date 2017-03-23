TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
#DBD += ledPi.dbd

LIBRARY_IOC += ledPi
ledPi_LIBS += $(EPICS_BASE_IOC_LIBS)
wiringPi_DIR += /usr/lib
ledPi_LIBS += wiringPi
ledPi_SRCS += devledPi.c 
ledPi_SRCS += drvledPi.c 
#=============================
# Build the IOC application

PROD_IOC = raspberryPi2
# raspberryPi2.dbd will be created and installed
DBD += raspberryPi2.dbd

# raspberryPi2.dbd will be made up from these files:
raspberryPi2_DBD += base.dbd

# Include dbd files from all support applications:
#raspberryPi2_DBD += xxx.dbd
raspberryPi2_DBD += ledPi.dbd

# Add all the support libraries needed by this IOC
#raspberryPi2_LIBS += xxx
raspberryPi2_LIBS += ledPi 

# raspberryPi2_registerRecordDeviceDriver.cpp derives from raspberryPi2.dbd
raspberryPi2_SRCS += raspberryPi2_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
raspberryPi2_SRCS_DEFAULT += raspberryPi2Main.cpp
raspberryPi2_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#raspberryPi2_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
raspberryPi2_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

