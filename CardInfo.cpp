// {{{RME classifier 'Logical View::CardInfo'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CardInfo.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardInfo.h>
#include <CardReader.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_CardInfo_init( const RTObject_class * type, CardInfo * target )
{
	(void)new( target ) CardInfo;
}

static void rtg_CardInfo_copy( const RTObject_class * type, CardInfo * target, const CardInfo * source )
{
	(void)new( target ) CardInfo( *source );
}

static void rtg_CardInfo_destroy( const RTObject_class * type, CardInfo * target )
{
	target->~CardInfo();
}

const RTFieldDescriptor rtg_CardInfo_fields[] =
{
	// {{{RME classAttribute 'CardNumber'
	{
		"CardNumber"
	  , RTOffsetOf( CardInfo, CardNumber )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Zone'
  , {
		"Zone"
	  , RTOffsetOf( CardInfo, Zone )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Clearance'
  , {
		"Clearance"
	  , RTOffsetOf( CardInfo, Clearance )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'DoorNumber'
  , {
		"DoorNumber"
	  , RTOffsetOf( CardInfo, DoorNumber )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_CardInfo =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "CardInfo"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( CardInfo )
  , (RTInitFunction)rtg_CardInfo_init
  , (RTCopyFunction)rtg_CardInfo_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_CardInfo_destroy
  , 4
  , rtg_CardInfo_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
CardInfo::CardInfo( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
CardInfo::~CardInfo( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
CardInfo::CardInfo( const CardInfo & rtg_arg )
	: CardNumber( rtg_arg.CardNumber )
	, Zone( rtg_arg.Zone )
	, Clearance( rtg_arg.Clearance )
	, DoorNumber( rtg_arg.DoorNumber )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
CardInfo & CardInfo::operator=( const CardInfo & rtg_arg )
{
	if( this != &rtg_arg )
	{
		CardNumber = rtg_arg.CardNumber;
		Zone = rtg_arg.Zone;
		Clearance = rtg_arg.Clearance;
		DoorNumber = rtg_arg.DoorNumber;
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_CardInfo_installer( RTType_CardInfo );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
