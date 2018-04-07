// {{{RME classifier 'Logical View::Door'

#ifndef Door_H
#define Door_H

#ifdef PRAGMA
#pragma interface "Door.h"
#endif

#include <RTSystem/TestComponent.h>
#include <DoorProtocol.h>
#include <DoorTest.h>
class DeviceInfo;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Door;

#define SUPER RTActor
class Door_Actor : public RTActor
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
	// {{{RME classAttribute 'DoorTimer'
	RTTimerId DoorTimer;
	// }}}RME

protected:
	// {{{RME port 'DoorPort'
	DoorProtocol::Conjugate DoorPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME
	// {{{RME port 'DoorTestPort'
	DoorTest::Base DoorTestPort;
	// }}}RME

public:
	Door_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Door_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:doorLocked:J58B88C4101A6:unlock'
	INLINE_METHODS void transition2_unlock( const void * rtdata, DoorProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:doorUnlocked:J58B88C470239:timeout'
	INLINE_METHODS void transition3_timeout( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:doorUnlocked:J58B9B9F7025C:open'
	INLINE_METHODS void transition4_open( const void * rtdata, DoorTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:doorOpen:J58B9B9FE0202:close'
	INLINE_METHODS void transition5_close( const void * rtdata, DoorTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:doorOpen:J58D9860D00C2:doorHeld1min'
	INLINE_METHODS void transition6_doorHeld1min( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:doorHeld:J58D9865302AC:doorHeld5min'
	INLINE_METHODS void transition7_doorHeld5min( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:doorHeld:J58D98688021D:close'
	INLINE_METHODS void transition8_close( const void * rtdata, DoorTest::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_unlock( void );
	INLINE_CHAINS void chain3_timeout( void );
	INLINE_CHAINS void chain4_open( void );
	INLINE_CHAINS void chain6_doorHeld1min( void );
	INLINE_CHAINS void chain5_close( void );
	INLINE_CHAINS void chain7_doorHeld5min( void );
	INLINE_CHAINS void chain8_close( void );

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
	static const RTFieldDescriptor rtg_Door_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Door_H */

// }}}RME
