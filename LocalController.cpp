// {{{RME classifier 'Logical View::LocalController'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LocalController.h"
#endif

#include <RTSystem/TestComponent.h>
#include <LocalController.h>
extern const RTActorClass Alarm;
extern const RTActorClass CardReader;
extern const RTActorClass Door;
extern const RTActorClass Sensor;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"ControlPort"
	  , &Control::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"LocalTest"
	  , &Test::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_LocalController_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new LocalController_Actor( _rts, _ref );
}

const RTActorClass LocalController =
{
	(const RTActorClass *)0
  , "LocalController"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_LocalController_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "idleDisarmed"
  , "idleArmed"
  , "alarmTriggered"
  , "cardSwipe"
  , "securityAlarm"
  , "securityViolation"
  , "doorOpen"
  , "doorUnlock"
  , "waitDisarmed"
  , "waitArmed"
  , "Delay"
};

static const RTInterfaceDescriptor rtg_interfaces_doorStateR1[] =
{
	{
		"DoorPort"
	  , 1
	}
  , {
		"DoorTestPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_doorStateR1[] =
{
	{
		0
	  , &DoorProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_cardReaderR1[] =
{
	{
		"ReaderPort"
	  , 1
	}
  , {
		"TestSwipePort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_cardReaderR1[] =
{
	{
		0
	  , &CardReaderProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_sensorR1[] =
{
	{
		"SensorPort"
	  , 1
	}
  , {
		"SensorTest"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_sensorR1[] =
{
	{
		0
	  , &SensorProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_alarmR1[] =
{
	{
		"AlarmPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_alarmR1[] =
{
	{
		0
	  , &AlarmProtocol::Base::rt_class
	}
};

#define SUPER RTActor

LocalController_Actor::LocalController_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

LocalController_Actor::~LocalController_Actor( void )
{
}

int LocalController_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// ControlPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &ControlPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// LocalTest
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LocalTest;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int LocalController_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// doorStateR1
		switch( rtg_portId )
		{
		case 0:
			// DoorPort
			if( rtg_repIndex < 2 )
			{
				// DoorPort
				rtg_end.port = &DoorPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// cardReaderR1
		switch( rtg_portId )
		{
		case 0:
			// ReaderPort
			if( rtg_repIndex < 2 )
			{
				// ReaderPort
				rtg_end.port = &ReaderPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 3:
		// sensorR1
		switch( rtg_portId )
		{
		case 0:
			// SensorPort
			if( rtg_repIndex < 8 )
			{
				// SensorPort
				rtg_end.port = &SensorPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 4:
		// alarmR1
		switch( rtg_portId )
		{
		case 0:
			// AlarmPort
			if( rtg_repIndex < 2 )
			{
				// AlarmPort
				rtg_end.port = &AlarmPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	return RTActor::_followOutV( rtg_end, rtg_compId, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:idleArmed:J58B888EE011B:disarm'
INLINE_METHODS void LocalController_Actor::transition2_disarm( const void * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	AlarmPort.disarm().send();
	SensorPort.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idleDisarmed:J58B8A7CE0251:arm'
INLINE_METHODS void LocalController_Actor::transition3_arm( const void * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	AlarmPort.arm().send();
	SensorPort.arm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idleArmed:J58B8A7D30076:testFail'
INLINE_METHODS void LocalController_Actor::transition4_testFail( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	ControlPort.needRepair().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idleDisarmed:J58B8AB5501C2:cardInDisarmed'
INLINE_METHODS void LocalController_Actor::transition8_cardInDisarmed( const CardInfo * rtdata, CardReaderProtocol::Base * rtport )
{
	// {{{USR
	//send cardIn to the control center
	CardInfo cardInfo = *rtdata;
	cardInfo.DoorNumber = msg->sapIndex0();
	ControlPort.cardIn(cardInfo).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idleArmed:J58B8AB5B016B:cardInArmed'
INLINE_METHODS void LocalController_Actor::transition10_cardInArmed( const CardInfo * rtdata, CardReaderProtocol::Base * rtport )
{
	// {{{USR
	//send cardIn to the control center
	CardInfo cardInfo = *rtdata;
	cardInfo.DoorNumber = msg->sapIndex0();
	ControlPort.cardIn(cardInfo).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:alarmTriggered:J58B9B7ED03CD:alarmResolve'
INLINE_METHODS void LocalController_Actor::transition12_alarmResolve( const void * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	//turn off all alarms in the zone and disarm the zone
	AlarmPort.deactivateAlarm().send();
	SensorPort.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idleArmed:J58DD2E0F01BD:sensorTriggered'
INLINE_METHODS void LocalController_Actor::transition14_sensorTriggered( const void * rtdata, SensorProtocol::Base * rtport )
{
	// {{{USR
	//send sensorTriggered to the
	//control center

	ControlPort.sensorTriggered().send();


	//Create a timeout to go off in five seconds. 
	//Delay introduced for testing the case of disarming a zone before alarm has sounded
	RTTimespec fiveSeconds (5, 0);
	timing.informIn (fiveSeconds);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Delay:J58DD2E120063:turnOnAlarm'
INLINE_METHODS void LocalController_Actor::transition15_turnOnAlarm( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//activate all alarms in the zone
	AlarmPort.activateAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Delay:J58DD31E900F6:disarmed'
INLINE_METHODS void LocalController_Actor::transition16_disarmed( const void * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	SensorPort.disarm().send();
	AlarmPort.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:securityViolation:J58B885D90270:fiveMinutes'
INLINE_METHODS void LocalController_Actor::transition17_fiveMinutes( const void * rtdata, DoorProtocol::Base * rtport )
{
	// {{{USR
	//send doorHeld5 to the control center

	ControlPort.doorHeld5().send();
	AlarmPort.activateAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:doorOpen:J58B885D60300:oneMinute'
INLINE_METHODS void LocalController_Actor::transition18_oneMinute( const void * rtdata, DoorProtocol::Base * rtport )
{
	// {{{USR
	ControlPort.doorHeld1().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:doorUnlock:J58B8794E00F7:timerStart'
INLINE_METHODS void LocalController_Actor::transition19_timerStart( const void * rtdata, DoorProtocol::Base * rtport )
{
	// {{{USR
	SensorPort.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:waitDisarmed:J58B88577006B:cardValid'
INLINE_METHODS void LocalController_Actor::transition20_cardValid( const CardInfo * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	//send doorUnlock to a door
	CardInfo cardInfo = *rtdata;
	DoorPort.doorUnlock().sendAt(cardInfo.DoorNumber);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:securityAlarm:J58B880400383:alarmResolved'
INLINE_METHODS void LocalController_Actor::transition21_alarmResolved( const void * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	//send deactivateAlarm to the alarm

	AlarmPort.deactivateAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:securityViolation:J58B8863B03CA:doorClosed1'
INLINE_METHODS void LocalController_Actor::transition22_doorClosed1( const void * rtdata, DoorProtocol::Base * rtport )
{
	// {{{USR
	AlarmPort.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:doorOpen:J58B8B035005E:doorClosed'
INLINE_METHODS void LocalController_Actor::transition25_doorClosed( const void * rtdata, DoorProtocol::Base * rtport )
{
	// {{{USR
	AlarmPort.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:cardSwipe:waitArmed:J58B9B8830025:cardValid'
INLINE_METHODS void LocalController_Actor::transition28_cardValid( const CardInfo * rtdata, Control::Conjugate * rtport )
{
	// {{{USR
	//send doorUnlock to a door
	CardInfo cardInfo = *rtdata;
	DoorPort.doorUnlock().sendAt(cardInfo.DoorNumber);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void LocalController_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain3_arm( void )
{
	// transition ':TOP:idleDisarmed:J58B8A7CE0251:arm'
	rtgChainBegin( 2, "arm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_arm( msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void LocalController_Actor::chain8_cardInDisarmed( void )
{
	// transition ':TOP:idleDisarmed:J58B8AB5501C2:cardInDisarmed'
	rtgChainBegin( 2, "cardInDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_cardInDisarmed( (const CardInfo *)msg->data, (CardReaderProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	// transition ':TOP:cardSwipe:J58B8AB5501C7:cardInDisarmed'
	rtgChainBegin( 5, "cardInDisarmed" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 10 );
}

INLINE_CHAINS void LocalController_Actor::chain14_sensorTriggered( void )
{
	// transition ':TOP:idleArmed:J58DD2E0F01BD:sensorTriggered'
	rtgChainBegin( 3, "sensorTriggered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition14_sensorTriggered( msg->data, (SensorProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 12 );
}

INLINE_CHAINS void LocalController_Actor::chain4_testFail( void )
{
	// transition ':TOP:idleArmed:J58B8A7D30076:testFail'
	rtgChainBegin( 3, "testFail" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_testFail( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void LocalController_Actor::chain2_disarm( void )
{
	// transition ':TOP:idleArmed:J58B888EE011B:disarm'
	rtgChainBegin( 3, "disarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_disarm( msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain10_cardInArmed( void )
{
	// transition ':TOP:idleArmed:J58B8AB5B016B:cardInArmed'
	rtgChainBegin( 3, "cardInArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_cardInArmed( (const CardInfo *)msg->data, (CardReaderProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	// transition ':TOP:cardSwipe:J58B8ABD2027D:cardInArmed'
	rtgChainBegin( 5, "cardInArmed" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 11 );
}

INLINE_CHAINS void LocalController_Actor::chain12_alarmResolve( void )
{
	// transition ':TOP:alarmTriggered:J58B9B7ED03CD:alarmResolve'
	rtgChainBegin( 4, "alarmResolve" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition12_alarmResolve( msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain21_alarmResolved( void )
{
	// transition ':TOP:cardSwipe:securityAlarm:J58B880400383:alarmResolved'
	rtgChainBegin( 6, "alarmResolved" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition21_alarmResolved( msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:cardSwipe:J58B8AADE037C:alarmResolved'
	rtgChainBegin( 5, "alarmResolved" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain22_doorClosed1( void )
{
	// transition ':TOP:cardSwipe:securityViolation:J58B8863B03CA:doorClosed1'
	rtgChainBegin( 7, "doorClosed1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition22_doorClosed1( msg->data, (DoorProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:cardSwipe:J58B8AA6A02D4:doorClosed1'
	rtgChainBegin( 5, "doorClosed1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain17_fiveMinutes( void )
{
	// transition ':TOP:cardSwipe:securityViolation:J58B885D90270:fiveMinutes'
	rtgChainBegin( 7, "fiveMinutes" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition17_fiveMinutes( msg->data, (DoorProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void LocalController_Actor::chain25_doorClosed( void )
{
	// transition ':TOP:cardSwipe:doorOpen:J58B8B035005E:doorClosed'
	rtgChainBegin( 8, "doorClosed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition25_doorClosed( msg->data, (DoorProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:cardSwipe:J58B8AFEB012D:doorClosed'
	rtgChainBegin( 5, "doorClosed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain18_oneMinute( void )
{
	// transition ':TOP:cardSwipe:doorOpen:J58B885D60300:oneMinute'
	rtgChainBegin( 8, "oneMinute" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition18_oneMinute( msg->data, (DoorProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void LocalController_Actor::chain19_timerStart( void )
{
	// transition ':TOP:cardSwipe:doorUnlock:J58B8794E00F7:timerStart'
	rtgChainBegin( 9, "timerStart" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition19_timerStart( msg->data, (DoorProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 8 );
}

INLINE_CHAINS void LocalController_Actor::chain29_timeout( void )
{
	// transition ':TOP:cardSwipe:doorUnlock:J58D98936031E:timeout'
	rtgChainBegin( 9, "timeout" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	// transition ':TOP:cardSwipe:J58D988FC02F2:timeout'
	rtgChainBegin( 5, "timeout" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain20_cardValid( void )
{
	// transition ':TOP:cardSwipe:waitDisarmed:J58B88577006B:cardValid'
	rtgChainBegin( 10, "cardValid" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition20_cardValid( (const CardInfo *)msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void LocalController_Actor::chain24_invDisarmed( void )
{
	// transition ':TOP:cardSwipe:waitDisarmed:J58B8AD450074:invDisarmed'
	rtgChainBegin( 10, "invDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	// transition ':TOP:cardSwipe:J58B8AB520179:invDisarmed'
	rtgChainBegin( 5, "invDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain28_cardValid( void )
{
	// transition ':TOP:cardSwipe:waitArmed:J58B9B8830025:cardValid'
	rtgChainBegin( 11, "cardValid" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition28_cardValid( (const CardInfo *)msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void LocalController_Actor::chain26_invArmed( void )
{
	// transition ':TOP:cardSwipe:waitArmed:J58B9B84801E3:invArmed'
	rtgChainBegin( 11, "invArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	// transition ':TOP:cardSwipe:J58B8AB58016F:invArmed'
	rtgChainBegin( 5, "invArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void LocalController_Actor::chain16_disarmed( void )
{
	// transition ':TOP:Delay:J58DD31E900F6:disarmed'
	rtgChainBegin( 12, "disarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition16_disarmed( msg->data, (Control::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain15_turnOnAlarm( void )
{
	// transition ':TOP:Delay:J58DD2E120063:turnOnAlarm'
	rtgChainBegin( 12, "turnOnAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition15_turnOnAlarm( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

void LocalController_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:idleDisarmed'
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
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_armZone:
					chain3_arm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'ReaderPort'
				switch( signalIndex )
				{
				case CardReaderProtocol::Base::rti_cardIn:
					chain8_cardInDisarmed();
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
			// {{{RME state ':TOP:idleArmed'
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
			case 2:
				// {{{RME port 'SensorPort'
				switch( signalIndex )
				{
				case SensorProtocol::Base::rti_triggered:
					chain14_sensorTriggered();
					return;
				case SensorProtocol::Base::rti_testFail:
					chain4_testFail();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_disarmZone:
					chain2_disarm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'ReaderPort'
				switch( signalIndex )
				{
				case CardReaderProtocol::Base::rti_cardIn:
					chain10_cardInArmed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 5:
				// {{{RME port 'AlarmPort'
				switch( signalIndex )
				{
				case AlarmProtocol::Base::rti_testFail:
					chain4_testFail();
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
			// {{{RME state ':TOP:alarmTriggered'
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
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_resolveAlarm:
					chain12_alarmResolve();
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
			// {{{RME state ':TOP:cardSwipe'
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
			default:
				break;
			}
			break;
			// }}}RME
		case 6:
			// {{{RME state ':TOP:cardSwipe:securityAlarm'
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
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_resolveAlarm:
					chain21_alarmResolved();
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
		case 7:
			// {{{RME state ':TOP:cardSwipe:securityViolation'
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
				case DoorProtocol::Base::rti_doorClosed:
					chain22_doorClosed1();
					return;
				case DoorProtocol::Base::rti_doorHeld5:
					chain17_fiveMinutes();
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
		case 8:
			// {{{RME state ':TOP:cardSwipe:doorOpen'
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
				case DoorProtocol::Base::rti_doorClosed:
					chain25_doorClosed();
					return;
				case DoorProtocol::Base::rti_doorHeld1:
					chain18_oneMinute();
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
		case 9:
			// {{{RME state ':TOP:cardSwipe:doorUnlock'
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
				case DoorProtocol::Base::rti_doorOpen:
					chain19_timerStart();
					return;
				case DoorProtocol::Base::rti_doorClosed:
					chain29_timeout();
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
		case 10:
			// {{{RME state ':TOP:cardSwipe:waitDisarmed'
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
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_cardValid:
					chain20_cardValid();
					return;
				case Control::Conjugate::rti_cardInvalid:
					chain24_invDisarmed();
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
		case 11:
			// {{{RME state ':TOP:cardSwipe:waitArmed'
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
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_cardValid:
					chain28_cardValid();
					return;
				case Control::Conjugate::rti_cardInvalid:
					chain26_invArmed();
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
		case 12:
			// {{{RME state ':TOP:Delay'
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
				// {{{RME port 'ControlPort'
				switch( signalIndex )
				{
				case Control::Conjugate::rti_disarmZone:
					chain16_disarmed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 7:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain15_turnOnAlarm();
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

const RTActor_class * LocalController_Actor::getActorData( void ) const
{
	return &LocalController_Actor::rtg_class;
}

const RTActor_class LocalController_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 12
  , LocalController_Actor::rtg_parent_state
  , &LocalController
  , 4
  , LocalController_Actor::rtg_capsule_roles
  , 7
  , LocalController_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId LocalController_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
  , 5
  , 5
  , 5
  , 5
  , 5
  , 5
  , 1
};

const RTComponentDescriptor LocalController_Actor::rtg_capsule_roles[] =
{
	{
		"doorStateR1"
	  , &Door
	  , RTOffsetOf( LocalController_Actor, doorStateR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 2 // cardinality
	  , 2
	  , rtg_interfaces_doorStateR1
	  , 1
	  , rtg_bindings_doorStateR1
	}
  , {
		"cardReaderR1"
	  , &CardReader
	  , RTOffsetOf( LocalController_Actor, cardReaderR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 2 // cardinality
	  , 2
	  , rtg_interfaces_cardReaderR1
	  , 1
	  , rtg_bindings_cardReaderR1
	}
  , {
		"sensorR1"
	  , &Sensor
	  , RTOffsetOf( LocalController_Actor, sensorR1 )
	  , 3
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 8 // cardinality
	  , 2
	  , rtg_interfaces_sensorR1
	  , 1
	  , rtg_bindings_sensorR1
	}
  , {
		"alarmR1"
	  , &Alarm
	  , RTOffsetOf( LocalController_Actor, alarmR1 )
	  , 4
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 2 // cardinality
	  , 1
	  , rtg_interfaces_alarmR1
	  , 1
	  , rtg_bindings_alarmR1
	}
};

const RTPortDescriptor LocalController_Actor::rtg_ports[] =
{
	{
		"DoorPort"
	  , (const char *)0
	  , &DoorProtocol::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::DoorPort )
	  , 2 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"SensorPort"
	  , (const char *)0
	  , &SensorProtocol::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::SensorPort )
	  , 8 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"ControlPort"
	  , (const char *)0
	  , &Control::Conjugate::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::ControlPort )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"ReaderPort"
	  , (const char *)0
	  , &CardReaderProtocol::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::ReaderPort )
	  , 2 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"AlarmPort"
	  , (const char *)0
	  , &AlarmProtocol::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::AlarmPort )
	  , 2 // cardinality
	  , 5
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"LocalTest"
	  , (const char *)0
	  , &Test::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::LocalTest )
	  , 1 // cardinality
	  , 6
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timing"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::timing )
	  , 1 // cardinality
	  , 7
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
