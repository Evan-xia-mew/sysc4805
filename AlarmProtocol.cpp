// {{{RME classifier 'Logical View::AlarmProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "AlarmProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <AlarmProtocol.h>

const RTProtocolDescriptor AlarmProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &AlarmProtocol::Conjugate::rt_class
  , "AlarmProtocol"
  , 0
  , 4
  , AlarmProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor AlarmProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , AlarmProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , AlarmProtocol::Base::rti_rtUnbound
	}
  , {
		"testFail"
	  , &RTType_void
	  , AlarmProtocol::Base::rti_testFail
	}
  , {
		"testPass"
	  , &RTType_void
	  , AlarmProtocol::Base::rti_testPass
	}
};

const RTProtocolDescriptor AlarmProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &AlarmProtocol::Base::rt_class
  , "AlarmProtocol"
  , 0
  , 6
  , AlarmProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor AlarmProtocol::Conjugate::rt_signals[] =
{
	{
		"activateAlarm"
	  , &RTType_void
	  , AlarmProtocol::Conjugate::rti_activateAlarm
	}
  , {
		"arm"
	  , &RTType_void
	  , AlarmProtocol::Conjugate::rti_arm
	}
  , {
		"deactivateAlarm"
	  , &RTType_void
	  , AlarmProtocol::Conjugate::rti_deactivateAlarm
	}
  , {
		"disarm"
	  , &RTType_void
	  , AlarmProtocol::Conjugate::rti_disarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , AlarmProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , AlarmProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
