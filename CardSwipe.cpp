// {{{RME classifier 'Logical View::CardSwipe'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CardSwipe.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardSwipe.h>

const RTProtocolDescriptor CardSwipe::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &CardSwipe::Conjugate::rt_class
  , "CardSwipe"
  , 0
  , 3
  , CardSwipe::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor CardSwipe::Base::rt_signals[] =
{
	{
		"cardSwipe"
	  , &RTType_CardInfo
	  , CardSwipe::Base::rti_cardSwipe
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , CardSwipe::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , CardSwipe::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor CardSwipe::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &CardSwipe::Base::rt_class
  , "CardSwipe"
  , 0
  , 2
  , CardSwipe::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor CardSwipe::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , CardSwipe::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , CardSwipe::Conjugate::rti_rtUnbound
	}
};

// }}}RME
