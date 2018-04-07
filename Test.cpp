// {{{RME classifier 'Logical View::Test'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Test.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Test.h>

const RTProtocolDescriptor Test::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Test::Conjugate::rt_class
  , "Test"
  , 0
  , 5
  , Test::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Test::Base::rt_signals[] =
{
	{
		"arm"
	  , &RTType_int
	  , Test::Base::rti_arm
	}
  , {
		"disarm"
	  , &RTType_int
	  , Test::Base::rti_disarm
	}
  , {
		"resolveAlarm"
	  , &RTType_int
	  , Test::Base::rti_resolveAlarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Test::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Test::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Test::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Test::Base::rt_class
  , "Test"
  , 0
  , 2
  , Test::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Test::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , Test::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Test::Conjugate::rti_rtUnbound
	}
};

// }}}RME
