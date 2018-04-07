// {{{RME classifier 'Logical View::SensorTest'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SensorTest.h"
#endif

#include <RTSystem/TestComponent.h>
#include <SensorTest.h>

const RTProtocolDescriptor SensorTest::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &SensorTest::Conjugate::rt_class
  , "SensorTest"
  , 0
  , 3
  , SensorTest::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor SensorTest::Base::rt_signals[] =
{
	{
		"TriggerSensor"
	  , &RTType_void
	  , SensorTest::Base::rti_TriggerSensor
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , SensorTest::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , SensorTest::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor SensorTest::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &SensorTest::Base::rt_class
  , "SensorTest"
  , 0
  , 2
  , SensorTest::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor SensorTest::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , SensorTest::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , SensorTest::Conjugate::rti_rtUnbound
	}
};

// }}}RME
