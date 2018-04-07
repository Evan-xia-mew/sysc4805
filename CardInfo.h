// {{{RME classifier 'Logical View::CardInfo'

#ifndef CardInfo_H
#define CardInfo_H

#ifdef PRAGMA
#pragma interface "CardInfo.h"
#endif

#include <RTSystem/TestComponent.h>
extern const RTActorClass CardReader;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_CardInfo;

class CardInfo
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

public:
	// {{{RME classAttribute 'CardNumber'
	int CardNumber;
	// }}}RME
	// {{{RME classAttribute 'Zone'
	int Zone;
	// }}}RME
	// {{{RME classAttribute 'Clearance'
	bool Clearance;
	// }}}RME
	// {{{RME classAttribute 'DoorNumber'
	int DoorNumber;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	CardInfo( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~CardInfo( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	CardInfo( const CardInfo & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	CardInfo & operator=( const CardInfo & rtg_arg );
	// }}}RME
};

struct RTTypedValue_CardInfo
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_CardInfo( const CardInfo & rtg_value )
		: data( &rtg_value ), type( &RTType_CardInfo )
	{
	}
	inline RTTypedValue_CardInfo( const CardInfo & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_CardInfo( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CardInfo_H */

// }}}RME
