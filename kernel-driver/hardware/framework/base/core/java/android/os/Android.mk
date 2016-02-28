#
# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

# We have a special case here where we build the library's resources
# independently from its code, so we need to find where the resource
# class source got placed in the course of building the resources.
# Thus, the magic here.
# Also, this module cannot depend directly on the R.java file; if it
# did, the PRIVATE_* vars for R.java wouldn't be guaranteed to be correct.
# Instead, it depends on the R.stamp file, which lists the corresponding
# R.java file as a prerequisite.
# TODO: find a more appropriate way to do this.
framework_res_source_path := APPS/framework-res_intermediates/src

# the library
# ============================================================
include $(CLEAR_VARS)

# FRAMEWORKS_BASE_SUBDIRS comes from build/core/pathmap.mk
LOCAL_SRC_FILES := $(call find-other-java-files,$(FRAMEWORKS_BASE_SUBDIRS))

# EventLogTags files.
LOCAL_SRC_FILES += \
       core/java/android/content/EventLogTags.logtags \
       core/java/android/speech/tts/EventLogTags.logtags \
       core/java/android/webkit/EventLogTags.logtags \

# The following filters out code we are temporarily not including at all.
# TODO: Move AWT and beans (and associated harmony code) back into libcore.
# TODO: Maybe remove javax.microedition entirely?
# TODO: Move SyncML (org.mobilecontrol.*) into its own library.

LOCAL_SRC_FILES := $(filter-out org/mobilecontrol/%, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out core/java/android/bluetooth/%, $(LOCAL_SRC_FILES))

## READ ME: ########################################################
##
## When updating this list of aidl files, consider if that aidl is
## part of the SDK API.  If it is, also add it to the list below that
## is preprocessed and distributed with the SDK.  This list should
## not contain any aidl files for parcelables, but the one below should
## if you intend for 3rd parties to be able to send those objects
## across process boundaries.
##
## READ ME: ########################################################
LOCAL_SRC_FILES += \
	core/java/android/accessibilityservice/IAccessibilityServiceConnection.aidl \
	core/java/android/accessibilityservice/IAccessibilityServiceClient.aidl \
	core/java/android/accounts/IAccountManager.aidl \
	core/java/android/accounts/IAccountManagerResponse.aidl \
	core/java/android/accounts/IAccountAuthenticator.aidl \
	core/java/android/accounts/IAccountAuthenticatorResponse.aidl \
	core/java/android/app/IActivityController.aidl \
	core/java/android/app/IActivityPendingResult.aidl \
	core/java/android/app/IAlarmManager.aidl \
	core/java/android/app/IBackupAgent.aidl \
	core/java/android/app/IInstrumentationWatcher.aidl \
	core/java/android/app/INotificationManager.aidl \
	core/java/android/app/IProcessObserver.aidl \
	core/java/android/app/ISearchManager.aidl \
	core/java/android/app/ISearchManagerCallback.aidl \
	core/java/android/app/IServiceConnection.aidl \
	core/java/android/app/IStopUserCallback.aidl \
	core/java/android/app/IThumbnailReceiver.aidl \
	core/java/android/app/IThumbnailRetriever.aidl \
	core/java/android/app/ITransientNotification.aidl \
	core/java/android/app/IUiModeManager.aidl \
	core/java/android/app/IUserSwitchObserver.aidl \
	core/java/android/app/IWallpaperManager.aidl \
	core/java/android/app/IWallpaperManagerCallback.aidl \
	core/java/android/app/admin/IDevicePolicyManager.aidl \
	core/java/android/app/backup/IBackupManager.aidl \
	core/java/android/app/backup/IFullBackupRestoreObserver.aidl \
	core/java/android/app/backup/IRestoreObserver.aidl \
	core/java/android/app/backup/IRestoreSession.aidl \
	core/java/android/content/IClipboard.aidl \
	core/java/android/content/IContentService.aidl \
	core/java/android/content/IIntentReceiver.aidl \
	core/java/android/content/IIntentSender.aidl \
	core/java/android/content/IOnPrimaryClipChangedListener.aidl \
	core/java/android/content/ISyncAdapter.aidl \
	core/java/android/content/ISyncContext.aidl \
	core/java/android/content/ISyncStatusObserver.aidl \
	core/java/android/content/pm/IPackageDataObserver.aidl \
	core/java/android/content/pm/IPackageDeleteObserver.aidl \
	core/java/android/content/pm/IPackageInstallObserver.aidl \
	core/java/android/content/pm/IPackageManager.aidl \
	core/java/android/content/pm/IPackageMoveObserver.aidl \
	core/java/android/content/pm/IPackageStatsObserver.aidl \
	core/java/android/database/IContentObserver.aidl \
	core/java/android/hardware/ISerialManager.aidl \
	core/java/android/hardware/display/IDisplayManager.aidl \
	core/java/android/hardware/display/IDisplayManagerCallback.aidl \
	core/java/android/hardware/input/IInputManager.aidl \
	core/java/android/hardware/input/IInputDevicesChangedListener.aidl \
	core/java/android/hardware/usb/IUsbManager.aidl \
	core/java/android/net/IConnectivityManager.aidl \
	core/java/android/net/INetworkManagementEventObserver.aidl \
	core/java/android/net/IThrottleManager.aidl \
	core/java/android/net/INetworkPolicyListener.aidl \
	core/java/android/net/INetworkPolicyManager.aidl \
	core/java/android/net/INetworkStatsService.aidl \
	core/java/android/net/INetworkStatsSession.aidl \
	core/java/android/net/nsd/INsdManager.aidl \
	core/java/android/nfc/INdefPushCallback.aidl \
	core/java/android/nfc/INfcAdapter.aidl \
	core/java/android/nfc/INfcAdapterExtras.aidl \
	core/java/android/nfc/INfcTag.aidl \
	core/java/android/os/ICancellationSignal.aidl \
	core/java/android/os/IHardwareService.aidl \
	core/java/android/os/IMessenger.aidl \
	core/java/android/os/INetworkManagementService.aidl \
	core/java/android/os/IPermissionController.aidl \
	core/java/android/os/IPowerManager.aidl \
	core/java/android/os/IRemoteCallback.aidl \
	core/java/android/os/ISchedulingPolicyService.aidl \
	core/java/android/os/IUpdateLock.aidl \
	core/java/android/os/IUserManager.aidl \
	core/java/android/os/IVibratorService.aidl \
	core/java/android/service/dreams/IDreamManager.aidl \
	core/java/android/service/dreams/IDreamService.aidl \
	core/java/android/service/wallpaper/IWallpaperConnection.aidl \
	core/java/android/service/wallpaper/IWallpaperEngine.aidl \
	core/java/android/service/wallpaper/IWallpaperService.aidl \
	core/java/android/view/accessibility/IAccessibilityInteractionConnection.aidl\
	core/java/android/view/accessibility/IAccessibilityInteractionConnectionCallback.aidl\
	core/java/android/view/accessibility/IAccessibilityManager.aidl \
	core/java/android/view/accessibility/IAccessibilityManagerClient.aidl \
	core/java/android/view/IApplicationToken.aidl \
	core/java/android/view/IDisplayContentChangeListener.aidl \
	core/java/android/view/IInputFilter.aidl \
	core/java/android/view/IInputFilterHost.aidl \
	core/java/android/view/IOnKeyguardExitResult.aidl \
	core/java/android/view/IRotationWatcher.aidl \
	core/java/android/view/IWindow.aidl \
	core/java/android/view/IWindowManager.aidl \
	core/java/android/view/IWindowSession.aidl \
	core/java/android/speech/IRecognitionListener.aidl \
	core/java/android/speech/IRecognitionService.aidl \
	core/java/android/speech/tts/ITextToSpeechCallback.aidl \
	core/java/android/speech/tts/ITextToSpeechService.aidl \
	core/java/com/android/internal/app/IBatteryStats.aidl \
	core/java/com/android/internal/app/IUsageStats.aidl \
	core/java/com/android/internal/app/IMediaContainerService.aidl \
	core/java/com/android/internal/appwidget/IAppWidgetService.aidl \
	core/java/com/android/internal/appwidget/IAppWidgetHost.aidl \
	core/java/com/android/internal/backup/IBackupTransport.aidl \
	core/java/com/android/internal/policy/IFaceLockCallback.aidl \
	core/java/com/android/internal/policy/IFaceLockInterface.aidl \
	core/java/com/android/internal/os/IDropBoxManagerService.aidl \
	core/java/com/android/internal/os/IResultReceiver.aidl \
	../../autochips/frameworks/base/core/java/com/android/internal/statusbar/IStatusBar.aidl \
	../../autochips/frameworks/base/core/java/com/android/internal/statusbar/IStatusBarService.aidl \
	core/java/com/android/internal/textservice/ISpellCheckerService.aidl \
	core/java/com/android/internal/textservice/ISpellCheckerSession.aidl \
	core/java/com/android/internal/textservice/ISpellCheckerSessionListener.aidl \
	core/java/com/android/internal/textservice/ITextServicesManager.aidl \
	core/java/com/android/internal/textservice/ITextServicesSessionListener.aidl \
	core/java/com/android/internal/view/IInputContext.aidl \
	core/java/com/android/internal/view/IInputContextCallback.aidl \
	core/java/com/android/internal/view/IInputMethod.aidl \
	core/java/com/android/internal/view/IInputMethodCallback.aidl \
	core/java/com/android/internal/view/IInputMethodClient.aidl \
	core/java/com/android/internal/view/IInputMethodManager.aidl \
	core/java/com/android/internal/view/IInputMethodSession.aidl \
	core/java/com/android/internal/widget/ILockSettings.aidl \
	core/java/com/android/internal/widget/IRemoteViewsFactory.aidl \
	core/java/com/android/internal/widget/IRemoteViewsAdapterConnection.aidl \
	//gudh modify
	core/java/com/android/internal/widget/IHelloService.aidl \
	//gudh modify
	keystore/java/android/security/IKeyChainAliasCallback.aidl \
	keystore/java/android/security/IKeyChainService.aidl \
	location/java/android/location/ICountryDetector.aidl \
	location/java/android/location/ICountryListener.aidl \
	location/java/android/location/IGeocodeProvider.aidl \
	location/java/android/location/IGpsStatusListener.aidl \
	location/java/android/location/IGpsStatusProvider.aidl \
	location/java/android/location/ILocationListener.aidl \
	location/java/android/location/ILocationManager.aidl \
	location/java/android/location/INetInitiatedListener.aidl \
	location/java/com/android/internal/location/ILocationProvider.aidl \
	../../autochips/frameworks/base/media/java/android/media/IAudioService.aidl \
	media/java/android/media/IAudioFocusDispatcher.aidl \
	media/java/android/media/IAudioRoutesObserver.aidl \
	media/java/android/media/IMediaScannerListener.aidl \
	media/java/android/media/IMediaScannerService.aidl \
	media/java/android/media/IRemoteControlClient.aidl \
	media/java/android/media/IRemoteControlDisplay.aidl \
	media/java/android/media/IRemoteVolumeObserver.aidl \
	media/java/android/media/IRingtonePlayer.aidl \
	telephony/java/com/android/internal/telephony/IPhoneStateListener.aidl \
	telephony/java/com/android/internal/telephony/IPhoneSubInfo.aidl \
	telephony/java/com/android/internal/telephony/ITelephony.aidl \
	telephony/java/com/android/internal/telephony/ITelephonyRegistry.aidl \
	telephony/java/com/android/internal/telephony/IWapPushManager.aidl \
	../../autochips/frameworks/base/telephony/java/com/android/internal/telephony/IExtendedNetworkService.aidl \
	wifi/java/android/net/wifi/IWifiManager.aidl \
	wifi/java/android/net/wifi/p2p/IWifiP2pManager.aidl \
	voip/java/android/net/sip/ISipSession.aidl \
	voip/java/android/net/sip/ISipSessionListener.aidl \
	voip/java/android/net/sip/ISipService.aidl
#


## READ ME: ########################################################
##
## Add autochips added java file.
##
## READ ME: ########################################################
LOCAL_SRC_FILES := $(filter-out core/java/android/os/RecoverySystem.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out core/java/android/os/Environment.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out media/java/android/media/MediaFile.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out media/java/android/media/MediaScanner.java, $(LOCAL_SRC_FILES))

LOCAL_SRC_FILES += \
	../../autochips/frameworks/base/core/java/android/os/FscManager.java \
	../../autochips/frameworks/base/core/java/android/os/RecoverySystem.java \
	../../autochips/frameworks/base/core/java/android/os/Environment.java \
	../../autochips/frameworks/base/media/java/android/media/MediaFile.java \
	../../autochips/frameworks/base/media/java/android/media/MediaScanner.java \
	../../autochips/frameworks/base/core/java/android/os/EnvironmentATC.java 
	
LOCAL_SRC_FILES += \
	../../autochips/frameworks/base/core/java/android/os/IFscService.aidl

LOCAL_SRC_FILES := $(filter-out core/java/android/provider/Settings.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/provider/Settings.java

LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/com/android/internal/os/BootProf.java

LOCAL_SRC_FILES := $(filter-out core/java/android/app/ContextImpl.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/app/ContextImpl.java

LOCAL_SRC_FILES := $(filter-out core/java/android/app/StatusBarManager.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/app/StatusBarManager.java

LOCAL_SRC_FILES := $(filter-out core/java/android/content/Context.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/content/Context.java

LOCAL_SRC_FILES := $(filter-out core/java/android/content/Intent.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/content/Intent.java

LOCAL_SRC_FILES := $(filter-out core/java/android/widget/ProgressBar.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/widget/ProgressBar.java

LOCAL_SRC_FILES := $(filter-out media/java/android/media/AudioManager.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/media/java/android/media/AudioManager.java
LOCAL_SRC_FILES := $(filter-out media/java/android/media/AudioService.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/media/java/android/media/AudioService.java
LOCAL_SRC_FILES := $(filter-out media/java/android/media/AudioSystem.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/media/java/android/media/AudioSystem.java
LOCAL_SRC_FILES := $(filter-out media/java/android/media/AudioTrack.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/media/java/android/media/AudioTrack.java

LOCAL_SRC_FILES := $(filter-out media/java/android/media/MediaPlayer.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/media/java/android/media/MediaPlayer.java

LOCAL_SRC_FILES := $(filter-out media/java/android/media/TimedText.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/media/java/android/media/TimedText.java

LOCAL_SRC_FILES := $(filter-out core/java/android/webkit/HTML5VideoView.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/webkit/HTML5VideoView.java
LOCAL_SRC_FILES := $(filter-out core/java/android/webkit/HTML5VideoViewProxy.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/webkit/HTML5VideoViewProxy.java

LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/WifiStateMachine.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/wifi/java/android/net/wifi/WifiStateMachine.java

LOCAL_SRC_FILES := $(filter-out core/java/android/app/backup/WallpaperBackupHelper.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/app/backup/WallpaperBackupHelper.java

LOCAL_SRC_FILES := $(filter-out core/java/android/content/SyncStorageEngine.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/android/content/SyncStorageEngine.java

LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/WifiApConfigStore.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/wifi/java/android/net/wifi/WifiApConfigStore.java

LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/WifiManager.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/wifi/java/android/net/wifi/WifiManager.java

LOCAL_SRC_FILES := $(filter-out core/java/com/android/internal/util/FileRotator.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/com/android/internal/util/FileRotator.java

LOCAL_SRC_FILES := $(filter-out core/java/com/android/internal/widget/LockSettingsService.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES += ../../autochips/frameworks/base/core/java/com/android/internal/widget/LockSettingsService.java
###inputsource#
MTK_INPUTSOURCE_PATH := ../../autochips/frameworks/base/core/java/android/inputsource
MTK_INPUTSOURCE_SERVER_PATH := ../../autochips/frameworks/base/services/java/com/android/server/inputsource

LOCAL_SRC_FILES += \
        $(MTK_INPUTSOURCE_PATH)/IInputSourceClient.aidl \
        $(MTK_INPUTSOURCE_PATH)/IInputSourceBase.aidl \
        $(MTK_INPUTSOURCE_PATH)/IInputSourceService.aidl 

LOCAL_SRC_FILES += $(call find-other-java-files,$(MTK_INPUTSOURCE_PATH))
#LOCAL_SRC_FILES += $(call find-other-java-files,$(MTK_INPUTSOURCE_SERVER_PATH))

###dvp#
##ATC_DVPSERVICE_PATH := ../../autochips/frameworks/base/core/java/com/autochips/dvp
##LOCAL_SRC_FILES += $(call find-other-java-files,$(ATC_DVPSERVICE_PATH))

###dvp#
ATC_DVP_PATH := ../../autochips/frameworks/base/core/java/android/dvp
ATC_DVP_SERVER_PATH := ../../autochips/frameworks/base/services/java/com/android/server/dvp

LOCAL_SRC_FILES += \
        $(ATC_DVP_PATH)/IDvdManagerBase.aidl \
        $(ATC_DVP_PATH)/IDvdManagerClient.aidl \
        $(ATC_DVP_PATH)/IDvdManagerService.aidl 

LOCAL_SRC_FILES += $(call find-other-java-files,$(ATC_DVP_PATH))
#LOCAL_SRC_FILES += $(call find-other-java-files,$(ATC_DVP_SERVER_PATH))

##whitelist#
LOCAL_SRC_FILES += \
	../../autochips/frameworks/base/core/java/com/autochips/whitelist/WhiteList.java 
	
# CBM
LOCAL_SRC_FILES += \
	../../autochips/frameworks/base/core/java/android/cbm/CBManager.java \
	../../autochips/frameworks/base/core/java/android/cbm/ICBMService.aidl \
	../../autochips/frameworks/base/core/java/android/cbm/ICBMClient.aidl


## wifi display
LOCAL_SRC_FILES := $(filter-out core/java/android/hardware/display/DisplayManager.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out core/java/android/hardware/display/DisplayManagerGlobal.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out core/java/android/hardware/display/WifiDisplayStatus.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out media/java/android/media/RemoteDisplay.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/WifiNative.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/p2p/WifiP2pDevice.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/p2p/WifiP2pManager.java, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/p2p/WifiP2pService.java, $(LOCAL_SRC_FILES))

LOCAL_SRC_FILES := $(filter-out core/java/android/hardware/display/IDisplayManager.aidl, $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(filter-out wifi/java/android/net/wifi/p2p/IWifiP2pManager.aidl, $(LOCAL_SRC_FILES))

LOCAL_SRC_FILES += \
	../../autochips/frameworks/base/core/java/android/hardware/display/DisplayManager.java \
	../../autochips/frameworks/base/core/java/android/hardware/display/DisplayManagerGlobal.java \
	../../autochips/frameworks/base/core/java/android/hardware/display/WifiDisplayStatus.java \
	../../autochips/frameworks/base/media/java/android/media/RemoteDisplay.java \
	../../autochips/frameworks/base/wifi/java/android/net/wifi/WifiNative.java \
	../../autochips/frameworks/base/wifi/java/android/net/wifi/p2p/WifiP2pDevice.java \
	../../autochips/frameworks/base/wifi/java/android/net/wifi/p2p/WifiP2pManager.java \
	../../autochips/frameworks/base/wifi/java/android/net/wifi/p2p/WifiP2pService.java \
	../../autochips/frameworks/base/core/java/android/hardware/display/IDisplayManager.aidl \
	../../autochips/frameworks/base/wifi/java/android/net/wifi/p2p/IWifiP2pManager.aidl

## READ ME: ########################################################
##
## Add autochips Bluetooth java file and aidl file
##
## READ ME: ########################################################
MTK_BASE_PATH := ../../autochips/frameworks/base
MTK_BT_JAVA_PATH := $(MTK_BASE_PATH)/core/java/android/bluetooth
LOCAL_SRC_FILES += $(call find-other-java-files,$(MTK_BT_JAVA_PATH))

LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothA2dpService.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothAdapterProperties.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothAdapterStateMachine.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothBondState.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothDeviceProperties.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothEventLoop.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothHealthProfileHandler.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothInputProfileHandler.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothPanProfileHandler.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothProfileManagerService.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothService.java
LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/android/server/BluetoothSocketService.java

LOCAL_SRC_FILES += $(MTK_BASE_PATH)/core/java/com/autochips/bluetooth/service/BluetoothPrxmDevice.java

LOCAL_SRC_FILES += \
        $(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetooth.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothA2dp.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothA2dpSink.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothAvrcpCt.aidl \
        $(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothDunDt.aidl \
 	$(MTK_BASE_PATH)/core/java/android/bluetooth/IDunCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothHf.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothHeadset.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothHealthCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothPbap.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothPbapCall.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothPbapClient.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IPBCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothStateChangeCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothProfileManager.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothSocket.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothBipi.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothBipr.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothBpp.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothDun.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothFtpCtrl.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothFtpServer.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothFtpServerCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothSimap.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothSimapCallback.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothMap.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothOpp.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothHid.aidl \
	$(MTK_BASE_PATH)/core/java/android/bluetooth/IBluetoothPan.aidl \
	$(MTK_BASE_PATH)/core/java/com/autochips/bluetooth/service/IBluetoothPrxm.aidl \
	$(MTK_BASE_PATH)/core/java/com/autochips/bluetooth/service/IBluetoothPrxr.aidl \

aidl_files += \
	$(MTK_BASE_PATH)/core/java/com/autochips/bluetooth/service/BluetoothPrxmDevice.aidl \
	$(MTK_BASE_PATH)/core/java/com/autochips/bluetooth/service/BluetoothSocket.aidl \

# FRAMEWORKS_BASE_JAVA_SRC_DIRS comes from build/core/pathmap.mk
LOCAL_AIDL_INCLUDES += autochips/frameworks/base/core/java
LOCAL_AIDL_INCLUDES += $(FRAMEWORKS_BASE_JAVA_SRC_DIRS)

LOCAL_INTERMEDIATE_SOURCES := \
			$(framework_res_source_path)/android/R.java \
			$(framework_res_source_path)/android/Manifest.java \
			$(framework_res_source_path)/com/android/internal/R.java

LOCAL_NO_STANDARD_LIBRARIES := true
LOCAL_JAVA_LIBRARIES := bouncycastle core core-junit ext

LOCAL_MODULE := framework
LOCAL_MODULE_CLASS := JAVA_LIBRARIES

# List of classes and interfaces which should be loaded by the Zygote.
LOCAL_JAVA_RESOURCE_FILES += $(LOCAL_PATH)/preloaded-classes

#LOCAL_JARJAR_RULES := $(LOCAL_PATH)/jarjar-rules.txt

LOCAL_DX_FLAGS := --core-library

include $(BUILD_JAVA_LIBRARY)

# Make sure that R.java and Manifest.java are built before we build
# the source for this library.
framework_res_R_stamp := \
	$(call intermediates-dir-for,APPS,framework-res,,COMMON)/src/R.stamp
$(full_classes_compiled_jar): $(framework_res_R_stamp)

# Make sure that framework-res is installed when framework is.
$(LOCAL_INSTALLED_MODULE): | $(dir $(LOCAL_INSTALLED_MODULE))framework-res.apk

framework_built := $(call java-lib-deps,framework)

# AIDL files to be preprocessed and included in the SDK,
# relative to the root of the build tree.
# ============================================================
aidl_files := \
	frameworks/base/core/java/android/accounts/IAccountManager.aidl \
	frameworks/base/core/java/android/accounts/IAccountManagerResponse.aidl \
	frameworks/base/core/java/android/accounts/IAccountAuthenticator.aidl \
	frameworks/base/core/java/android/accounts/IAccountAuthenticatorResponse.aidl \
	frameworks/base/core/java/android/app/Notification.aidl \
	frameworks/base/core/java/android/app/PendingIntent.aidl \
	autochips/frameworks/base/core/java/android/bluetooth/BluetoothDevice.aidl \
	autochips/frameworks/base/core/java/android/bluetooth/BluetoothHealthAppConfiguration.aidl \
	frameworks/base/core/java/android/content/ComponentName.aidl \
	frameworks/base/core/java/android/content/Intent.aidl \
	frameworks/base/core/java/android/content/IntentSender.aidl \
	frameworks/base/core/java/android/content/PeriodicSync.aidl \
	frameworks/base/core/java/android/content/SyncStats.aidl \
	frameworks/base/core/java/android/content/res/Configuration.aidl \
	frameworks/base/core/java/android/appwidget/AppWidgetProviderInfo.aidl \
	frameworks/base/core/java/android/net/Uri.aidl \
	frameworks/base/core/java/android/nfc/NdefMessage.aidl \
	frameworks/base/core/java/android/nfc/NdefRecord.aidl \
	frameworks/base/core/java/android/nfc/Tag.aidl \
	frameworks/base/core/java/android/os/Bundle.aidl \
	frameworks/base/core/java/android/os/DropBoxManager.aidl \
	frameworks/base/core/java/android/os/ParcelFileDescriptor.aidl \
	frameworks/base/core/java/android/os/ParcelUuid.aidl \
	frameworks/base/core/java/android/view/KeyEvent.aidl \
	frameworks/base/core/java/android/view/MotionEvent.aidl \
	frameworks/base/core/java/android/view/Surface.aidl \
	frameworks/base/core/java/android/view/WindowManager.aidl \
	frameworks/base/core/java/android/widget/RemoteViews.aidl \
	frameworks/base/core/java/com/android/internal/textservice/ISpellCheckerService.aidl \
	frameworks/base/core/java/com/android/internal/textservice/ISpellCheckerSession.aidl \
	frameworks/base/core/java/com/android/internal/textservice/ISpellCheckerSessionListener.aidl \
	frameworks/base/core/java/com/android/internal/textservice/ITextServicesManager.aidl \
	frameworks/base/core/java/com/android/internal/textservice/ITextServicesSessionListener.aidl \
	frameworks/base/core/java/com/android/internal/view/IInputContext.aidl \
	frameworks/base/core/java/com/android/internal/view/IInputMethod.aidl \
	frameworks/base/core/java/com/android/internal/view/IInputMethodCallback.aidl \
	frameworks/base/core/java/com/android/internal/view/IInputMethodClient.aidl \
	frameworks/base/core/java/com/android/internal/view/IInputMethodManager.aidl \
	frameworks/base/core/java/com/android/internal/view/IInputMethodSession.aidl \
	frameworks/base/graphics/java/android/graphics/Bitmap.aidl \
	frameworks/base/graphics/java/android/graphics/Rect.aidl \
	frameworks/base/graphics/java/android/graphics/Region.aidl \
	frameworks/base/location/java/android/location/Criteria.aidl \
	frameworks/base/location/java/android/location/Geofence.aidl \
	frameworks/base/location/java/android/location/Location.aidl \
	frameworks/base/location/java/android/location/LocationRequest.aidl \
	frameworks/base/location/java/com/android/internal/location/ProviderProperties.aidl \
	frameworks/base/location/java/com/android/internal/location/ProviderRequest.aidl \
	frameworks/base/telephony/java/android/telephony/ServiceState.aidl \
	frameworks/base/telephony/java/com/android/internal/telephony/IPhoneSubInfo.aidl \
	frameworks/base/telephony/java/com/android/internal/telephony/ITelephony.aidl \

gen := $(TARGET_OUT_COMMON_INTERMEDIATES)/framework.aidl
$(gen): PRIVATE_SRC_FILES := $(aidl_files)
ALL_SDK_FILES += $(gen)
$(gen): $(aidl_files) | $(AIDL)
		@echo Aidl Preprocess: $@
		$(hide) $(AIDL) --preprocess $@ $(PRIVATE_SRC_FILES)

# the documentation
# ============================================================

# TODO: deal with com/google/android/googleapps
packages_to_document := \
	android \
	javax/microedition/khronos

# Search through the base framework dirs for these packages.
# The result will be relative to frameworks/base.
fwbase_dirs_to_document := \
	test-runner/src \
	$(patsubst $(LOCAL_PATH)/%,%, \
	  $(wildcard \
	    $(foreach dir, $(FRAMEWORKS_BASE_JAVA_SRC_DIRS), \
	      $(addprefix $(dir)/, $(packages_to_document)) \
	     ) \
	   ) \
	 )

# include definition of libcore_to_document
include libcore/Docs.mk

# include definition of junit_to_document
include external/junit/Common.mk

non_base_dirs := \
	../../external/apache-http/src/org/apache/http \
	../opt/telephony/src/java/android/telephony \
	../opt/telephony/src/java/android/telephony/gsm \

# These are relative to frameworks/base
dirs_to_check_apis := \
  $(fwbase_dirs_to_document) \
	$(non_base_dirs)

# These are relative to frameworks/base
# FRAMEWORKS_BASE_SUBDIRS comes from build/core/pathmap.mk
dirs_to_document := \
	$(dirs_to_check_apis) \
  $(addprefix ../../, $(FRAMEWORKS_SUPPORT_JAVA_SRC_DIRS))

# These are relative to frameworks/base
html_dirs := \
	$(FRAMEWORKS_BASE_SUBDIRS) \
	$(non_base_dirs)

# Common sources for doc check and api check
common_src_files := \
	$(call find-other-html-files, $(html_dirs)) \
	$(addprefix ../../libcore/, $(call libcore_to_document, $(LOCAL_PATH)/../../libcore)) \
	$(addprefix ../../external/junit/, $(call junit_to_document, $(LOCAL_PATH)/../../external/junit))

# These are relative to frameworks/base
framework_docs_LOCAL_SRC_FILES := \
	$(call find-other-java-files, $(dirs_to_document)) \
	$(common_src_files)

# These are relative to frameworks/base
framework_docs_LOCAL_API_CHECK_SRC_FILES := \
	$(call find-other-java-files, $(dirs_to_check_apis)) \
	$(common_src_files)

# This is used by ide.mk as the list of source files that are
# always included.
INTERNAL_SDK_SOURCE_DIRS := $(addprefix $(LOCAL_PATH)/,$(dirs_to_document))

framework_docs_LOCAL_DROIDDOC_SOURCE_PATH := \
	$(FRAMEWORKS_BASE_JAVA_SRC_DIRS)

framework_docs_LOCAL_INTERMEDIATE_SOURCES := \
			$(framework_res_source_path)/android/R.java \
			$(framework_res_source_path)/android/Manifest.java \
			$(framework_res_source_path)/com/android/internal/R.java

framework_docs_LOCAL_JAVA_LIBRARIES := \
			bouncycastle \
			core \
			ext \
			framework \
			mms-common \
			telephony-common \

framework_docs_LOCAL_MODULE_CLASS := JAVA_LIBRARIES
framework_docs_LOCAL_DROIDDOC_HTML_DIR := docs/html
# The since flag (-since N.xml API_LEVEL) is used to add API Level information
# to the reference documentation. Must be in order of oldest to newest.
framework_docs_LOCAL_DROIDDOC_OPTIONS := \
    -knowntags ./frameworks/base/docs/knowntags.txt \
    -since ./frameworks/base/api/1.xml 1 \
    -since ./frameworks/base/api/2.xml 2 \
    -since ./frameworks/base/api/3.xml 3 \
    -since ./frameworks/base/api/4.xml 4 \
    -since ./frameworks/base/api/5.xml 5 \
    -since ./frameworks/base/api/6.xml 6 \
    -since ./frameworks/base/api/7.xml 7 \
    -since ./frameworks/base/api/8.xml 8 \
    -since ./frameworks/base/api/9.xml 9 \
    -since ./frameworks/base/api/10.xml 10 \
    -since ./frameworks/base/api/11.xml 11 \
    -since ./frameworks/base/api/12.xml 12 \
    -since ./frameworks/base/api/13.xml 13 \
    -since ./frameworks/base/api/14.txt 14 \
    -since ./frameworks/base/api/15.txt 15 \
    -since ./frameworks/base/api/16.txt 16 \
    -since ./frameworks/base/api/17.txt 17 \
		-werror -hide 113 \
		-overview $(LOCAL_PATH)/core/java/overview.html

framework_docs_LOCAL_ADDITIONAL_JAVA_DIR:= $(call intermediates-dir-for,JAVA_LIBRARIES,framework,,COMMON)

framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES := \
    frameworks/base/docs/knowntags.txt

sample_dir := development/samples

# the list here should match the list of samples included in the sdk samples package
# (see development/build/sdk.atree)
# remove htmlified samples for now -- samples are still available through the SDK
# web_docs_sample_code_flags := \
		-hdf android.hasSamples 1 \
		-samplecode $(sample_dir)/AccelerometerPlay \
		            resources/samples/AccelerometerPlay "Accelerometer Play" \
		-samplecode $(sample_dir)/ActionBarCompat \
		            resources/samples/ActionBarCompat "Action Bar Compatibility" \
                -samplecode $(sample_dir)/AndroidBeamDemo \
		            resources/samples/AndroidBeamDemo "Android Beam Demo" \
		-samplecode $(sample_dir)/ApiDemos \
		            resources/samples/ApiDemos "API Demos" \
		-samplecode $(sample_dir)/Support4Demos \
		            resources/samples/Support4Demos "API 4+ Support Demos" \
		-samplecode $(sample_dir)/Support13Demos \
		            resources/samples/Support13Demos "API 13+ Support Demos" \
		-samplecode $(sample_dir)/BackupRestore \
		            resources/samples/BackupRestore "Backup and Restore" \
		-samplecode $(sample_dir)/BluetoothChat \
		            resources/samples/BluetoothChat "Bluetooth Chat" \
		-samplecode $(sample_dir)/BluetoothHDP \
		            resources/samples/BluetoothHDP "Bluetooth HDP Demo" \
		-samplecode $(sample_dir)/BusinessCard \
		            resources/samples/BusinessCard "Business Card" \
		-samplecode $(sample_dir)/ContactManager \
		            resources/samples/ContactManager "Contact Manager" \
		-samplecode $(sample_dir)/CubeLiveWallpaper \
		            resources/samples/CubeLiveWallpaper "Cube Live Wallpaper" \
		-samplecode $(sample_dir)/Home \
		            resources/samples/Home "Home" \
		-samplecode $(sample_dir)/HoneycombGallery \
		            resources/samples/HoneycombGallery "Honeycomb Gallery" \
		-samplecode $(sample_dir)/JetBoy \
		            resources/samples/JetBoy "JetBoy" \
		-samplecode $(sample_dir)/KeyChainDemo \
		            resources/samples/KeyChainDemo "KeyChain Demo" \
		-samplecode $(sample_dir)/LunarLander \
		            resources/samples/LunarLander "Lunar Lander" \
		-samplecode $(sample_dir)/training/ads-and-ux \
		            resources/samples/training/ads-and-ux "Mobile Advertisement Integration" \
		-samplecode $(sample_dir)/MultiResolution \
		            resources/samples/MultiResolution "Multiple Resolutions" \
		-samplecode $(sample_dir)/training/multiscreen/newsreader \
		            resources/samples/newsreader "News Reader" \
		-samplecode $(sample_dir)/NotePad \
		            resources/samples/NotePad "Note Pad" \
		-samplecode $(sample_dir)/SpellChecker/SampleSpellCheckerService \
		            resources/samples/SpellChecker/SampleSpellCheckerService "Spell Checker Service" \
		-samplecode $(sample_dir)/SpellChecker/HelloSpellChecker \
		            resources/samples/SpellChecker/HelloSpellChecker "Spell Checker Client" \
		-samplecode $(sample_dir)/SampleSyncAdapter \
		            resources/samples/SampleSyncAdapter "Sample Sync Adapter" \
		-samplecode $(sample_dir)/RandomMusicPlayer \
		            resources/samples/RandomMusicPlayer "Random Music Player" \
		-samplecode $(sample_dir)/RenderScript \
		            resources/samples/RenderScript "RenderScript" \
		-samplecode $(sample_dir)/SearchableDictionary \
		            resources/samples/SearchableDictionary "Searchable Dictionary v2" \
		-samplecode $(sample_dir)/SipDemo \
		            resources/samples/SipDemo "SIP Demo" \
		-samplecode $(sample_dir)/Snake \
		            resources/samples/Snake "Snake" \
		-samplecode $(sample_dir)/SoftKeyboard \
		            resources/samples/SoftKeyboard "Soft Keyboard" \
		-samplecode $(sample_dir)/Spinner  \
		            resources/samples/Spinner "Spinner" \
		-samplecode $(sample_dir)/SpinnerTest \
		            resources/samples/SpinnerTest "SpinnerTest" \
		-samplecode $(sample_dir)/StackWidget \
		            resources/samples/StackWidget "StackView Widget" \
		-samplecode $(sample_dir)/TicTacToeLib  \
		            resources/samples/TicTacToeLib "TicTacToeLib" \
		-samplecode $(sample_dir)/TicTacToeMain \
		            resources/samples/TicTacToeMain "TicTacToeMain" \
		-samplecode $(sample_dir)/ToyVpn \
		            resources/samples/ToyVpn "Toy VPN Client" \
		-samplecode $(sample_dir)/USB \
		            resources/samples/USB "USB" \
		-samplecode $(sample_dir)/WeatherListWidget \
		            resources/samples/WeatherListWidget "Weather List Widget" \
		-samplecode $(sample_dir)/WiFiDirectDemo \
                            resources/samples/WiFiDirectDemo "Wi-Fi Direct Demo" \
		-samplecode $(sample_dir)/Wiktionary \
		            resources/samples/Wiktionary "Wiktionary" \
		-samplecode $(sample_dir)/WiktionarySimple \
		            resources/samples/WiktionarySimple "Wiktionary (Simplified)" \
		-samplecode $(sample_dir)/VoiceRecognitionService \
		            resources/samples/VoiceRecognitionService "Voice Recognition Service" \
		-samplecode $(sample_dir)/VoicemailProviderDemo \
		            resources/samples/VoicemailProviderDemo "Voicemail Provider Demo" \
		-samplecode $(sample_dir)/XmlAdapters \
		            resources/samples/XmlAdapters "XML Adapters" \
		-samplecode $(sample_dir)/TtsEngine \
		            resources/samples/TtsEngine "Text To Speech Engine" \
		-samplecode $(sample_dir)/training/device-management-policy \
		            resources/samples/training/device-management-policy "Device Management Policy"


## SDK version identifiers used in the published docs
  # major[.minor] version for current SDK. (full releases only)
framework_docs_SDK_VERSION:=4.2
  # release version (ie "Release x")  (full releases only)
framework_docs_SDK_REL_ID:=1

framework_docs_LOCAL_DROIDDOC_OPTIONS += \
		-hdf sdk.version $(framework_docs_SDK_VERSION) \
		-hdf sdk.rel.id $(framework_docs_SDK_REL_ID) \
		-hdf sdk.preview 0 \

# ====  the api stubs and current.xml ===========================
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=$(framework_docs_LOCAL_API_CHECK_SRC_FILES)
LOCAL_INTERMEDIATE_SOURCES:=$(framework_docs_LOCAL_INTERMEDIATE_SOURCES)
LOCAL_JAVA_LIBRARIES:=$(framework_docs_LOCAL_JAVA_LIBRARIES)
LOCAL_MODULE_CLASS:=$(framework_docs_LOCAL_MODULE_CLASS)
LOCAL_DROIDDOC_SOURCE_PATH:=$(framework_docs_LOCAL_DROIDDOC_SOURCE_PATH)
LOCAL_DROIDDOC_HTML_DIR:=$(framework_docs_LOCAL_DROIDDOC_HTML_DIR)
LOCAL_ADDITIONAL_JAVA_DIR:=$(framework_docs_LOCAL_ADDITIONAL_JAVA_DIR)
LOCAL_ADDITIONAL_DEPENDENCIES:=$(framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES)

LOCAL_MODULE := api-stubs

LOCAL_DROIDDOC_OPTIONS:=\
		$(framework_docs_LOCAL_DROIDDOC_OPTIONS) \
		-stubs $(TARGET_OUT_COMMON_INTERMEDIATES)/JAVA_LIBRARIES/android_stubs_current_intermediates/src \
		-api $(INTERNAL_PLATFORM_API_FILE) \
		-nodocs

LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR:=build/tools/droiddoc/templates-sdk

LOCAL_UNINSTALLABLE_MODULE := true

include $(BUILD_DROIDDOC)

# $(gen), i.e. framework.aidl, is also needed while building against the current stub.
$(full_target): $(framework_built) $(gen)
$(INTERNAL_PLATFORM_API_FILE): $(full_target)
$(call dist-for-goals,sdk,$(INTERNAL_PLATFORM_API_FILE))

# ====  check javadoc comments but don't generate docs ========
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=$(framework_docs_LOCAL_SRC_FILES)
LOCAL_INTERMEDIATE_SOURCES:=$(framework_docs_LOCAL_INTERMEDIATE_SOURCES)
LOCAL_JAVA_LIBRARIES:=$(framework_docs_LOCAL_JAVA_LIBRARIES)
LOCAL_MODULE_CLASS:=$(framework_docs_LOCAL_MODULE_CLASS)
LOCAL_DROIDDOC_SOURCE_PATH:=$(framework_docs_LOCAL_DROIDDOC_SOURCE_PATH)
LOCAL_DROIDDOC_HTML_DIR:=$(framework_docs_LOCAL_DROIDDOC_HTML_DIR)
LOCAL_ADDITIONAL_JAVA_DIR:=$(framework_docs_LOCAL_ADDITIONAL_JAVA_DIR)
LOCAL_ADDITIONAL_DEPENDENCIES:=$(framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES)

LOCAL_MODULE := doc-comment-check

LOCAL_DROIDDOC_OPTIONS:=\
		$(framework_docs_LOCAL_DROIDDOC_OPTIONS) \
		-parsecomments

LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR:=build/tools/droiddoc/templates-sdk

LOCAL_UNINSTALLABLE_MODULE := true

include $(BUILD_DROIDDOC)

# $(gen), i.e. framework.aidl, is also needed while building against the current stub.
$(full_target): $(framework_built) $(gen)

droidcore: doc-comment-check-docs

# ====  static html in the sdk ==================================
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=$(framework_docs_LOCAL_SRC_FILES)
LOCAL_INTERMEDIATE_SOURCES:=$(framework_docs_LOCAL_INTERMEDIATE_SOURCES)
LOCAL_JAVA_LIBRARIES:=$(framework_docs_LOCAL_JAVA_LIBRARIES)
LOCAL_MODULE_CLASS:=$(framework_docs_LOCAL_MODULE_CLASS)
LOCAL_DROIDDOC_SOURCE_PATH:=$(framework_docs_LOCAL_DROIDDOC_SOURCE_PATH)
LOCAL_DROIDDOC_HTML_DIR:=$(framework_docs_LOCAL_DROIDDOC_HTML_DIR)
LOCAL_ADDITIONAL_JAVA_DIR:=$(framework_docs_LOCAL_ADDITIONAL_JAVA_DIR)
LOCAL_ADDITIONAL_DEPENDENCIES:=$(framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES)

LOCAL_MODULE := offline-sdk

LOCAL_DROIDDOC_OPTIONS:=\
		$(framework_docs_LOCAL_DROIDDOC_OPTIONS) \
                $(web_docs_sample_code_flags) \
                -offlinemode \
		-title "Android SDK" \
		-proofread $(OUT_DOCS)/$(LOCAL_MODULE)-proofread.txt \
		-todo $(OUT_DOCS)/$(LOCAL_MODULE)-docs-todo.html \
		-sdkvalues $(OUT_DOCS) \
		-hdf android.whichdoc offline


LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR:=build/tools/droiddoc/templates-sdk

include $(BUILD_DROIDDOC)

static_doc_index_redirect := $(out_dir)/index.html
$(static_doc_index_redirect): \
	$(LOCAL_PATH)/docs/docs-documentation-redirect.html | $(ACP)
	$(hide) mkdir -p $(dir $@)
	$(hide) $(ACP) $< $@

$(full_target): $(static_doc_index_redirect)
$(full_target): $(framework_built)

# ==== docs for the web (on the androiddevdocs app engine server) =======================
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=$(framework_docs_LOCAL_SRC_FILES)
LOCAL_INTERMEDIATE_SOURCES:=$(framework_docs_LOCAL_INTERMEDIATE_SOURCES)
LOCAL_STATIC_JAVA_LIBRARIES:=$(framework_docs_LOCAL_STATIC_JAVA_LIBRARIES)
LOCAL_JAVA_LIBRARIES:=$(framework_docs_LOCAL_JAVA_LIBRARIES)
LOCAL_MODULE_CLASS:=$(framework_docs_LOCAL_MODULE_CLASS)
LOCAL_DROIDDOC_SOURCE_PATH:=$(framework_docs_LOCAL_DROIDDOC_SOURCE_PATH)
LOCAL_DROIDDOC_HTML_DIR:=$(framework_docs_LOCAL_DROIDDOC_HTML_DIR)
LOCAL_ADDITIONAL_JAVA_DIR:=$(framework_docs_LOCAL_ADDITIONAL_JAVA_DIR)
LOCAL_ADDITIONAL_DEPENDENCIES:=$(framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES)

LOCAL_MODULE := online-sdk

LOCAL_DROIDDOC_OPTIONS:= \
		$(framework_docs_LOCAL_DROIDDOC_OPTIONS) \
		$(web_docs_sample_code_flags) \
		-toroot / \
		-hdf android.whichdoc online \
		-hdf template.showLanguageMenu true

LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR:=build/tools/droiddoc/templates-sdk

include $(BUILD_DROIDDOC)

# explicitly specify that online-sdk depends on framework-res and any generated docs
$(full_target): framework-res-package-target

# ==== docs for the web (on the devsite app engine server) =======================
include $(CLEAR_VARS)
LOCAL_SRC_FILES:=$(framework_docs_LOCAL_SRC_FILES)
LOCAL_INTERMEDIATE_SOURCES:=$(framework_docs_LOCAL_INTERMEDIATE_SOURCES)
LOCAL_STATIC_JAVA_LIBRARIES:=$(framework_docs_LOCAL_STATIC_JAVA_LIBRARIES)
LOCAL_JAVA_LIBRARIES:=$(framework_docs_LOCAL_JAVA_LIBRARIES)
LOCAL_MODULE_CLASS:=$(framework_docs_LOCAL_MODULE_CLASS)
LOCAL_DROIDDOC_SOURCE_PATH:=$(framework_docs_LOCAL_DROIDDOC_SOURCE_PATH)
LOCAL_DROIDDOC_HTML_DIR:=$(framework_docs_LOCAL_DROIDDOC_HTML_DIR)
LOCAL_ADDITIONAL_JAVA_DIR:=$(framework_docs_LOCAL_ADDITIONAL_JAVA_DIR)
LOCAL_ADDITIONAL_DEPENDENCIES:=$(framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES)
# specify a second html input dir and an output path relative to OUT_DIR)
LOCAL_ADDITIONAL_HTML_DIR:=docs/html-intl /

LOCAL_MODULE := ds

LOCAL_DROIDDOC_OPTIONS:= \
		$(framework_docs_LOCAL_DROIDDOC_OPTIONS) \
		$(web_docs_sample_code_flags) \
		-devsite \
		-toroot / \
		-hdf android.whichdoc online \
		-hdf devsite true

LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR:=build/tools/droiddoc/templates-sdk

include $(BUILD_DROIDDOC)

# explicitly specify that ds depends on framework-res and any generated docs
$(full_target): framework-res-package-target


#==== reference docs for GCM =======================

include $(CLEAR_VARS)
#
gcm_docs_src_files += \
        $(call all-java-files-under, ../../vendor/unbundled_google/libs/gcm/gcm-client/src) \
        $(call all-java-files-under, ../../vendor/unbundled_google/libs/gcm/gcm-server/src) \
        $(call all-html-files-under, ../../vendor/unbundled_google/libs/gcm/gcm-client/src) \
        $(call all-html-files-under, ../../vendor/unbundled_google/libs/gcm/gcm-server/src) \

LOCAL_SRC_FILES := $(gcm_docs_src_files)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= online-gcm-ref
LOCAL_MODULE_CLASS := JAVA_LIBRARIES
LOCAL_IS_HOST_MODULE := false

LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR := build/tools/droiddoc/templates-sdk

LOCAL_DROIDDOC_OPTIONS := \
        -toroot / \
        -gcmref \
        -hdf android.whichdoc online \
        -hdf template.showLanguageMenu true

include $(BUILD_DROIDDOC)

# ==== docs that have all of the stuff that's @hidden =======================
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=$(framework_docs_LOCAL_SRC_FILES)
LOCAL_INTERMEDIATE_SOURCES:=$(framework_docs_LOCAL_INTERMEDIATE_SOURCES)
LOCAL_JAVA_LIBRARIES:=$(framework_docs_LOCAL_JAVA_LIBRARIES) framework
LOCAL_MODULE_CLASS:=$(framework_docs_LOCAL_MODULE_CLASS)
LOCAL_DROIDDOC_SOURCE_PATH:=$(framework_docs_LOCAL_DROIDDOC_SOURCE_PATH)
LOCAL_DROIDDOC_HTML_DIR:=$(framework_docs_LOCAL_DROIDDOC_HTML_DIR)
LOCAL_ADDITIONAL_JAVA_DIR:=$(framework_docs_LOCAL_ADDITIONAL_JAVA_DIR)
LOCAL_ADDITIONAL_DEPENDENCIES:=$(framework_docs_LOCAL_ADDITIONAL_DEPENDENCIES)

LOCAL_MODULE := hidden
LOCAL_DROIDDOC_OPTIONS:=\
		$(framework_docs_LOCAL_DROIDDOC_OPTIONS) \
		-title "Android SDK - Including hidden APIs."
#		-hidden

LOCAL_DROIDDOC_CUSTOM_TEMPLATE_DIR:=build/tools/droiddoc/templates-sdk

include $(BUILD_DROIDDOC)

# Build ext.jar
# ============================================================

# NOTICE notes for non-obvious sections
# apache-http - covered by the Apache Commons section.


ext_dirs := \
	../../external/nist-sip/java \
	../../external/apache-http/src \
	../../external/tagsoup/src \
	../../external/libphonenumber/java/src

ext_src_files := $(call all-java-files-under,$(ext_dirs))

ext_res_dirs := \
	../../external/libphonenumber/java/src

# ====  the library  =========================================
include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(ext_src_files)

LOCAL_NO_STANDARD_LIBRARIES := true
LOCAL_JAVA_LIBRARIES := core
LOCAL_JAVA_RESOURCE_DIRS := $(ext_res_dirs)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := ext

LOCAL_DX_FLAGS := --core-library

include $(BUILD_JAVA_LIBRARY)


# Include subdirectory makefiles
# ============================================================

# If we're building with ONE_SHOT_MAKEFILE (mm, mmm), then what the framework
# team really wants is to build the stuff defined by this makefile.
ifeq (,$(ONE_SHOT_MAKEFILE))
include $(call first-makefiles-under,$(LOCAL_PATH))
endif
