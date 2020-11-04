//==============================================================================
/**
@file       MyStreamDeckPlugin.h

@brief      Demo Hello World

@copyright  (c) 2020, Zongyi Yang

**/
//==============================================================================

#include "Common/ESDBasePlugin.h"
#include <mutex>

class HelloWorldHelper;
class CallBackTimer;

class MyStreamDeckPlugin : public ESDBasePlugin
{
public:
	
	MyStreamDeckPlugin();
	virtual ~MyStreamDeckPlugin();
	
	void KeyDownForAction(const std::string& inAction, const std::string& inContext, const json &inPayload, const std::string& inDeviceID) override;
	void KeyUpForAction(const std::string& inAction, const std::string& inContext, const json &inPayload, const std::string& inDeviceID) override;
	
	void WillAppearForAction(const std::string& inAction, const std::string& inContext, const json &inPayload, const std::string& inDeviceID) override;
	void WillDisappearForAction(const std::string& inAction, const std::string& inContext, const json &inPayload, const std::string& inDeviceID) override;
	
	void DeviceDidConnect(const std::string& inDeviceID, const json &inDeviceInfo) override;
	void DeviceDidDisconnect(const std::string& inDeviceID) override;
	
	void SendToPlugin(const std::string& inAction, const std::string& inContext, const json &inPayload, const std::string& inDeviceID) override;

private:
	
	void UpdateTimer();
	
	std::mutex mVisibleContextsMutex;
	std::set<std::string> mVisibleContexts;
	
	std::unique_ptr<HelloWorldHelper> mHelloWorld = std::make_unique <HelloWorldHelper>();
	std::unique_ptr<CallBackTimer> mTimer = std::make_unique <CallBackTimer>();
};
