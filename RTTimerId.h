// {{{RME classifier 'Logical View::RTTimerId'

#ifndef RTTimerId_H
#define RTTimerId_H

#ifdef PRAGMA
#pragma interface "RTTimerId.h"
#endif

#include <RTSystem/TestComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_RTTimerId;

class RTTimerId
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
	// {{{RME classAttribute 'TimerID'
	RTTimerId TimerID;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	RTTimerId( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~RTTimerId( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	RTTimerId( const RTTimerId & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	RTTimerId & operator=( const RTTimerId & rtg_arg );
	// }}}RME
	static const RTFieldDescriptor rtg_RTTimerId_fields[];
};

struct RTTypedValue_RTTimerId
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_RTTimerId( const RTTimerId & rtg_value )
		: data( &rtg_value ), type( &RTType_RTTimerId )
	{
	}
	inline RTTypedValue_RTTimerId( const RTTimerId & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_RTTimerId( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RTTimerId_H */

// }}}RME
