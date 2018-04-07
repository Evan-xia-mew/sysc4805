// {{{RME classifier 'Logical View::Database'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Database.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Database.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"DatabasePort"
	  , &DatabaseProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Database_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Database_Actor( _rts, _ref );
}

const RTActorClass Database =
{
	(const RTActorClass *)0
  , "Database"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Database_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "idle"
};

const RTTypeModifier rtg_tm_Database_Actor_ValidIDs =
{
	RTNumberConstant
  , (3) * (5)
  , 0
};

const RTTypeModifier rtg_tm_Database_Actor_SecurityLevel =
{
	RTNumberConstant
  , (5)
  , 0
};

#define SUPER RTActor

Database_Actor::Database_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, EventLog( 0 )
{
}

Database_Actor::~Database_Actor( void )
{
}

int Database_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// DatabasePort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &DatabasePort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:idle:J58B890A00180:returnValue'
INLINE_METHODS void Database_Actor::transition1_returnValue( const CardInfo * rtdata, DatabaseProtocol::Base * rtport )
{
	// {{{USR
	CardInfo cardInfo = *rtdata;

	//Get the security level for this zone
	int securityLevel = SecurityLevel[cardInfo.Zone];

	for (int i = 0; i < sizeof(ValidIDs[securityLevel])/sizeof(ValidIDs[securityLevel][0]); i++)
	{
		cardInfo.Clearance = (cardInfo.CardNumber == ValidIDs[securityLevel][i]);
		if (cardInfo.Clearance)
		{
			DatabasePort.validCard(cardInfo).send();
			return;
		}
	}
	DatabasePort.invalidCard(cardInfo).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void Database_Actor::transition2_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	//intialaize database information: 
	//valid IDs for each security level and security level of each zone
	//Hard coded to simulate pre-stored database information

	//3 security levels for 5 zones
	SecurityLevel[0] = 0;		//Zone 0 has security level 0
	SecurityLevel[1] = 2;		//Zone 1 has security level 2
	SecurityLevel[2] = 1;
	SecurityLevel[3] = 1;
	SecurityLevel[4] = 2;


	//The list of valid card numbers to access each security level
	//Security Level 0
	ValidIDs[0][0] = 11;
	ValidIDs[0][1] = 12;
	ValidIDs[0][2] = 13;
	ValidIDs[0][3] = 14;
	ValidIDs[0][4] = 15;


	//Security Level 1
	ValidIDs[1][0] = 11;
	ValidIDs[1][1] = 13;
	ValidIDs[1][2] = 15;


	//Security Level 2
	ValidIDs[2][0] = 13;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58B890370236:logEvent'
INLINE_METHODS void Database_Actor::transition3_logEvent( const int * rtdata, DatabaseProtocol::Base * rtport )
{
	// {{{USR
	EventLog++;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:idle:J58DD67570289:viewEvents'
INLINE_METHODS void Database_Actor::transition4_viewEvents( const void * rtdata, DatabaseProtocol::Base * rtport )
{
	// {{{USR
	log.log("Number of events logged:");
	log.log(EventLog);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Database_Actor::chain2_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition2_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Database_Actor::chain1_returnValue( void )
{
	// transition ':TOP:idle:J58B890A00180:returnValue'
	rtgChainBegin( 2, "returnValue" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_returnValue( (const CardInfo *)msg->data, (DatabaseProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Database_Actor::chain3_logEvent( void )
{
	// transition ':TOP:idle:J58B890370236:logEvent'
	rtgChainBegin( 2, "logEvent" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_logEvent( (const int *)msg->data, (DatabaseProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Database_Actor::chain4_viewEvents( void )
{
	// transition ':TOP:idle:J58DD67570289:viewEvents'
	rtgChainBegin( 2, "viewEvents" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_viewEvents( msg->data, (DatabaseProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Database_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'DatabasePort'
				switch( signalIndex )
				{
				case DatabaseProtocol::Base::rti_cardIn:
					chain1_returnValue();
					return;
				case DatabaseProtocol::Base::rti_event:
					chain3_logEvent();
					return;
				case DatabaseProtocol::Base::rti_viewEvents:
					chain4_viewEvents();
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

const RTActor_class * Database_Actor::getActorData( void ) const
{
	return &Database_Actor::rtg_class;
}

const RTActor_class Database_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Database_Actor::rtg_parent_state
  , &Database
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Database_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 3
  , Database_Actor::rtg_Database_fields
};

const RTStateId Database_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor Database_Actor::rtg_ports[] =
{
	{
		"DatabasePort"
	  , (const char *)0
	  , &DatabaseProtocol::Base::rt_class
	  , RTOffsetOf( Database_Actor, Database_Actor::DatabasePort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Database_Actor, Database_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor Database_Actor::rtg_Database_fields[] =
{
	// {{{RME classAttribute 'EventLog'
	{
		"EventLog"
	  , RTOffsetOf( Database_Actor, EventLog )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'ValidIDs'
  , {
		"ValidIDs"
	  , RTOffsetOf( Database_Actor, ValidIDs[ 0 ][ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_Database_Actor_ValidIDs
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'SecurityLevel'
  , {
		"SecurityLevel"
	  , RTOffsetOf( Database_Actor, SecurityLevel[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_Database_Actor_SecurityLevel
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
