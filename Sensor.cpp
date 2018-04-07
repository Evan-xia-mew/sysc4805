// {{{RME classifier 'Logical View::Sensor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Sensor.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Sensor.h>
#include <DeviceInfo.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"SensorPort"
	  , &SensorProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"SensorTest"
	  , &SensorTest::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Sensor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Sensor_Actor( _rts, _ref );
}

const RTActorClass Sensor =
{
	(const RTActorClass *)0
  , "Sensor"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Sensor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "disarmed"
  , "armed"
  , "testPassed"
};

#define SUPER RTActor

Sensor_Actor::Sensor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, BreakSensors( false )
{
}

Sensor_Actor::~Sensor_Actor( void )
{
}

int Sensor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// SensorPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &SensorPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// SensorTest
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &SensorTest;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:testPassed:False'
INLINE_METHODS void Sensor_Actor::transition3_False( const void * rtdata, SensorProtocol::Conjugate * rtport )
{
	// {{{USR
	SensorPort.testFail().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:armed:J58B88D610111:tripped'
INLINE_METHODS void Sensor_Actor::transition6_tripped( const void * rtdata, SensorTest::Base * rtport )
{
	// {{{USR
	SensorPort.triggered().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Sensor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Sensor_Actor::chain2_selfTest( void )
{
	// transition ':TOP:disarmed:J58B88D27038E:selfTest'
	rtgChainBegin( 2, "selfTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_testPassed( msg->data, (SensorProtocol::Conjugate *)msg->sap() ) )
		chain4_True();
	else
		chain3_False();
}

// {{{RME choicePoint ':TOP:testPassed'
INLINE_METHODS int Sensor_Actor::choicePoint1_testPassed( const void * rtdata, SensorProtocol::Conjugate * rtport )
{
	// {{{USR
	return !BreakSensors;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Sensor_Actor::chain4_True( void )
{
	// transition ':TOP:testPassed:True'
	rtgChainBegin( 4, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Sensor_Actor::chain3_False( void )
{
	// transition ':TOP:testPassed:False'
	rtgChainBegin( 4, "False" );
	rtgTransitionBegin();
	transition3_False( msg->data, (SensorProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Sensor_Actor::chain5_disarm( void )
{
	// transition ':TOP:armed:J58B88D54000C:disarm'
	rtgChainBegin( 3, "disarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Sensor_Actor::chain6_tripped( void )
{
	// transition ':TOP:armed:J58B88D610111:tripped'
	rtgChainBegin( 3, "tripped" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_tripped( msg->data, (SensorTest::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

void Sensor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'SensorPort'
				switch( signalIndex )
				{
				case SensorProtocol::Conjugate::rti_arm:
					chain2_selfTest();
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
				// {{{RME port 'SensorPort'
				switch( signalIndex )
				{
				case SensorProtocol::Conjugate::rti_disarm:
					chain5_disarm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'SensorTest'
				switch( signalIndex )
				{
				case SensorTest::Base::rti_TriggerSensor:
					chain6_tripped();
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

const RTActor_class * Sensor_Actor::getActorData( void ) const
{
	return &Sensor_Actor::rtg_class;
}

const RTActor_class Sensor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , Sensor_Actor::rtg_parent_state
  , &Sensor
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Sensor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , Sensor_Actor::rtg_Sensor_fields
};

const RTStateId Sensor_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor Sensor_Actor::rtg_ports[] =
{
	{
		"SensorPort"
	  , (const char *)0
	  , &SensorProtocol::Conjugate::rt_class
	  , RTOffsetOf( Sensor_Actor, Sensor_Actor::SensorPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"SensorTest"
	  , (const char *)0
	  , &SensorTest::Base::rt_class
	  , RTOffsetOf( Sensor_Actor, Sensor_Actor::SensorTest )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor Sensor_Actor::rtg_Sensor_fields[] =
{
	// {{{RME classAttribute 'BreakSensors'
	{
		"BreakSensors"
	  , RTOffsetOf( Sensor_Actor, BreakSensors )
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
