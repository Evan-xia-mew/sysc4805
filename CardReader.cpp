// {{{RME classifier 'Logical View::CardReader'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CardReader.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardReader.h>
#include <CardInfo.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"ReaderPort"
	  , &CardReaderProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"TestSwipePort"
	  , &CardSwipe::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_CardReader_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new CardReader_Actor( _rts, _ref );
}

const RTActorClass CardReader =
{
	(const RTActorClass *)0
  , "CardReader"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_CardReader_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "idle"
};

#define SUPER RTActor

CardReader_Actor::CardReader_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

CardReader_Actor::~CardReader_Actor( void )
{
}

int CardReader_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// ReaderPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &ReaderPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// TestSwipePort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &TestSwipePort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:idle:J58B87FF8026D:readCard'
INLINE_METHODS void CardReader_Actor::transition2_readCard( const CardInfo * rtdata, CardSwipe::Base * rtport )
{
	// {{{USR
	//Send cardIn to the local controller
	CardInfo cardInfo = *rtdata;
	ReaderPort.cardIn(cardInfo).send();

	// }}}USR
}
// }}}RME

INLINE_CHAINS void CardReader_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CardReader_Actor::chain2_readCard( void )
{
	// transition ':TOP:idle:J58B87FF8026D:readCard'
	rtgChainBegin( 2, "readCard" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_readCard( (const CardInfo *)msg->data, (CardSwipe::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void CardReader_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			case 2:
				// {{{RME port 'TestSwipePort'
				switch( signalIndex )
				{
				case CardSwipe::Base::rti_cardSwipe:
					chain2_readCard();
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

const RTActor_class * CardReader_Actor::getActorData( void ) const
{
	return &CardReader_Actor::rtg_class;
}

const RTActor_class CardReader_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , CardReader_Actor::rtg_parent_state
  , &CardReader
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , CardReader_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId CardReader_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor CardReader_Actor::rtg_ports[] =
{
	{
		"ReaderPort"
	  , (const char *)0
	  , &CardReaderProtocol::Conjugate::rt_class
	  , RTOffsetOf( CardReader_Actor, CardReader_Actor::ReaderPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"TestSwipePort"
	  , (const char *)0
	  , &CardSwipe::Base::rt_class
	  , RTOffsetOf( CardReader_Actor, CardReader_Actor::TestSwipePort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
