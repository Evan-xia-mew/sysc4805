// {{{RME classifier 'Logical View::SensorProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SensorProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <SensorProtocol.h>

const RTProtocolDescriptor SensorProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &SensorProtocol::Conjugate::rt_class
  , "SensorProtocol"
  , 0
  , 5
  , SensorProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor SensorProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , SensorProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , SensorProtocol::Base::rti_rtUnbound
	}
  , {
		"testFail"
	  , &RTType_void
	  , SensorProtocol::Base::rti_testFail
	}
  , {
		"testPass"
	  , &RTType_void
	  , SensorProtocol::Base::rti_testPass
	}
  , {
		"triggered"
	  , &RTType_void
	  , SensorProtocol::Base::rti_triggered
	}
};

const RTProtocolDescriptor SensorProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &SensorProtocol::Base::rt_class
  , "SensorProtocol"
  , 0
  , 4
  , SensorProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor SensorProtocol::Conjugate::rt_signals[] =
{
	{
		"arm"
	  , &RTType_void
	  , SensorProtocol::Conjugate::rti_arm
	}
  , {
		"disarm"
	  , &RTType_void
	  , SensorProtocol::Conjugate::rti_disarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , SensorProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , SensorProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
