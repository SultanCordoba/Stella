//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2019 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef CARTRIDGE0840_WIDGET_HXX
#define CARTRIDGE0840_WIDGET_HXX

class Cartridge0840;
class PopUpWidget;

#include "CartDebugWidget.hxx"

class Cartridge0840Widget : public CartDebugWidget
{
  public:
    Cartridge0840Widget(GuiObject* boss, const GUI::Font& lfont,
                        const GUI::Font& nfont,
                        int x, int y, int w, int h,
                        Cartridge0840& cart);
    virtual ~Cartridge0840Widget() = default;

  private:
    Cartridge0840& myCart;
    PopUpWidget* myBank;

    enum { kBankChanged = 'bkCH' };

  private:
    void loadConfig() override;
    void handleCommand(CommandSender* sender, int cmd, int data, int id) override;

    string bankState() override;

    // Following constructors and assignment operators not supported
    Cartridge0840Widget() = delete;
    Cartridge0840Widget(const Cartridge0840Widget&) = delete;
    Cartridge0840Widget(Cartridge0840Widget&&) = delete;
    Cartridge0840Widget& operator=(const Cartridge0840Widget&) = delete;
    Cartridge0840Widget& operator=(Cartridge0840Widget&&) = delete;
};

#endif
