// {{{RME classifier 'Logical View::Alarm'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Alarm.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Alarm.h>
#include <DeviceInfo.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"AlarmPort"
	  , &AlarmProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Alarm_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Alarm_Actor( _rts, _ref );
}

const RTActorClass Alarm =
{
	(const RTActorClass *)0
  , "Alarm"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Alarm_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "disarmed"
  , "armed"
  , "triggered"
  , "testPassed"
};

#define SUPER RTActor

Alarm_Actor::Alarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, BreakAlarms( false )
{
}

Alarm_Actor::~Alarm_Actor( void )
{
}

int Alarm_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// AlarmPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &AlarmPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:armed:J58B8820B0367:triggerAlarm'
INLINE_METHODS void Alarm_Actor::transition2_triggerAlarm( const void * rtdata, AlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	log.log("Alarm activated!");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:testPassed:False'
INLINE_METHODS void Alarm_Actor::transition4_False( const void * rtdata, AlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	AlarmPort.testFail().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:triggered:J58DD5B270033:clearAlarm'
INLINE_METHODS void Alarm_Actor::transition7_clearAlarm( const void * rtdata, AlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	log.log("Alarm stopped.");
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Alarm_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Alarm_Actor::chain3_selfTest( void )
{
	// transition ':TOP:disarmed:J58B88D960291:selfTest'
	rtgChainBegin( 2, "selfTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_testPassed( msg->data, (AlarmProtocol::Conjugate *)msg->sap() ) )
		chain5_True();
	else
		chain4_False();
}

// {{{RME choicePoint ':TOP:testPassed'
INLINE_METHODS int Alarm_Actor::choicePoint1_testPassed( const void * rtdata, AlarmProtocol::Conjugate * rtport )
{
	// {{{USR
	return !BreakAlarms;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Alarm_Actor::chain5_True( void )
{
	// transition ':TOP:testPassed:True'
	rtgChainBegin( 5, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Alarm_Actor::chain4_False( void )
{
	// transition ':TOP:testPassed:False'
	rtgChainBegin( 5, "False" );
	rtgTransitionBegin();
	transition4_False( msg->data, (AlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Alarm_Actor::chain6_disarm( void )
{
	// transition ':TOP:armed:J58B88DB6006D:disarm'
	rtgChainBegin( 3, "disarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Alarm_Actor::chain2_triggerAlarm( void )
{
	// transition ':TOP:armed:J58B8820B0367:triggerAlarm'
	rtgChainBegin( 3, "triggerAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_triggerAlarm( msg->data, (AlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Alarm_Actor::chain7_clearAlarm( void )
{
	// transition ':TOP:triggered:J58DD5B270033:clearAlarm'
	rtgChainBegin( 4, "clearAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_clearAlarm( msg->data, (AlarmProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Alarm_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:disarmed'
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
				// {{{RME port 'AlarmPort'
				switch( signalIndex )
				{
				case AlarmProtocol::Conjugate::rti_arm:
					chain3_selfTest();
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
			// {{{RME state ':TOP:armed'
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
				// {{{RME port 'AlarmPort'
				switch( signalIndex )
				{
				case AlarmProtocol::Conjugate::rti_disarm:
					chain6_disarm();
					return;
				case AlarmProtocol::Conjugate::rti_activateAlarm:
					chain2_triggerAlarm();
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
			// {{{RME state ':TOP:triggered'
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
				// {{{RME port 'AlarmPort'
				switch( signalIndex )
				{
				case AlarmProtocol::Conjugate::rti_deactivateAlarm:
					chain7_clearAlarm();
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

const RTActor_class * Alarm_Actor::getActorData( void ) const
{
	return &Alarm_Actor::rtg_class;
}

const RTActor_class Alarm_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 4
  , Alarm_Actor::rtg_parent_state
  , &Alarm
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Alarm_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , Alarm_Actor::rtg_Alarm_fields
};

const RTStateId Alarm_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
};

const RTPortDescriptor Alarm_Actor::rtg_ports[] =
{
	{
		"AlarmPort"
	  , (const char *)0
	  , &AlarmProtocol::Conjugate::rt_class
	  , RTOffsetOf( Alarm_Actor, Alarm_Actor::AlarmPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Alarm_Actor, Alarm_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor Alarm_Actor::rtg_Alarm_fields[] =
{
	// {{{RME classAttribute 'BreakAlarms'
	{
		"BreakAlarms"
	  , RTOffsetOf( Alarm_Actor, BreakAlarms )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
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
