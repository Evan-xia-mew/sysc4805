// {{{RME classifier 'Logical View::Printer'

#ifndef Printer_H
#define Printer_H

#ifdef PRAGMA
#pragma interface "Printer.h"
#endif

#include <RTSystem/TestComponent.h>
#include <PrinterProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Printer;

#define SUPER RTActor
class Printer_Actor : public RTActor
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
	// {{{RME port 'PrinterPort'
	PrinterProtocol::Conjugate PrinterPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	Printer_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Printer_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:idle:J58B892CB01D0:printEvent'
	INLINE_METHODS void transition1_printEvent( const int * rtdata, PrinterProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain2_Initial( void );
	INLINE_CHAINS void chain1_printEvent( void );

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

#endif /* Printer_H */

// }}}RME
