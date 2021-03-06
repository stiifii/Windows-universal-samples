//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
//-----------------------------------------------------------------------------
// <auto-generated>
//   This code was generated by a tool.
//
//   Changes to this file may cause incorrect behavior and will be lost if
//   the code is regenerated.
//
//   For more information, see: http://go.microsoft.com/fwlink/?LinkID=623246
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace org { namespace alljoyn { namespace Onboarding {

public interface class IOnboardingConsumer
{
};

public ref class OnboardingConsumer sealed  : [Windows::Foundation::Metadata::Default] IOnboardingConsumer, ISignalEmitter
{
public:
    OnboardingConsumer(Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);
    virtual ~OnboardingConsumer();

    // Create a consumer from a device Id asynchronously.
    //
    // This is usually called to create a consumer after the unique name of a producer has been reported
    // in the Added callback on the DeviceWatcher.
    static Windows::Foundation::IAsyncOperation<OnboardingConsumer^>^ FromIdAsync(_In_ Platform::String^ deviceId);

    // Create a consumer from a device Id asynchronously with the provided bus attachment.
    //
    // This is usually called to create a consumer after the unique name of a producer has been reported
    // in the Added callback on the DeviceWatcher.
    static Windows::Foundation::IAsyncOperation<OnboardingConsumer^>^ FromIdAsync(_In_ Platform::String^ deviceId, _In_ Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);

    int32 OnboardingConsumer::Initialize(_In_ Windows::Devices::AllJoyn::AllJoynServiceInfo^ serviceInfo);

    // "Sends the personal AP information to the onboardee"
    // Call the ConfigureWiFi method
    Windows::Foundation::IAsyncOperation<OnboardingConfigureWiFiResult^>^ ConfigureWiFiAsync(_In_ Platform::String^ interfaceMemberSSID, _In_ Platform::String^ interfaceMemberPassphrase, _In_ int16 interfaceMemberAuthType);
    // "Tells the onboardee to connect to the personal AP"
    // Call the Connect method
    Windows::Foundation::IAsyncOperation<OnboardingConnectResult^>^ ConnectAsync();
    // "Tells the onboardee to disconnect from the personal AP"
    // Call the Offboard method
    Windows::Foundation::IAsyncOperation<OnboardingOffboardResult^>^ OffboardAsync();
    // "Scans all the Wi-Fi access points in the onboardee's proximity"
    // Call the GetScanInfo method
    Windows::Foundation::IAsyncOperation<OnboardingGetScanInfoResult^>^ GetScanInfoAsync();

    // "Interface version number"
    // Get the value of the Version property.
    Windows::Foundation::IAsyncOperation<OnboardingGetVersionResult^>^ GetVersionAsync();

    // "The configuration state"
    // Get the value of the State property.
    Windows::Foundation::IAsyncOperation<OnboardingGetStateResult^>^ GetStateAsync();

    // "The last error code and error message"
    // Get the value of the LastError property.
    Windows::Foundation::IAsyncOperation<OnboardingGetLastErrorResult^>^ GetLastErrorAsync();


    // Used to send signals or register functions to handle received signals.
    property OnboardingSignals^ Signals
    {
        OnboardingSignals^ get() { return m_signals; }
    }

    // Used to get the name of the interface this consumer implements.
    static property Platform::String^ InterfaceName
    {
        Platform::String^ get() { return AllJoynHelpers::MultibyteToPlatformString(m_interfaceName); }
    }

    virtual property Windows::Devices::AllJoyn::AllJoynBusObject^ BusObject
    {
        Windows::Devices::AllJoyn::AllJoynBusObject^ get() { return m_busObject; }
    }

    virtual property Windows::Devices::AllJoyn::AllJoynSession^ Session
    {
        Windows::Devices::AllJoyn::AllJoynSession^ get() { return m_session; }
    }

internal:
    // Consumers do not support property get.
    QStatus OnPropertyGet(_In_ PCSTR interfaceName, _In_ PCSTR propertyName, _Inout_ alljoyn_msgarg val)
    {
        UNREFERENCED_PARAMETER(interfaceName); UNREFERENCED_PARAMETER(propertyName); UNREFERENCED_PARAMETER(val);
        return ER_NOT_IMPLEMENTED;
    }

    // Consumers do not support property set.
    QStatus OnPropertySet(_In_ PCSTR interfaceName, _In_ PCSTR propertyName, _In_ alljoyn_msgarg val)
    {
        UNREFERENCED_PARAMETER(interfaceName); UNREFERENCED_PARAMETER(propertyName); UNREFERENCED_PARAMETER(val);
        return ER_NOT_IMPLEMENTED;
    }

    void OnPropertyChanged(_In_ alljoyn_proxybusobject obj, _In_ PCSTR interfaceName, _In_ const alljoyn_msgarg changed, _In_ const alljoyn_msgarg invalidated);

    property Platform::String^ ServiceObjectPath
    {
        Platform::String^ get() { return m_ServiceObjectPath; }
        void set(Platform::String^ value) { m_ServiceObjectPath = value; }
    }

    property alljoyn_proxybusobject ProxyBusObject
    {
        alljoyn_proxybusobject get() { return m_proxyBusObject; }
        void set(alljoyn_proxybusobject value) { m_proxyBusObject = value; }
    }

private:
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _SessionLost;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _SessionMemberAdded;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _SessionMemberRemoved;

    // Register a callback function to handle incoming signals.
    QStatus AddSignalHandler(_In_ alljoyn_busattachment busAttachment, _In_ alljoyn_interfacedescription interfaceDescription, _In_ PCSTR methodName, _In_ alljoyn_messagereceiver_signalhandler_ptr handler);

    // "This signal is emitted when the connection attempt against the personal AP is completed"
    static void CallConnectionResultSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);

    Windows::Devices::AllJoyn::AllJoynBusAttachment^ m_busAttachment;
    Windows::Devices::AllJoyn::AllJoynBusObject^ m_busObject;
    Windows::Devices::AllJoyn::AllJoynSession^ m_session;
    OnboardingSignals^ m_signals;
    Platform::String^ m_ServiceObjectPath;

    alljoyn_proxybusobject m_proxyBusObject;
    alljoyn_sessionlistener m_sessionListener;
    alljoyn_busobject m_nativeBusObject;
    alljoyn_busattachment m_nativeBusAttachment;

    // Used to pass a pointer to this class to callbacks
    Platform::WeakReference* m_weak;

    // This map is required because we need a way to pass the consumer to the signal
    // handlers, but the current AllJoyn C API does not allow passing a context to these
    // callbacks.
    static std::map<alljoyn_interfacedescription, Platform::WeakReference*> SourceInterfaces;

    // The name of the interface this consumer implements.
    static PCSTR m_interfaceName;
};

} } } 
