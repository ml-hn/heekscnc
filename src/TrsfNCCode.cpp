// TrsfNCCode.cpp
// Copyright (c) 2009, Dan Heeks
// This program is released under the BSD license. See the file COPYING for details.

#include "stdafx.h"
#include "TrsfNCCode.h"
#include "PythonStuff.h"
#include "tinyxml/tinyxml.h"
#include "NCCode.h"

using namespace std;

CTrsfNCCode::CTrsfNCCode():m_x(0),m_y(0)
{
	Add(new CNCCode(),NULL);
}

CTrsfNCCode::~CTrsfNCCode()
{

}

HeeksObj *CTrsfNCCode::MakeACopy(void)const
{
	return new CTrsfNCCode(*this);
}


void CTrsfNCCode::GetProperties(std::list<Property *> *list)
{
	HeeksObj::GetProperties(list);
}

void CTrsfNCCode::WriteXML(TiXmlNode *root)
{
}

// static member function
HeeksObj* CTrsfNCCode::ReadFromXMLElement(TiXmlElement* pElem)
{
	return NULL;
}

void CTrsfNCCode::glCommands(bool select, bool marked, bool no_color)
{
	glPushMatrix();
	
	glTranslated(m_x,m_y,0);
	ObjList::glCommands(select,marked,no_color);

	glPopMatrix();
}