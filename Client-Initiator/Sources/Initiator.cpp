#include "Headers/Initiator.hpp"

void onCreate(const FIX::SessionID &session_id) {
  //log - > session has been created!
}


void onLogon( const FIX::SessionID &session_id) {
  std::cout << "Logon into the session : " << session_id << std::endl;
  //log- > logon to the session - session id
  //may sent the subscribtion initially one time here
}

void onLogout( const FIX::SessionID &session_id) {
  std::cout << "Logout from the session : " << session_id << std::endl;
  //logout from the session - sessionid
}

void toAdmin( FIX::Message &message, const FIX::SessionID &session_id ) {
  // log-> sending Administrative Messages like 
  // Logon (A), Logout (5), Heartbeat (0), Test Request (1), Resend Request (2)
  // to the counterparty will invoke this method
}

void toApp( FIX::Message &message, const FIX::SessionID &session_id ) 
  throw (FIX::DoNotSend) {
    //log -> sending All application message through this method;
}

void fromAdmin( const FIX::Message &message, const FIX::SessionID &session_id ) 
  throw ( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon ) {
    std::cout << "incoming : " << message << std::endl;
}

void fromApp( const FIX::Message &message, const FIX::SessionID &session_id ) 
  throw ( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType ) {
    std::cout << "incoming : " << message << std::endl;
}