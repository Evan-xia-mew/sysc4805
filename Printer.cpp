// {{{RME classifier 'Logical View::Printer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Printer.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Printer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"PrinterPort"
	  , &PrinterProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Printer_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Printer_Actor( _rts, _ref );
}

const RTActorClass Printer =
{
	(const RTActorClass *)0
  , "Printer"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Printer_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "idle"
};

#define SUPER RTActor

Printer_Actor::Printer_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Printer_Actor::~Printer_Actor( void )
{
}

int Printer_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// PrinterPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &PrinterPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:idle:J58B892CB01D0:printEvent'
INLINE_METHODS void Printer_Actor::transition1_printEvent( const int * rtdata, PrinterProtocol::Conjugate * rtport )
{
	// {{{USR
	int eventType = *rtdata;

	switch(eventType)
	{
		case(1):
		log.log("Security violation detected: door held open 1 minute.");
		break;
		case(2):
		log.log("Security alarm detected.");
		break;
		case(3):
		log.log("Security violation detected: Entry with invalid card attempted.");
		break;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Printer_Actor::chain2_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Printer_Actor::chain1_printEvent( void )
{
	// transition ':TOP:idle:J58B892CB01D0:printEvent'
	rtgChainBegin( 2, "printEvent" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_printEvent( (const int *)msg->data, (PrinterProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Printer_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
		switch( stateIndex )
		{
		case 1:
			// {{{RME state ':TOP'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					chain2_Initial();
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:idle'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'PrinterPort'
				switch( signalIndex )
				{
				case PrinterProtocol::Conjugate::rti_printEvent:
					chain1_printEvent();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * Printer_Actor::getActorData( void ) const
{
	return &Printer_Actor::rtg_class;
}

const RTActor_class Printer_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Printer_Actor::rtg_parent_state
  , &Printer
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Printer_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId Printer_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor Printer_Actor::rtg_ports[] =
{
	{
		"PrinterPort"
	  , (const char *)0
	  , &PrinterProtocol::Conjugate::rt_class
	  , RTOffsetOf( Printer_Actor, Printer_Actor::PrinterPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Printer_Actor, Printer_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
