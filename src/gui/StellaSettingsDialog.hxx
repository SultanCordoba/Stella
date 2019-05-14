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

#ifndef STELLA_OPTIONS_DIALOG_HXX
#define STELLA_OPTIONS_DIALOG_HXX

class PopUpWidget;

#include "Props.hxx"
#include "Menu.hxx"
#include "Dialog.hxx"
#include "MessageBox.hxx"
// FIXME - use the R77 define in the final release
//         use the '1' define for testing
#if defined(RETRON77)
// #if 1
#include "R77HelpDialog.hxx"
#else
#include "HelpDialog.hxx"
#endif

namespace GUI {
  class Font;
}

class StellaSettingsDialog : public Dialog
{
  public:
    StellaSettingsDialog(OSystem& osystem, DialogContainer& parent,
      const GUI::Font& font, int max_w, int max_h, Menu::AppMode mode);
    virtual ~StellaSettingsDialog() = default;

  private:
    void loadConfig() override;
    void saveConfig() override;
    void setDefaults() override;

    void addVideoOptions(WidgetArray& wid, int& xpos, int& ypos, const GUI::Font& font);
    void addUIOptions(WidgetArray& wid, int& xpos, int& ypos, const GUI::Font& font);
    void addGameOptions(WidgetArray& wid, int& xpos, int& ypos, const GUI::Font& font);

    void handleCommand(CommandSender* sender, int cmd, int data, int id) override;

    // switch to advanced settings after user confirmation
    void switchSettingsMode();

    // load the properties for the controller settings
    void loadControllerProperties(const Properties& props);

    // convert internal setting values to user friendly levels
    int levelToValue(int level);
    int valueToLevel(int value);

    void openHelp();

  private:
    // UI theme
    PopUpWidget*      myThemePopup;
    PopUpWidget*      myPositionPopup;

    // TV effects
    PopUpWidget*      myTVMode;

    // TV scanline intensity
    StaticTextWidget* myTVScanlines;
    SliderWidget*     myTVScanIntense;

    // TV phosphor effect
    SliderWidget*     myTVPhosLevel;

    // Controller properties
    StaticTextWidget* myGameSettings;

    StaticTextWidget* myLeftPortLabel;
    StaticTextWidget* myRightPortLabel;
    PopUpWidget*      myLeftPort;
    StaticTextWidget* myLeftPortDetected;
    PopUpWidget*      myRightPort;
    StaticTextWidget* myRightPortDetected;

    unique_ptr<GUI::MessageBox> myConfirmMsg;
    // FIXME - use the R77 define in the final release
    //         use the '1' define for testing
  #if defined(RETRON77)
  // #if 1
    unique_ptr<R77HelpDialog> myHelpDialog;
  #else
    unique_ptr<HelpDialog> myHelpDialog;
  #endif

    // Indicates if this dialog is used for global (vs. in-game) settings
    Menu::AppMode myMode;

    enum {
      kAdvancedSettings = 'SSad',
      kConfirmSwitchCmd = 'SScf',
      kHelp             = 'SShl',
      kScanlinesChanged = 'SSsc',
      kPhosphorChanged  = 'SSph'
    };

    // Game properties for currently loaded ROM
    Properties myGameProperties;

    // Following constructors and assignment operators not supported
    StellaSettingsDialog() = delete;
    StellaSettingsDialog(const StellaSettingsDialog&) = delete;
    StellaSettingsDialog(StellaSettingsDialog&&) = delete;
    StellaSettingsDialog& operator=(const StellaSettingsDialog&) = delete;
    StellaSettingsDialog& operator=(StellaSettingsDialog&&) = delete;
};

#endif
