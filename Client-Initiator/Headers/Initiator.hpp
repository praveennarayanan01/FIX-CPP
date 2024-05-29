#include <quickfix/Initiator.h>
#include <quickfix/Application.h>
#include <quickfix/MessageCracker.h>
#include <quickfix/Message.h>

class MyInitiator : FIX::Application, FIX::MessageCracker {

/// @brief will automatically invoke when session will created to the counter-party
/// @param session_id  "session ID" refers to a unique identifier representing a specific communication 
///                     session between two FIX protocol participants.
void onCreate(const FIX::SessionID &session_id);

/// @brief will automatically invoke when the session logon into the counter-party
/// @param session_id  "session ID" refers to a unique identifier representing a specific communication 
///                     session between two FIX protocol participants.
void onLogon( const FIX::SessionID &session_id);

/// @brief will automatically invoke when the session logout from the counter-party
/// @param session_id  "session ID" refers to a unique identifier representing a specific communication 
///                     session between two FIX protocol participants.
void onLogout( const FIX::SessionID &session_id);

/// @brief will automatically invoke when adminstrative messages sent from our client-side
/// @param message  FIX::Message
/// @param session_id FIX::SessionID 
void toAdmin( FIX::Message &message, const FIX::SessionID &session_id );

/// @brief will automatically invoke when 
/// @param message FIX::Message
/// @param session_id FIX::SessionID
/// @return void 
void toApp( FIX::Message &message, const FIX::SessionID &session_id ) 
    throw (FIX::DoNotSend); 

void fromAdmin( const FIX::Message &message, const FIX::SessionID &session_id ) 
    throw ( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon );

void fromApp( const FIX::Message &message, const FIX::SessionID &session_id ) 
    throw ( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType );
 
}; 