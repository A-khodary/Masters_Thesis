
RTIMULIBPATH	= ../RTIMULib
RTIMULIBPATH2	= RTIMULib
CXX           	= g++
LIBS			= libs
INCLUDE_PATH	= -Ilibs/ -IRTIMULib/ -I. -I$(RTIMULIBPATH)
DEL_FILE      	= rm -rf
LIB_INCLUDE 	= -lbcm2835 -lwiringPi -lpthread -L/usr/lib/arm-linux-gnueabihf
CFLAGS 			= -c
C_FLAGS 		= -pipe -O2 -Wall -W
CHK_DIR_EXISTS	= test -d
MKDIR         	= mkdir -p
INCPATH			= -I. -I$(RTIMULIBPATH)

# Files

DEPS          = $(RTIMULIBPATH)/RTMath.h \
				$(RTIMULIBPATH)/RTIMULib.h \
				$(RTIMULIBPATH)/RTIMULibDefs.h \
				$(RTIMULIBPATH)/RTIMUHal.h \
				$(RTIMULIBPATH)/RTIMU.h \
				$(RTIMULIBPATH)/RTIMUNull.h \
				$(RTIMULIBPATH)/RTIMUMPU9150.h \
				$(RTIMULIBPATH)/RTIMUGD20HM303D.h \
				$(RTIMULIBPATH)/RTIMUGD20M303DLHC.h \
				$(RTIMULIBPATH)/RTIMULSM9DS0.h \
				$(RTIMULIBPATH)/RTFusion.h \
				$(RTIMULIBPATH)/RTFusionKalman4.h \
				$(RTIMULIBPATH)/RTFusionRTQF.h \
				$(RTIMULIBPATH)/RTIMUSettings.h \

DEPS2          = $(RTIMULIBPATH2)/RTMath.h \
				$(RTIMULIBPATH2)/RTIMULib.h \
				$(RTIMULIBPATH2)/RTIMULibDefs.h \
				$(RTIMULIBPATH2)/RTIMUHal.h \
				$(RTIMULIBPATH2)/RTIMU.h \
				$(RTIMULIBPATH2)/RTIMUNull.h \
				$(RTIMULIBPATH2)/RTIMUMPU9150.h \
				$(RTIMULIBPATH2)/RTIMUGD20HM303D.h \
				$(RTIMULIBPATH2)/RTIMUGD20M303DLHC.h \
				$(RTIMULIBPATH2)/RTIMULSM9DS0.h \
				$(RTIMULIBPATH2)/RTFusion.h \
				$(RTIMULIBPATH2)/RTFusionKalman4.h \
				$(RTIMULIBPATH2)/RTFusionRTQF.h \
				$(RTIMULIBPATH2)/RTIMUSettings.h \

run: libraries
	$(CXX) main/AccelerometerTransmitter.cpp $(wildcard libraries/*) $(DEPS2) $(INCLUDE_PATH) -o run $(LIB_INCLUDE)

libraries:
	@$(CHK_DIR_EXISTS) libraries/ || $(MKDIR) libraries/
	@$(CHK_DIR_EXISTS) data/ || $(MKDIR) data/
	for dir in $(LIBS); do \
		cd $$dir; \
		$(CXX) $(CFLAGS) *.cpp $(DEPS) -I../ $(LIB_INCLUDE); \
		$(CXX) $(CFLAGS) $(RTIMULIBPATH)/*.cpp $(DEPS) -I../ $(LIB_INCLUDE); \
		mv *.o ../libraries; \
		cd -; \
	done
	
clean:
	-$(DEL_FILE) libraries/ run



