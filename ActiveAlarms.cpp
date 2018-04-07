// {{{RME classifier 'Logical View::ActiveAlarms'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ActiveAlarms.h"
#endif

#include <RTSystem/TestComponent.h>
#include <ActiveAlarms.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"ActiveAlarmsPort"
	  , &CCAlarmProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ActiveAlarms_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ActiveAlarms_Actor( _rts, _ref );
}

const RTActorClass ActiveAlarms =
{
	(const RTActorClass *)0
  , "ActiveAlarms"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ActiveAlarms_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "noActiveAlarms"
  , "activeAlarms"
  , "CP1"
};

#define SUPER RTActor

ActiveAlarms_Actor::ActiveAlarms_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, ActiveList( 0 )
{
}

ActiveAlarms_Actor::~ActiveAlarms_Actor( void )
{
}

int ActiveAlarms_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// ActiveAlarmsPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &ActiveAlarmsPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:noActiveAlarms:J58B8951E006B:addEvent'
INLINE_METHODS void ActiveAlarms_Actor::transition2_addEvent( const void * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	ActiveList++;

	ActiveAlarmsPort.activateCCAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:activeAlarms:J58DD4852022D:addEvent'
INLINE_METHODS void ActiveAlarms_Actor::transition3_addEvent( const void * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	ActiveList++;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:activeAlarms:J58DD48130151:eventCleared'
INLINE_METHODS void ActiveAlarms_Actor::transition4_eventCleared( const int * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	int clearOne = *rtdata;
	if (clearOne)
		ActiveList--;
	else
		ActiveList = 0;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP1:True'
INLINE_METHODS void ActiveAlarms_Actor::transition5_True( const int * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	ActiveAlarmsPort.deactivateCCAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:activeAlarms:J58DD5E590044:viewActiveAlarms'
INLINE_METHODS void ActiveAlarms_Actor::transition7_viewActiveAlarms( const void * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	log.log("Number of active security alarms:");
	log.log(ActiveList);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ActiveAlarms_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ActiveAlarms_Actor::chain2_addEvent( void )
{
	// transition ':TOP:noActiveAlarms:J58B8951E006B:addEvent'
	rtgChainBegin( 2, "addEvent" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_addEvent( msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ActiveAlarms_Actor::chain7_viewActiveAlarms( void )
{
	// transition ':TOP:activeAlarms:J58DD5E590044:viewActiveAlarms'
	rtgChainBegin( 3, "viewActiveAlarms" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_viewActiveAlarms( msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ActiveAlarms_Actor::chain3_addEvent( void )
{
	// transition ':TOP:activeAlarms:J58DD4852022D:addEvent'
	rtgChainBegin( 3, "addEvent" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_addEvent( msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ActiveAlarms_Actor::chain4_eventCleared( void )
{
	// transition ':TOP:activeAlarms:J58DD48130151:eventCleared'
	rtgChainBegin( 3, "eventCleared" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_eventCleared( (const int *)msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint1_CP1( (const int *)msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() ) )
		chain5_True();
	else
		chain6_False();
}

// {{{RME choicePoint ':TOP:CP1'
INLINE_METHODS int ActiveAlarms_Actor::choicePoint1_CP1( const int * rtdata, CCAlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	return ActiveList==0;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ActiveAlarms_Actor::chain5_True( void )
{
	// transition ':TOP:CP1:True'
	rtgChainBegin( 4, "True" );
	rtgTransitionBegin();
	transition5_True( (const int *)msg->data, (CCAlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ActiveAlarms_Actor::chain6_False( void )
{
	// transition ':TOP:CP1:False'
	rtgChainBegin( 4, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

void ActiveAlarms_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:noActiveAlarms'
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
				// {{{RME port 'ActiveAlarmsPort'
				switch( signalIndex )
				{
				case CCAlarmProtocol::Conjugate::rti_addAlarm:
					chain2_addEvent();
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
			// {{{RME state ':TOP:activeAlarms'
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
				// {{{RME port 'ActiveAlarmsPort'
				switch( signalIndex )
				{
				case CCAlarmProtocol::Conjugate::rti_viewAlarms:
					chain7_viewActiveAlarms();
					return;
				case CCAlarmProtocol::Conjugate::rti_addAlarm:
					chain3_addEvent();
					return;
				case CCAlarmProtocol::Conjugate::rti_resolveAlarm:
					chain4_eventCleared();
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

const RTActor_class * ActiveAlarms_Actor::getActorData( void ) const
{
	return &ActiveAlarms_Actor::rtg_class;
}

const RTActor_class ActiveAlarms_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , ActiveAlarms_Actor::rtg_parent_state
  , &ActiveAlarms
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , ActiveAlarms_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , ActiveAlarms_Actor::rtg_ActiveAlarms_fields
};

const RTStateId ActiveAlarms_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor ActiveAlarms_Actor::rtg_ports[] =
{
	{
		"ActiveAlarmsPort"
	  , (const char *)0
	  , &CCAlarmProtocol::Conjugate::rt_class
	  , RTOffsetOf( ActiveAlarms_Actor, ActiveAlarms_Actor::ActiveAlarmsPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( ActiveAlarms_Actor, ActiveAlarms_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor ActiveAlarms_Actor::rtg_ActiveAlarms_fields[] =
{
	// {{{RME classAttribute 'ActiveList'
	{
		"ActiveList"
	  , RTOffsetOf( ActiveAlarms_Actor, ActiveList )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
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
