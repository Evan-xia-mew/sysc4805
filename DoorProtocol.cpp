// {{{RME classifier 'Logical View::DoorProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DoorProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <DoorProtocol.h>

const RTProtocolDescriptor DoorProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &DoorProtocol::Conjugate::rt_class
  , "DoorProtocol"
  , 0
  , 6
  , DoorProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DoorProtocol::Base::rt_signals[] =
{
	{
		"doorClosed"
	  , &RTType_void
	  , DoorProtocol::Base::rti_doorClosed
	}
  , {
		"doorHeld1"
	  , &RTType_void
	  , DoorProtocol::Base::rti_doorHeld1
	}
  , {
		"doorHeld5"
	  , &RTType_void
	  , DoorProtocol::Base::rti_doorHeld5
	}
  , {
		"doorOpen"
	  , &RTType_void
	  , DoorProtocol::Base::rti_doorOpen
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , DoorProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DoorProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor DoorProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &DoorProtocol::Base::rt_class
  , "DoorProtocol"
  , 0
  , 4
  , DoorProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DoorProtocol::Conjugate::rt_signals[] =
{
	{
		"doorClosed"
	  , &RTType_void
	  , DoorProtocol::Conjugate::rti_doorClosed
	}
  , {
		"doorUnlock"
	  , &RTType_void
	  , DoorProtocol::Conjugate::rti_doorUnlock
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , DoorProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DoorProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
