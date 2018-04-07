// {{{RME classifier 'Logical View::Control'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Control.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Control.h>

const RTProtocolDescriptor Control::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Control::Conjugate::rt_class
  , "Control"
  , 0
  , 7
  , Control::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Control::Base::rt_signals[] =
{
	{
		"cardIn"
	  , &RTType_CardInfo
	  , Control::Base::rti_cardIn
	}
  , {
		"doorHeld1"
	  , &RTType_void
	  , Control::Base::rti_doorHeld1
	}
  , {
		"doorHeld5"
	  , &RTType_void
	  , Control::Base::rti_doorHeld5
	}
  , {
		"needRepair"
	  , &RTType_void
	  , Control::Base::rti_needRepair
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Control::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Control::Base::rti_rtUnbound
	}
  , {
		"sensorTriggered"
	  , &RTType_void
	  , Control::Base::rti_sensorTriggered
	}
};

const RTProtocolDescriptor Control::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Control::Base::rt_class
  , "Control"
  , 0
  , 7
  , Control::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Control::Conjugate::rt_signals[] =
{
	{
		"armZone"
	  , &RTType_void
	  , Control::Conjugate::rti_armZone
	}
  , {
		"cardInvalid"
	  , &RTType_CardInfo
	  , Control::Conjugate::rti_cardInvalid
	}
  , {
		"cardValid"
	  , &RTType_CardInfo
	  , Control::Conjugate::rti_cardValid
	}
  , {
		"disarmZone"
	  , &RTType_void
	  , Control::Conjugate::rti_disarmZone
	}
  , {
		"resolveAlarm"
	  , &RTType_void
	  , Control::Conjugate::rti_resolveAlarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Control::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Control::Conjugate::rti_rtUnbound
	}
};

// }}}RME
