// {{{RME classifier 'Logical View::Door'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Door.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Door.h>
#include <DeviceInfo.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"DoorPort"
	  , &DoorProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"DoorTestPort"
	  , &DoorTest::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Door_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Door_Actor( _rts, _ref );
}

const RTActorClass Door =
{
	(const RTActorClass *)0
  , "Door"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Door_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "doorLocked"
  , "doorUnlocked"
  , "doorOpen"
  , "doorHeld"
};

#define SUPER RTActor

Door_Actor::Door_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Door_Actor::~Door_Actor( void )
{
}

int Door_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// DoorPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &DoorPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// DoorTestPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &DoorTestPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:doorLocked:J58B88C4101A6:unlock'
INLINE_METHODS void Door_Actor::transition2_unlock( const void * rtdata, DoorProtocol::Conjugate * rtport )
{
	// {{{USR
	log.log("Door unlocked");

	RTTimespec thirtySeconds (10, 0);
	DoorTimer = timer.informIn(thirtySeconds);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:doorUnlocked:J58B88C470239:timeout'
INLINE_METHODS void Door_Actor::transition3_timeout( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	log.log("Door locked due to timeout");
	DoorPort.doorClosed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:doorUnlocked:J58B9B9F7025C:open'
INLINE_METHODS void Door_Actor::transition4_open( const void * rtdata, DoorTest::Base * rtport )
{
	// {{{USR
	timer.cancelTimer(DoorTimer);

	RTTimespec oneMinute (10, 0);
	DoorTimer = timer.informIn(oneMinute);

	DoorPort.doorOpen().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:doorOpen:J58B9B9FE0202:close'
INLINE_METHODS void Door_Actor::transition5_close( const void * rtdata, DoorTest::Base * rtport )
{
	// {{{USR
	timer.cancelTimer(DoorTimer);

	DoorPort.doorClosed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:doorOpen:J58D9860D00C2:doorHeld1min'
INLINE_METHODS void Door_Actor::transition6_doorHeld1min( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	RTTimespec fourMinutes (10, 0);
	DoorTimer = timer.informIn(fourMinutes);

	DoorPort.doorHeld1().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:doorHeld:J58D9865302AC:doorHeld5min'
INLINE_METHODS void Door_Actor::transition7_doorHeld5min( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	DoorPort.doorHeld5().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:doorHeld:J58D98688021D:close'
INLINE_METHODS void Door_Actor::transition8_close( const void * rtdata, DoorTest::Base * rtport )
{
	// {{{USR
	timer.cancelTimer(DoorTimer);

	DoorPort.doorClosed().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Door_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Door_Actor::chain2_unlock( void )
{
	// transition ':TOP:doorLocked:J58B88C4101A6:unlock'
	rtgChainBegin( 2, "unlock" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_unlock( msg->data, (DoorProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Door_Actor::chain3_timeout( void )
{
	// transition ':TOP:doorUnlocked:J58B88C470239:timeout'
	rtgChainBegin( 3, "timeout" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_timeout( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Door_Actor::chain4_open( void )
{
	// transition ':TOP:doorUnlocked:J58B9B9F7025C:open'
	rtgChainBegin( 3, "open" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_open( msg->data, (DoorTest::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Door_Actor::chain6_doorHeld1min( void )
{
	// transition ':TOP:doorOpen:J58D9860D00C2:doorHeld1min'
	rtgChainBegin( 4, "doorHeld1min" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_doorHeld1min( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Door_Actor::chain5_close( void )
{
	// transition ':TOP:doorOpen:J58B9B9FE0202:close'
	rtgChainBegin( 4, "close" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_close( msg->data, (DoorTest::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Door_Actor::chain7_doorHeld5min( void )
{
	// transition ':TOP:doorHeld:J58D9865302AC:doorHeld5min'
	rtgChainBegin( 5, "doorHeld5min" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_doorHeld5min( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Door_Actor::chain8_close( void )
{
	// transition ':TOP:doorHeld:J58D98688021D:close'
	rtgChainBegin( 5, "close" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_close( msg->data, (DoorTest::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Door_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain1_Initial();
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
			// {{{RME state ':TOP:doorLocked'
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
				// {{{RME port 'DoorPort'
				switch( signalIndex )
				{
				case DoorProtocol::Conjugate::rti_doorUnlock:
					chain2_unlock();
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
		case 3:
			// {{{RME state ':TOP:doorUnlocked'
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
			case 3:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain3_timeout();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'DoorTestPort'
				switch( signalIndex )
				{
				case DoorTest::Base::rti_doorOpen:
					chain4_open();
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
		case 4:
			// {{{RME state ':TOP:doorOpen'
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
			case 3:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain6_doorHeld1min();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'DoorTestPort'
				switch( signalIndex )
				{
				case DoorTest::Base::rti_doorClose:
					chain5_close();
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
		case 5:
			// {{{RME state ':TOP:doorHeld'
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
			case 3:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain7_doorHeld5min();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'DoorTestPort'
				switch( signalIndex )
				{
				case DoorTest::Base::rti_doorClose:
					chain8_close();
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

const RTActor_class * Door_Actor::getActorData( void ) const
{
	return &Door_Actor::rtg_class;
}

const RTActor_class Door_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 5
  , Door_Actor::rtg_parent_state
  , &Door
  , 0
  , (const RTComponentDescriptor *)0
  , 4
  , Door_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , Door_Actor::rtg_Door_fields
};

const RTStateId Door_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
};

const RTPortDescriptor Door_Actor::rtg_ports[] =
{
	{
		"DoorPort"
	  , (const char *)0
	  , &DoorProtocol::Conjugate::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::DoorPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::timer )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"DoorTestPort"
	  , (const char *)0
	  , &DoorTest::Base::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::DoorTestPort )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor Door_Actor::rtg_Door_fields[] =
{
	// {{{RME classAttribute 'DoorTimer'
	{
		"DoorTimer"
	  , RTOffsetOf( Door_Actor, DoorTimer )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
