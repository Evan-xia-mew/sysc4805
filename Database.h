// {{{RME classifier 'Logical View::Database'

#ifndef Database_H
#define Database_H

#ifdef PRAGMA
#pragma interface "Database.h"
#endif

#include <RTSystem/TestComponent.h>
#include <DatabaseProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Database;

#define SUPER RTActor
class Database_Actor : public RTActor
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
	// {{{RME classAttribute 'EventLog'
	int EventLog;
	// }}}RME
	// {{{RME classAttribute 'ValidIDs'
	int ValidIDs[ 3 ][ 5 ];
	// }}}RME
	// {{{RME classAttribute 'SecurityLevel'
	int SecurityLevel[ 5 ];
	// }}}RME

protected:
	// {{{RME port 'DatabasePort'
	DatabaseProtocol::Base DatabasePort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	Database_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Database_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:idle:J58B890A00180:returnValue'
	INLINE_METHODS void transition1_returnValue( const CardInfo * rtdata, DatabaseProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition2_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58B890370236:logEvent'
	INLINE_METHODS void transition3_logEvent( const int * rtdata, DatabaseProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58DD67570289:viewEvents'
	INLINE_METHODS void transition4_viewEvents( const void * rtdata, DatabaseProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain2_Initial( void );
	INLINE_CHAINS void chain1_returnValue( void );
	INLINE_CHAINS void chain3_logEvent( void );
	INLINE_CHAINS void chain4_viewEvents( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_Database_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Database_H */

// }}}RME
