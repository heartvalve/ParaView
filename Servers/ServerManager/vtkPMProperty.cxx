/*=========================================================================

  Program:   ParaView
  Module:    $RCSfile$

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPMProperty.h"

#include "vtkClientServerInterpreter.h"
#include "vtkObjectFactory.h"
#include "vtkPMProxy.h"
#include "vtkPVXMLElement.h"

vtkStandardNewMacro(vtkPMProperty);
//----------------------------------------------------------------------------
vtkPMProperty::vtkPMProperty()
{
  this->Command = 0;
  this->XMLName = 0;
  this->UpdateSelf = false;
  this->InformationOnly = false;
  this->Repeatable = false;
  this->ProxyHelper = 0;
}

//----------------------------------------------------------------------------
vtkPMProperty::~vtkPMProperty()
{
  this->SetCommand(0);
  this->SetXMLName(0);
}

//----------------------------------------------------------------------------
bool vtkPMProperty::ReadXMLAttributes(
  vtkPMProxy* proxyhelper, vtkPVXMLElement* element)
{
  this->ProxyHelper = proxyhelper;

  const char* xmlname = element->GetAttribute("name");
  if(xmlname)
    {
    this->SetXMLName(xmlname);
    }

  const char* command = element->GetAttribute("command");
  if (command)
    {
    this->SetCommand(command);
    }

  int repeatable;
  if (element->GetScalarAttribute("repeatable", &repeatable))
    {
    this->Repeatable = (repeatable != 0);
    }

  // Yup, both mean the same thing :).
  int repeat_command;
  if (element->GetScalarAttribute("repeat_command", &repeat_command))
    {
    this->Repeatable = repeat_command;
    }


  int update_self;
  if (element->GetScalarAttribute("update_self", &update_self))
    {
    this->UpdateSelf = (update_self != 0);
    }

  int information_only;
  if (element->GetScalarAttribute("information_only", &information_only))
    {
    this->InformationOnly = (information_only != 0);
    }
  return true;
}

//----------------------------------------------------------------------------
vtkClientServerID vtkPMProperty::GetVTKObjectID()
{
  if (this->ProxyHelper)
    {
    return this->ProxyHelper->GetVTKObjectID();
    }

  return vtkClientServerID(0);
}

//----------------------------------------------------------------------------
bool vtkPMProperty::ProcessMessage(vtkClientServerStream& stream)
{
  if (this->ProxyHelper)
    {
    return this->ProxyHelper->GetInterpreter()->ProcessStream(stream) != 0;
    }
  return false;
}

//----------------------------------------------------------------------------
void vtkPMProperty::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}