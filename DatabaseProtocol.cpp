// {{{RME classifier 'Logical View::DatabaseProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DatabaseProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <DatabaseProtocol.h>

const RTProtocolDescriptor DatabaseProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &DatabaseProtocol::Conjugate::rt_class
  , "DatabaseProtocol"
  , 0
  , 6
  , DatabaseProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DatabaseProtocol::Base::rt_signals[] =
{
	{
		"cardIn"
	  , &RTType_CardInfo
	  , DatabaseProtocol::Base::rti_cardIn
	}
  , {
		"event"
	  , &RTType_int
	  , DatabaseProtocol::Base::rti_event
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , DatabaseProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DatabaseProtocol::Base::rti_rtUnbound
	}
  , {
		"viewEvents"
	  , &RTType_void
	  , DatabaseProtocol::Base::rti_viewEvents
	}
  , {
		"zone"
	  , &RTType_void
	  , DatabaseProtocol::Base::rti_zone
	}
};

const RTProtocolDescriptor DatabaseProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &DatabaseProtocol::Base::rt_class
  , "DatabaseProtocol"
  , 0
  , 4
  , DatabaseProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DatabaseProtocol::Conjugate::rt_signals[] =
{
	{
		"invalidCard"
	  , &RTType_CardInfo
	  , DatabaseProtocol::Conjugate::rti_invalidCard
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , DatabaseProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DatabaseProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"validCard"
	  , &RTType_CardInfo
	  , DatabaseProtocol::Conjugate::rti_validCard
	}
};

// }}}RME
