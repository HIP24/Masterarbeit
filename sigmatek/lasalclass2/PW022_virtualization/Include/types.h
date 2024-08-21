//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
TYPE
  _DRIVETYPE :
  (
    _NotFound,
    _SDD_310,
    _SDD_315,
    _SDD_105,
    _SDD_120,
    _SDD_305,
    _SDD_335,
    _SDD_215,
    _SDD_205,
    _SDD_210,
    _MDD_100,
    _S_340,
    _SDD_115,
    _SDD_1300:=811237,
    _SDD_1400:=811238,
    _SDD_1500:=811239,
    _SDD_1600:=811240,
    _MDD_2000:=811300,
    _VSDC_151:=811301,
    _VSDC_152:=811302,
    _DC061:=881042,
    _DC062:=881801,
    _SR011:=881802,
    _SR012:=881803,
    _DC101:=881804,
    _DC102:=881805,
    _WA011:=991800,
    _WA012:=991801
  )$UDINT;
#pragma pack(push, 1)
  _I_HC_Type : STRUCT  //! <Type Comment="Hardware Code an axis&#13;&#10;&#13;&#10;Bit 31..16 Hardware Code of the Control Board&#13;&#10;Bit 15...8 Software version of the feedback CPLD&#13;&#10;Bit   7...0 Hardware Code of the Power Stage" Name="_I_HC_Type"/>
    HardwareCodePowerStage : HSINT;  //! <Type Comment="Hardware Code of the Power Stage (Default: 16#80)" Name="_I_HC_Type.HardwareCodePowerStage"/>
    FPGAVersion : HSINT;  //! <Type Comment="Software version of the feedback CPLD" Name="_I_HC_Type.FPGAVersion"/>
    HardwareCodeControlBoard : HINT;  //! <Type Comment="Hardware Code of the Control Board (Default: 16#0000)" Name="_I_HC_Type.HardwareCodeControlBoard"/>
  END_STRUCT;
#pragma pack(pop)
  _SDDAXISSTATE : BDINT
  [
    1 NoHW,
    2 NoParameter,
    3 NotOnline,
    4 NotInitialized,
    5 SFFLimitationActive,
    6 DiagModeActive,
  ];
  _SDDUSERCMD :  //! <Type Comment="Type for user commands to the drive. See Server &apos;SDDCmdIntfc&apos; of the &apos;_DriveAxis&apos; class." Name="_SDDUSERCMD"/>
  (
    _SDDIDLE,  //! <Type Comment="default command" Name="_SDDUSERCMD._SDDIDLE"/>
    _SDDREADALL,  //! <Type Comment="read all parameters of the drive &#13;&#10;  and save the parameters in the SRAM or in the file.&#13;&#10;  If any parameter classes are connected to the class SDDMngBase,&#13;&#10;  the servers of the parameter classes are refreshed." Name="_SDDUSERCMD._SDDREADALL"/>
    _SDDINIT,  //! <Type Comment="Initialize the drive with the saved parameters." Name="_SDDUSERCMD._SDDINIT"/>
    _SDDURINIT,  //! <Type Comment="Initialize the drive with the parameters of the table.&#13;&#10;  (Lasal2 table, User Table or default table)" Name="_SDDUSERCMD._SDDURINIT"/>
    _SDDEXDATA,  //! <Type Comment="Export the actual drive parameter into an excel formatted file." Name="_SDDUSERCMD._SDDEXDATA"/>
    _SDDEXDATAXML:=6,  //! <Type Comment="Export the actual drive parameter into an xml formatted file." Name="_SDDUSERCMD._SDDEXDATAXML"/>
    _SDDIMDATAXML,  //! <Type Comment="Imports the drive parameter from an xml formatted file. User commands &quot;_SDDINIT&quot; must be called to transfer the data to the drive." Name="_SDDUSERCMD._SDDIMDATAXML"/>
    _SDDERROR,  //! <Type Comment="This value is shown, when the user commands &quot;_SDDEXDATAXML&quot;, &quot;_SDDIMDATAXML&quot;  or &quot;_SDDEXLOGFILE&quot; failed. See Log-File for details. New user commands can be set in this state." Name="_SDDUSERCMD._SDDERROR"/>
    _SDDEXLOGFILE  //! <Type Comment="Reads the Log File from the drive and writes it to the CPU under: &quot;C:\sysmsg\DriveLog&lt;Serial No&gt;.txt&quot;" Name="_SDDUSERCMD._SDDEXLOGFILE"/>
  )$UDINT;
  DS402_Control : BDINT
  [
    1 SwitchOn,
    2 EnableVoltage,
    3 QuickStop,
    4 EnableOperation,
    5 OperationModeSpec1,
    6 OperationModeSpec2,
    7 OperationModeSpec3,
    8 ResetFault,
    9 Halt,
    10 Reserved1,
    11 Reserved2,
    12 ManufactureSpec1,
    13 ManufactureSpec2,
    14 ManufactureSpec3,
    15 ManufactureSpec4,
    16 ManufactureSpec5,
  ];
  DS402_State : BDINT
  [
    1 ReadyToSwitchOn,
    2 SwitchedOn,
    3 OperationEnabled,
    4 Fault,
    5 VoltageEnabled,
    6 QuickStop,
    7 SwitchOnDisabled,
    8 Warning,
    9 ManufactureSpec1,
    10 Remote,
    11 TargetReached,
    12 InternalLimitActive,
    13 OperationModeSpec1,
    14 OperationModeSpec2,
    15 ManufactureSpec2,
    16 ManufactureSpec3,
  ];
  FeSetup : BDINT
  [
    1 Valid,  //! <Type Comment="must be 1 to Start FileEx work" Name="FeSetup.Valid"/>
    2 FileorRam,  //! <Type Comment="0= work in File 1= Work File" Name="FeSetup.FileorRam"/>
    3 EnableChecksum,  //! <Type Comment="0=no Checksum; 1=Calculate Checksum, increased write access on the CF card" Name="FeSetup.EnableChecksum"/>
    4 Encrypt,  //! <Type Comment="0=no encryption; 1=encrypt file, increased write access on the CF card" Name="FeSetup.Encrypt"/>
  ];
  IO_FLAG : BINT  //! <Type Comment="Status Flag f�r IO Daten" Name="IO_FLAG"/>
  [
    1 WrongHW,  //! <Type Comment="Falsche Hardware verbunden" Name="IO_FLAG.WrongHW"/>
    2 NoHW,  //! <Type Comment="Keine Hardware verbunden" Name="IO_FLAG.NoHW"/>
    3 NoCalibration,  //! <Type Comment="Keine Kalibrierungsdaten im Modul-EEPROM" Name="IO_FLAG.NoCalibration"/>
    4 ParaChkWrong,  //! <Type Comment="Die Parameter-Checksumme ist falsch" Name="IO_FLAG.ParaChkWrong"/>
    5 PhysicHiLimit,  //! <Type Comment="IO ist am oberen physikalischen Limit" Name="IO_FLAG.PhysicHiLimit"/>
    6 PhysicLoLimit,  //! <Type Comment="IO ist am unteren physikalischen Limit" Name="IO_FLAG.PhysicLoLimit"/>
    7 Invert,  //! <Type Comment="Daten sind invertiert" Name="IO_FLAG.Invert"/>
    14 OnDummyMode,  //! <Type Comment="1 = Objekt ist im Dummymodus (nicht refreshed)" Name="IO_FLAG.OnDummyMode"/>
    15 NotConnected,  //! <Type Comment="1 = Objekt ist nicht verbunden" Name="IO_FLAG.NotConnected"/>
    16 PhysicAccessOff,  //! <Type Comment="1 = kein physikalischer Zugriff erlaubt" Name="IO_FLAG.PhysicAccessOff"/>
  ];
#pragma pack(push, 1)
  IO_State : STRUCT
    uiIO_Flags : IO_FLAG;
    uiChNo : UINT;
  END_STRUCT;
#pragma pack(pop)
  pHwBase : ^HwBase;
  pHwBaseCDIAS : ^HwBaseCDIAS;
  SafetyConfigStateType :
  (
    _ModuleNotFound,
    _SafetyClassOK,
    _ReinitConfig,
    _UnsafeVarNotFound,
    _ModFromCfgNotFound,
    _MemAllocFailed,
    _ReadFWVerFailed,
    _UnknownCfgError,
    _WaitForSynchronicity,
    _AsyncComError:=9,
    _DOsIncreasedRestartApp:=10,
    _LostPowerSupply:=11,
    _WrongSafetyHW:=12
  )$UDINT;
#pragma pack(push, 1)
  SafetyDiagInfo : STRUCT
    uControllerID : USINT;  //! <Type Comment="ID of �Controller (0 = �C1, else �C2)" Name="SafetyDiagInfo.uControllerID"/>
    ActErrorCode : USINT;  //! <Type Comment="actual error code" Name="SafetyDiagInfo.ActErrorCode"/>
    FirstErrorCode : USINT;  //! <Type Comment="code of first error that lead to an error state" Name="SafetyDiagInfo.FirstErrorCode"/>
    ReasonCode0 : UDINT;  //! <Type Comment="reason for error (meaning depends on actual error code)" Name="SafetyDiagInfo.ReasonCode0"/>
    ReasonCode1 : UDINT;  //! <Type Comment="reason for error (meaning depends on actual error code)" Name="SafetyDiagInfo.ReasonCode1"/>
  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
  SafetyDiagState : STRUCT
    RunState : USINT;  //! <Type Comment=" 1..POST&#13;&#10; 2..SERVICE&#13;&#10; 4..ERROR&#13;&#10; 8..IDLE&#13;&#10;16..CHK_CFG&#13;&#10;32..OP_TEMP&#13;&#10;64..OP" Name="SafetyDiagState.RunState"/>
    ConfigState : USINT;  //! <Type Comment=" 1..INVALID&#13;&#10; 2..NOT_CONFIGURED&#13;&#10; 4..CONFIGURED_NOT_DEPLOYED_NOT_VERIFIED&#13;&#10; 8..CONFIGURED_AND_VERIFIED&#13;&#10;16..CONFIGURED_DEPLOYED_NOT_VERIFIED&#13;&#10;36..CONFIGURED_NOT_DEPLOYED_NOT_VERIFIED_DEV&#13;&#10;48..CONFIGURED_DEPLOYED_NOT_VERIFIED_DEV" Name="SafetyDiagState.ConfigState"/>
    LoginLevel : USINT;  //! <Type Comment="0..not logged in&#13;&#10;1..debug&#13;&#10;2..configuration&#13;&#10;3..general" Name="SafetyDiagState.LoginLevel"/>
    ErrorCounterIOState : UINT;  //! <Type Comment="Is increased on change of the error state of any input or output" Name="SafetyDiagState.ErrorCounterIOState"/>
  END_STRUCT;
#pragma pack(pop)
  t_e_SafetyMemState :
  (
    _ALL_OK,  //! <Type Comment="all memory settings are valid" Name="t_e_SafetyMemState._ALL_OK"/>
    _NOT_ACTIVE,
    _ASY_MEM_NOT_EQUAL,
    _ISO_MEM_NOT_EQUAL,
    _ASY_WR_SIZE_TOO_HIGH,
    _ASY_RD_SIZE_TOO_HIGH,
    _ISO_WR_SIZE_TOO_HIGH,
    _ISO_RD_SIZE_TOO_HIGH,
    _ISO_WR_SIZE_TOO_SMALL,
    _ISO_RD_SIZE_TOO_SMALL,
    _ASY_WR_INSTALL_ERROR,
    _ASY_RD_INSTALL_ERROR,
    _ISO_WR_INSTALL_ERROR,
    _ISO_RD_INSTALL_ERROR
  )$DINT;
  t_e_VaranErrors :
  (
    _ClassOk,
    _NotInitialized,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._NotInitialized"/>
    _CallBackError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._CallBackError"/>
    _RequiredError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._RequiredError"/>
    _RootError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._RootError"/>
    _NoHardware,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._NoHardware"/>
    _WrongHardware,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._WrongHardware"/>
    _CreateDOFailed,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._CreateDOFailed"/>
    _DirectAccessFailed,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._DirectAccessFailed"/>
    _PllError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._PllError"/>
    _TimeoutInInit,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._TimeoutInInit"/>
    _HardwareRequiredIRQ,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._HardwareRequiredIRQ"/>
    _HardwareNotRequiredIRQ,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._HardwareNotRequiredIRQ"/>
    _HardwareFatalErrorIRQ,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._HardwareFatalErrorIRQ"/>
    _ManagerError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._ManagerError"/>
    _DisableError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._DisableError"/>
    _EnableError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._EnableError"/>
    _MultipleError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._MultipleError"/>
    _SPIError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._SPIError"/>
    _ErrorBootImageFPGA,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._ErrorBootImageFPGA"/>
    _NoCDIASInterface,  //! <Type Comment="for CIV class" Name="t_e_VaranErrors._NoCDIASInterface"/>
    _EEPromError,  //! <Type Comment="for CIV class" Name="t_e_VaranErrors._EEPromError"/>
    _NoVaranInterface,  //! <Type Comment="for VaranMaster" Name="t_e_VaranErrors._NoVaranInterface"/>
    _MemoryFault,  //! <Type Comment="for VaranMaster" Name="t_e_VaranErrors._MemoryFault"/>
    _TimesliceError,  //! <Type Comment="for VaranMaster" Name="t_e_VaranErrors._TimesliceError"/>
    _TimesliceErrorIRQ,  //! <Type Comment="for VaranMaster" Name="t_e_VaranErrors._TimesliceErrorIRQ"/>
    _WatchdogError,  //! <Type Comment="for VaranMaster" Name="t_e_VaranErrors._WatchdogError"/>
    _VaranTimeError,  //! <Type Comment="for HwControl class" Name="t_e_VaranErrors._VaranTimeError"/>
    _DiasTimeError,  //! <Type Comment="for HwControl class" Name="t_e_VaranErrors._DiasTimeError"/>
    _DORamFull,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._DORamFull"/>
    _PortNoLink,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._PortNoLink"/>
    _VaranDriverNotExists,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._VaranDriverNotExists"/>
    _WrongDOLType,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._WrongDOLType"/>
    _WrongRunStatus,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._WrongRunStatus"/>
    _DOHandleInvalid,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._DOHandleInvalid"/>
    _DOCmdInvalid,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._DOCmdInvalid"/>
    _ManagerNotExists,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._ManagerNotExists"/>
    _DOLAddressInvalid,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._DOLAddressInvalid"/>
    _UnknownCommand,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._UnknownCommand"/>
    _ComponentNotExists,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._ComponentNotExists"/>
    _ClientNotExists,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._ClientNotExists"/>
    _CdiasEEPromNotExists,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._CdiasEEPromNotExists"/>
    _CdiasEEPromNoGrant,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._CdiasEEPromNoGrant"/>
    _CdiasEEPromNack,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._CdiasEEPromNack"/>
    _PortNotExists,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._PortNotExists"/>
    _PortIsUplink,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._PortIsUplink"/>
    _NoMutex,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._NoMutex"/>
    _NoTask,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._NoTask"/>
    _IDNotFound,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._IDNotFound"/>
    _IDNotInitialized,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._IDNotInitialized"/>
    _InvalidDeviceAddress,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._InvalidDeviceAddress"/>
    _CallbackNotHandled,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._CallbackNotHandled"/>
    _NoMem,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._NoMem"/>
    _NoLegacyWd,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._NoLegacyWd"/>
    _AdminDOLExecutionError,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._AdminDOLExecutionError"/>
    _DADOLExecutionError,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._DADOLExecutionError"/>
    _SPIFlashNoAccess,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._SPIFlashNoAccess"/>
    _ClientNotready,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._ClientNotready"/>
    _TimeoutVaran,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._TimeoutVaran"/>
    _UnknownFault,  //! <Type Comment="from VaranManager" Name="t_e_VaranErrors._UnknownFault"/>
    _DiasError,  //! <Type Comment="for CIC/DIV with Dias" Name="t_e_VaranErrors._DiasError"/>
    _DeviceError,  //! <Type Comment="for Varan hardwareclasses" Name="t_e_VaranErrors._DeviceError"/>
    _VaranTimeWarning,
    _OnlyASYSupported,
    _InvalidSerialNo,
    _CDIASRequiredError,
    _DIASRequiredError,
    _NoCalibDataFound,
    _ModuleFoundButManagerIsOff:=68,
    _InvalidConfguration,
    _ClientDisabled,
    _ClientCantEnable,
    _CdiasAddressInvalid,
    _SPIFlashInvalid,
    _SPIDOLIDInvalid,
    _SPIDOLInvalid,
    _SPIRequiredListError,
    _SPIChksumError,
    _ParameterInvalid,
    _DOTypeNotSupported,
    _DMAError,
    _PropertyIDInvalid,
    _PropertyValueInvalid,
    _DONumberOverflow,
    _APIUsageNotAllowed,
    _NodeTypeWrong,
    _DataLengthInvalid,
    _DOTypeInvalid,
    _OperationNotAllowed,
    _NodeNumberOverflow,
    _NoHandleFound,
    _TopologyNotAllowed
  )$UDINT;
#pragma pack(push, 1)
  t_s_ModulInfo : STRUCT
    Kennung : HINT;
    p_This : ^void;
  END_STRUCT;
#pragma pack(pop)
END_TYPE
