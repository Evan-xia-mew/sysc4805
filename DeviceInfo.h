// {{{RME classifier 'Logical View::DeviceInfo'

#ifndef DeviceInfo_H
#define DeviceInfo_H

#ifdef PRAGMA
#pragma interface "DeviceInfo.h"
#endif

#include <RTSystem/TestComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_DeviceInfo;

class DeviceInfo
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
	// {{{RME classAttribute 'Zone'
	int Zone;
	// }}}RME
	// {{{RME classAttribute 'DeviceID'
	int DeviceID;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DeviceInfo( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeviceInfo( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	DeviceInfo( const DeviceInfo & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	DeviceInfo & operator=( const DeviceInfo & rtg_arg );
	// }}}RME
	static const RTFieldDescriptor rtg_DeviceInfo_fields[];
};

struct RTTypedValue_DeviceInfo
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_DeviceInfo( const DeviceInfo & rtg_value )
		: data( &rtg_value ), type( &RTType_DeviceInfo )
	{
	}
	inline RTTypedValue_DeviceInfo( const DeviceInfo & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_DeviceInfo( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeviceInfo_H */

// }}}RME
