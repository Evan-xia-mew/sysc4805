// {{{RME classifier 'Logical View::ControlCenter'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ControlCenter.h"
#endif

#include <RTSystem/TestComponent.h>
#include <ControlCenter.h>
extern const RTActorClass ActiveAlarms;
extern const RTActorClass Database;
extern const RTActorClass LocalController;
extern const RTActorClass Printer;
extern const RTActorClass controlCenterAlarm;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"InterfacePort"
	  , &Test::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ControlCenter_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ControlCenter_Actor( _rts, _ref );
}

const RTActorClass ControlCenter =
{
	(const RTActorClass *)0
  , "ControlCenter"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ControlCenter_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "idle"
};

static const RTInterfaceDescriptor rtg_interfaces_alarmR1[] =
{
	{
		"CCAlarmPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_alarmR1[] =
{
	{
		0
	  , &CCAlarmProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_LocalControllerR1[] =
{
	{
		"ControlPort"
	  , 1
	}
  , {
		"LocalTest"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_LocalControllerR1[] =
{
	{
		0
	  , &Control::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_printerR1[] =
{
	{
		"PrinterPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_printerR1[] =
{
	{
		0
	  , &PrinterProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_activeAlarmsR1[] =
{
	{
		"ActiveAlarmsPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_activeAlarmsR1[] =
{
	{
		0
	  , &CCAlarmProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_databaseR1[] =
{
	{
		"DatabasePort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_databaseR1[] =
{
	{
		0
	  , &DatabaseProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

ControlCenter_Actor::ControlCenter_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ControlCenter_Actor::~ControlCenter_Actor( void )
{
}

int ControlCenter_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// InterfacePort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &InterfacePort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int ControlCenter_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// alarmR1
		switch( rtg_portId )
		{
		case 0:
			// CCAlarmPort
			if( rtg_repIndex < 1 )
			{
				// CCAlarmPort
				rtg_end.port = &CCAlarmPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// LocalControllerR1
		switch( rtg_portId )
		{
		case 0:
			// ControlPort
			if( rtg_repIndex < 5 )
			{
				// ControlPort
				rtg_end.port = &ControlPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 3:
		// printerR1
		switch( rtg_portId )
		{
		case 0:
			// PrinterPort
			if( rtg_repIndex < 1 )
			{
				// PrinterPort
				rtg_end.port = &PrinterPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 4:
		// activeAlarmsR1
		switch( rtg_portId )
		{
		case 0:
			// ActiveAlarmsPort
			if( rtg_repIndex < 1 )
			{
				// ActiveAlarmsPort
				rtg_end.port = &ActiveAlarmsPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 5:
		// databaseR1
		switch( rtg_portId )
		{
		case 0:
			// DatabasePort
			if( rtg_repIndex < 1 )
			{
				// DatabasePort
				rtg_end.port = &DatabasePort;
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

// {{{RME transition ':TOP:idle:J58B891450108:cardSwipe'
INLINE_METHODS void ControlCenter_Actor::transition2_cardSwipe( const CardInfo * rtdata, Control::Base * rtport )
{
	// {{{USR
	//verify card info using database
	CardInfo cardInfo = *rtdata;
	cardInfo.Zone = msg->sapIndex0();
	DatabasePort.cardIn(cardInfo).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58B893C50331:clearActiveAlarm'
INLINE_METHODS void ControlCenter_Actor::transition3_clearActiveAlarm( const int * rtdata, Test::Base * rtport )
{
	// {{{USR
	//send resolveAlarm to a local controller
	//to resolve an active alarm

	int zone = *rtdata;
	if(zone==0)
	{
		ControlPort.resolveAlarm().send();
		ActiveAlarmsPort.resolveAlarm(0).send();
	}
	else
	{
		ControlPort.resolveAlarm().sendAt(zone-1);
		ActiveAlarmsPort.resolveAlarm(1).send();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58DAABB30290:secViolation'
INLINE_METHODS void ControlCenter_Actor::transition4_secViolation( const void * rtdata, Control::Base * rtport )
{
	// {{{USR
	//send security violation (door held 1
	//minute) to database and printer

	DatabasePort.event(1).send();
	PrinterPort.printEvent(1).send();


	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58B8946700E1:armZone'
INLINE_METHODS void ControlCenter_Actor::transition5_armZone( const int * rtdata, Test::Base * rtport )
{
	// {{{USR
	//send armZone to a local controller
	//or all local controllers if 0

	int zone = *rtdata;
	if(zone==0)
		ControlPort.armZone().send();
	else
		ControlPort.armZone().sendAt(zone-1);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58B8946D023E:disarmZone'
INLINE_METHODS void ControlCenter_Actor::transition6_disarmZone( const int * rtdata, Test::Base * rtport )
{
	// {{{USR
	//send disarmZone to a local controller
	//or all local controllers if 0

	int zone = *rtdata;
	if(zone==0)
		ControlPort.disarmZone().send();
	else
		ControlPort.disarmZone().sendAt(zone-1);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58B8C1E70309:cardVerify'
INLINE_METHODS void ControlCenter_Actor::transition7_cardVerify( const CardInfo * rtdata, DatabaseProtocol::Conjugate * rtport )
{
	// {{{USR
	//send appropriate validity signal to a local controller
	CardInfo cardInfo = *rtdata;
	if (cardInfo.Clearance)
		ControlPort.cardValid(cardInfo).sendAt(cardInfo.Zone);
	else
	{
		ControlPort.cardInvalid(cardInfo).sendAt(cardInfo.Zone);
		//log security violation in database
		//and notify printer
		DatabasePort.event(1).send();
		PrinterPort.printEvent(3).send();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58D9907B000D:repairNeeded'
INLINE_METHODS void ControlCenter_Actor::transition8_repairNeeded( const void * rtdata, Control::Base * rtport )
{
	// {{{USR
	//Display a message indicating that a
	//device in a particular zone needs repairs

	int index = msg->sapIndex0();
	log.log("A device needs repair in zone");
	log.log(index);

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58DAABFF0054:secAlarm'
INLINE_METHODS void ControlCenter_Actor::transition9_secAlarm( const void * rtdata, Control::Base * rtport )
{
	// {{{USR
	//send security alarm (door held 5 minutes or break in)
	//to database and printer

	DatabasePort.event(2).send();
	PrinterPort.printEvent(2).send();


	//send addAlarm to ActiveAlarms
	ActiveAlarmsPort.addAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58DD4684028C:activateCCAlarm'
INLINE_METHODS void ControlCenter_Actor::transition10_activateCCAlarm( const void * rtdata, CCAlarmProtocol::Base * rtport )
{
	// {{{USR
	CCAlarmPort.activateCCAlarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58DD469A02AC:clearCCAlarm'
INLINE_METHODS void ControlCenter_Actor::transition11_clearCCAlarm( const void * rtdata, CCAlarmProtocol::Base * rtport )
{
	// {{{USR
	CCAlarmPort.deactivateCCAlarm().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ControlCenter_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain7_cardVerify( void )
{
	// transition ':TOP:idle:J58B8C1E70309:cardVerify'
	rtgChainBegin( 2, "cardVerify" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_cardVerify( (const CardInfo *)msg->data, (DatabaseProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain2_cardSwipe( void )
{
	// transition ':TOP:idle:J58B891450108:cardSwipe'
	rtgChainBegin( 2, "cardSwipe" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_cardSwipe( (const CardInfo *)msg->data, (Control::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain9_secAlarm( void )
{
	// transition ':TOP:idle:J58DAABFF0054:secAlarm'
	rtgChainBegin( 2, "secAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_secAlarm( msg->data, (Control::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain8_repairNeeded( void )
{
	// transition ':TOP:idle:J58D9907B000D:repairNeeded'
	rtgChainBegin( 2, "repairNeeded" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_repairNeeded( msg->data, (Control::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain4_secViolation( void )
{
	// transition ':TOP:idle:J58DAABB30290:secViolation'
	rtgChainBegin( 2, "secViolation" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_secViolation( msg->data, (Control::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain5_armZone( void )
{
	// transition ':TOP:idle:J58B8946700E1:armZone'
	rtgChainBegin( 2, "armZone" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_armZone( (const int *)msg->data, (Test::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain6_disarmZone( void )
{
	// transition ':TOP:idle:J58B8946D023E:disarmZone'
	rtgChainBegin( 2, "disarmZone" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_disarmZone( (const int *)msg->data, (Test::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain3_clearActiveAlarm( void )
{
	// transition ':TOP:idle:J58B893C50331:clearActiveAlarm'
	rtgChainBegin( 2, "clearActiveAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_clearActiveAlarm( (const int *)msg->data, (Test::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain10_activateCCAlarm( void )
{
	// transition ':TOP:idle:J58DD4684028C:activateCCAlarm'
	rtgChainBegin( 2, "activateCCAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_activateCCAlarm( msg->data, (CCAlarmProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ControlCenter_Actor::chain11_clearCCAlarm( void )
{
	// transition ':TOP:idle:J58DD469A02AC:clearCCAlarm'
	rtgChainBegin( 2, "clearCCAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition11_clearCCAlarm( msg->data, (CCAlarmProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void ControlCenter_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'DatabasePort'
				switch( signalIndex )
				{
				case DatabaseProtocol::Conjugate::rti_validCard:
					chain7_cardVerify();
					return;
				case DatabaseProtocol::Conjugate::rti_invalidCard:
					chain7_cardVerify();
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
				case Control::Base::rti_cardIn:
					chain2_cardSwipe();
					return;
				case Control::Base::rti_sensorTriggered:
					chain9_secAlarm();
					return;
				case Control::Base::rti_needRepair:
					chain8_repairNeeded();
					return;
				case Control::Base::rti_doorHeld1:
					chain4_secViolation();
					return;
				case Control::Base::rti_doorHeld5:
					chain9_secAlarm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'InterfacePort'
				switch( signalIndex )
				{
				case Test::Base::rti_arm:
					chain5_armZone();
					return;
				case Test::Base::rti_disarm:
					chain6_disarmZone();
					return;
				case Test::Base::rti_resolveAlarm:
					chain3_clearActiveAlarm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 5:
				// {{{RME port 'ActiveAlarmsPort'
				switch( signalIndex )
				{
				case CCAlarmProtocol::Base::rti_activateCCAlarm:
					chain10_activateCCAlarm();
					return;
				case CCAlarmProtocol::Base::rti_deactivateCCAlarm:
					chain11_clearCCAlarm();
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

const RTActor_class * ControlCenter_Actor::getActorData( void ) const
{
	return &ControlCenter_Actor::rtg_class;
}

const RTActor_class ControlCenter_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , ControlCenter_Actor::rtg_parent_state
  , &ControlCenter
  , 5
  , ControlCenter_Actor::rtg_capsule_roles
  , 7
  , ControlCenter_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId ControlCenter_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor ControlCenter_Actor::rtg_capsule_roles[] =
{
	{
		"alarmR1"
	  , &controlCenterAlarm
	  , RTOffsetOf( ControlCenter_Actor, alarmR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_alarmR1
	  , 1
	  , rtg_bindings_alarmR1
	}
  , {
		"LocalControllerR1"
	  , &LocalController
	  , RTOffsetOf( ControlCenter_Actor, LocalControllerR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 5 // cardinality
	  , 2
	  , rtg_interfaces_LocalControllerR1
	  , 1
	  , rtg_bindings_LocalControllerR1
	}
  , {
		"printerR1"
	  , &Printer
	  , RTOffsetOf( ControlCenter_Actor, printerR1 )
	  , 3
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_printerR1
	  , 1
	  , rtg_bindings_printerR1
	}
  , {
		"activeAlarmsR1"
	  , &ActiveAlarms
	  , RTOffsetOf( ControlCenter_Actor, activeAlarmsR1 )
	  , 4
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_activeAlarmsR1
	  , 1
	  , rtg_bindings_activeAlarmsR1
	}
  , {
		"databaseR1"
	  , &Database
	  , RTOffsetOf( ControlCenter_Actor, databaseR1 )
	  , 5
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_databaseR1
	  , 1
	  , rtg_bindings_databaseR1
	}
};

const RTPortDescriptor ControlCenter_Actor::rtg_ports[] =
{
	{
		"DatabasePort"
	  , (const char *)0
	  , &DatabaseProtocol::Conjugate::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::DatabasePort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"PrinterPort"
	  , (const char *)0
	  , &PrinterProtocol::Base::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::PrinterPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"ControlPort"
	  , (const char *)0
	  , &Control::Base::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::ControlPort )
	  , 5 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"InterfacePort"
	  , (const char *)0
	  , &Test::Base::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::InterfacePort )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"ActiveAlarmsPort"
	  , (const char *)0
	  , &CCAlarmProtocol::Base::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::ActiveAlarmsPort )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"CCAlarmPort"
	  , (const char *)0
	  , &CCAlarmProtocol::Base::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::CCAlarmPort )
	  , 1 // cardinality
	  , 6
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( ControlCenter_Actor, ControlCenter_Actor::log )
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
