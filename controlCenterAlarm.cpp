// {{{RME classifier 'Logical View::controlCenterAlarm'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "controlCenterAlarm.h"
#endif

#include <RTSystem/TestComponent.h>
#include <controlCenterAlarm.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"CCAlarmPort"
	  , &CCAlarmProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_controlCenterAlarm_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new controlCenterAlarm_Actor( _rts, _ref );
}

const RTActorClass controlCenterAlarm =
{
	(const RTActorClass *)0
  , "controlCenterAlarm"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_controlCenterAlarm_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "idle"
  , "active"
};

#define SUPER RTActor

controlCenterAlarm_Actor::controlCenterAlarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

controlCenterAlarm_Actor::~controlCenterAlarm_Actor( void )
{
}

int controlCenterAlarm_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// CCAlarmPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &CCAlarmPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:idle:J58B88DFB033A:activated'
INLINE_METHODS void controlCenterAlarm_Actor::transition2_activated( const void * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	log.log("Control Centre Alarm activated");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:active:J58B88DFE025A:cleared'
INLINE_METHODS void controlCenterAlarm_Actor::transition3_cleared( const void * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	log.log("Control Centre Alarm turned off");
	// }}}USR
}
// }}}RME

INLINE_CHAINS void controlCenterAlarm_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void controlCenterAlarm_Actor::chain2_activated( void )
{
	// transition ':TOP:idle:J58B88DFB033A:activated'
	rtgChainBegin( 2, "activated" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_activated( msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void controlCenterAlarm_Actor::chain3_cleared( void )
{
	// transition ':TOP:active:J58B88DFE025A:cleared'
	rtgChainBegin( 3, "cleared" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_cleared( msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void controlCenterAlarm_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'CCAlarmPort'
				switch( signalIndex )
				{
				case CCAlarmProtocol::Conjugate::rti_activateCCAlarm:
					chain2_activated();
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
			// {{{RME state ':TOP:active'
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
				// {{{RME port 'CCAlarmPort'
				switch( signalIndex )
				{
				case CCAlarmProtocol::Conjugate::rti_deactivateCCAlarm:
					chain3_cleared();
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

const RTActor_class * controlCenterAlarm_Actor::getActorData( void ) const
{
	return &controlCenterAlarm_Actor::rtg_class;
}

const RTActor_class controlCenterAlarm_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , controlCenterAlarm_Actor::rtg_parent_state
  , &controlCenterAlarm
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , controlCenterAlarm_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId controlCenterAlarm_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor controlCenterAlarm_Actor::rtg_ports[] =
{
	{
		"CCAlarmPort"
	  , (const char *)0
	  , &CCAlarmProtocol::Conjugate::rt_class
	  , RTOffsetOf( controlCenterAlarm_Actor, controlCenterAlarm_Actor::CCAlarmPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( controlCenterAlarm_Actor, controlCenterAlarm_Actor::log )
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
