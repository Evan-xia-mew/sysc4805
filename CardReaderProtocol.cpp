// {{{RME classifier 'Logical View::CardReaderProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CardReaderProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardReaderProtocol.h>

const RTProtocolDescriptor CardReaderProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &CardReaderProtocol::Conjugate::rt_class
  , "CardReaderProtocol"
  , 0
  , 3
  , CardReaderProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor CardReaderProtocol::Base::rt_signals[] =
{
	{
		"cardIn"
	  , &RTType_CardInfo
	  , CardReaderProtocol::Base::rti_cardIn
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , CardReaderProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , CardReaderProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor CardReaderProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &CardReaderProtocol::Base::rt_class
  , "CardReaderProtocol"
  , 0
  , 4
  , CardReaderProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor CardReaderProtocol::Conjugate::rt_signals[] =
{
	{
		"cardInvalid"
	  , &RTType_void
	  , CardReaderProtocol::Conjugate::rti_cardInvalid
	}
  , {
		"cardValid"
	  , &RTType_void
	  , CardReaderProtocol::Conjugate::rti_cardValid
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , CardReaderProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , CardReaderProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
