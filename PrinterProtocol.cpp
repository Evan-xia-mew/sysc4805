// {{{RME classifier 'Logical View::PrinterProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PrinterProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <PrinterProtocol.h>

const RTProtocolDescriptor PrinterProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PrinterProtocol::Conjugate::rt_class
  , "PrinterProtocol"
  , 0
  , 3
  , PrinterProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PrinterProtocol::Base::rt_signals[] =
{
	{
		"printEvent"
	  , &RTType_int
	  , PrinterProtocol::Base::rti_printEvent
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PrinterProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PrinterProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor PrinterProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PrinterProtocol::Base::rt_class
  , "PrinterProtocol"
  , 0
  , 3
  , PrinterProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PrinterProtocol::Conjugate::rt_signals[] =
{
	{
		"printEvent"
	  , &RTType_int
	  , PrinterProtocol::Conjugate::rti_printEvent
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PrinterProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PrinterProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
