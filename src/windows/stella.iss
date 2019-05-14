; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=Stella
AppVerName=Stella {#STELLA_VER}
AppPublisher=The Stella Team
AppPublisherURL=https://stella-emu.github.io
AppSupportURL=https://stella-emu.github.io
AppUpdatesURL=https://stella-emu.github.io
DefaultDirName={pf}\Stella
DefaultGroupName=Stella
OutputBaseFilename="Stella-{#STELLA_VER}-{#STELLA_ARCH}"
Compression=lzma
SolidCompression=yes
UninstallDisplayIcon={app}\Stella.exe
#if STELLA_ARCH == "x64"
ArchitecturesInstallIn64BitMode=x64
ArchitecturesAllowed=x64
#endif

[Languages]
Name: "eng"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}";

[Files]
Source: "{#STELLA_PATH}\Stella.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#STELLA_PATH}\*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#STELLA_DOCPATH}\*"; DestDir: "{app}\docs"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Stella"; Filename: "{app}\Stella.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Stella"; Filename: "{app}\Stella.exe"; WorkingDir: "{app}"; Tasks: desktopicon
Name: "{group}\Documentation"; Filename: "{app}\docs\index.html"
Name: "{group}\Uninstall Stella"; Filename: "{uninstallexe}"
