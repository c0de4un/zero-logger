# zero-logger
zeroEngine Logger - Part of zeroSDK

# Features
 * basic log-levels
 * lightweight
 * unicode support by native wchar_t
 * multibyte chars support
 * platform-specific API support (DebugOutput, Logcat, etc)
 * dynamic toggle flag

# Minimum Requirements
 * C++ 14
 * CMake 3.16

# Examples
 * Initialization with custom handler
 ```c++
 int main()
 {
     zLog::Initialize( new MyCustomLogHandler() );

#if defined( DEBUG ) || defined( ZERO_DEBUG ) // DEBUG
     zLog::info( u8"Hello World !" );
#endif // DEBUG

     return 0;
 }
 ```
 * Simple Print
 ```c++
 int main()
 {
#if defined( DEBUG ) // DEBUG
     const std::wstring unicodeStr( L"Здравствуй дивный мир !" );
     zLog::print_w( unicodeStr.c_str(), zELogLevel::INFO );
#endif // DEBUG

     return 0;
 }
 ```
