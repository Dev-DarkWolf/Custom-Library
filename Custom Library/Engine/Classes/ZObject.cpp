#include "ZObject.h"

#include <string>

ZObject::ZObject(char* Name)
{
	strcpy_s(stName, Name);
}

ZObject::ZObject(char * Name, ZObject * Parent)
{
	strcpy_s(stName, Name);
	pParent = Parent;
}

ZObject::~ZObject()
{
}

void ZObject::Rename(char * newName)
{
	strcpy_s(stName, newName);
}

ZObject * ZObject::GetParent()
{
	return pParent;
}

bool ZObject::operator!=(ZObject * Compare)
{
	if (this != Compare)
	{
		return true;
	}
	return false;
}

bool ZObject::operator==(ZObject * Compare)
{
	if (this == Compare)
	{
		return true;
	}
	return false;
}
