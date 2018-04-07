// {{{RME classifier 'Logical View::CardReader'

#ifndef CardReader_H
#define CardReader_H

#ifdef PRAGMA
#pragma interface "CardReader.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardReaderProtocol.h>
#include <CardSwipe.h>
class CardInfo;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass CardReader;

#define SUPER RTActor
class CardReader_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME port 'ReaderPort'
	CardReaderProtocol::Conjugate ReaderPort;
	// }}}RME
	// {{{RME port 'TestSwipePort'
	CardSwipe::Base TestSwipePort;
	// }}}RME

public:
	CardReader_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~CardReader_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:idle:J58B87FF8026D:readCard'
	INLINE_METHODS void transition2_readCard( const CardInfo * rtdata, CardSwipe::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_readCard( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CardReader_H */

// }}}RME
