// {{{RME classifier 'Logical View::DoorTest'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DoorTest.h"
#endif

#include <RTSystem/TestComponent.h>
#include <DoorTest.h>

const RTProtocolDescriptor DoorTest::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &DoorTest::Conjugate::rt_class
  , "DoorTest"
  , 0
  , 4
  , DoorTest::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DoorTest::Base::rt_signals[] =
{
	{
		"doorClose"
	  , &RTType_void
	  , DoorTest::Base::rti_doorClose
	}
  , {
		"doorOpen"
	  , &RTType_void
	  , DoorTest::Base::rti_doorOpen
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , DoorTest::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DoorTest::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor DoorTest::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &DoorTest::Base::rt_class
  , "DoorTest"
  , 0
  , 2
  , DoorTest::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DoorTest::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , DoorTest::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DoorTest::Conjugate::rti_rtUnbound
	}
};

// }}}RME
