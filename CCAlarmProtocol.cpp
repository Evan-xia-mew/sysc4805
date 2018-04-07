// {{{RME classifier 'Logical View::CCAlarmProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CCAlarmProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CCAlarmProtocol.h>

const RTProtocolDescriptor CCAlarmProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &CCAlarmProtocol::Conjugate::rt_class
  , "CCAlarmProtocol"
  , 0
  , 5
  , CCAlarmProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor CCAlarmProtocol::Base::rt_signals[] =
{
	{
		"activateCCAlarm"
	  , &RTType_void
	  , CCAlarmProtocol::Base::rti_activateCCAlarm
	}
  , {
		"addAlarm"
	  , &RTType_void
	  , CCAlarmProtocol::Base::rti_addAlarm
	}
  , {
		"deactivateCCAlarm"
	  , &RTType_void
	  , CCAlarmProtocol::Base::rti_deactivateCCAlarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , CCAlarmProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , CCAlarmProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor CCAlarmProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &CCAlarmProtocol::Base::rt_class
  , "CCAlarmProtocol"
  , 0
  , 7
  , CCAlarmProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor CCAlarmProtocol::Conjugate::rt_signals[] =
{
	{
		"activateCCAlarm"
	  , &RTType_void
	  , CCAlarmProtocol::Conjugate::rti_activateCCAlarm
	}
  , {
		"addAlarm"
	  , &RTType_void
	  , CCAlarmProtocol::Conjugate::rti_addAlarm
	}
  , {
		"deactivateCCAlarm"
	  , &RTType_void
	  , CCAlarmProtocol::Conjugate::rti_deactivateCCAlarm
	}
  , {
		"resolveAlarm"
	  , &RTType_int
	  , CCAlarmProtocol::Conjugate::rti_resolveAlarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , CCAlarmProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , CCAlarmProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"viewAlarms"
	  , &RTType_void
	  , CCAlarmProtocol::Conjugate::rti_viewAlarms
	}
};

// }}}RME
