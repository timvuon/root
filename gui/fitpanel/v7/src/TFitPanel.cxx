/// \file ROOT/TFitPanel.cxx
/// \ingroup WebGui ROOT7
/// \author Sergey Linev <S.Linev@gsi.de>
/// \date 2017-10-24
/// \warning This is part of the ROOT 7 prototype! It will change without notice. It might trigger earthquakes. Feedback
/// is welcome!

/*************************************************************************
 * Copyright (C) 1995-2017, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#include "ROOT/TFitPanel.hxx"

#include <ROOT/TWebWindowsManager.hxx>


void ROOT::Experimental::TFitPanel::Show(const std::string &where)
{
   if (fWindow) return;

   fWindow = TWebWindowsManager::Instance()->CreateWindow(false);

   WebWindowDataCallback_t func = std::bind(&TFitPanel::ProcessData, this, std::placeholders::_1, std::placeholders::_2);
   fWindow->SetDataCallBack(func);

   fWindow->Show(where);
}

void ROOT::Experimental::TFitPanel::Hide()
{
   if (!fWindow) return;
}


void ROOT::Experimental::TFitPanel::ProcessData(unsigned connid, const std::string &arg)
{
}
