RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = "C:/Documents and Settings/student/Desktop/system/system.rtmdl"
COMPONENT = "Component View::TestComponent"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/TestComponent.dep>
CODESYNC_TARGETS = $(TestComponent_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(TestComponent_SYSTARGET_CS) : $(TestComponent_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

