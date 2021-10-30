/**
 * All rights reserved.
 * License: see LICENSE.txt
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
 * in the credits of the application, if such credits exist.
 * The authors of this work must be notified via email (code4un@yandex.ru) in
 * this case of redistribution.
 * 3. Neither the name of copyright holders nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef ZERO_CORE_LOG_HPP
#define ZERO_CORE_LOG_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_API_HPP
#include "cfg/zero_api.hpp"
#endif // !ZERO_API_HPP

// Include zero::core::ELogLevels
#ifndef ZERO_CORE_E_LOG_LEVELS_HPP
#include "ELogLevels.hpp"
#endif // !ZERO_CORE_E_LOG_LEVELS_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward-Declare ILogger
#ifndef ZERO_CORE_I_LOGGER_DECL
#define ZERO_CORE_I_LOGGER_DECL
namespace zero { namespace core { class ILogger; } }
using zILogger = zero::core::ILogger;
#endif // !ZERO_CORE_I_LOGGER_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // zero::core::Log
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /**
         * @brief
         * Log - facade-class for loggin
         * 
         * @version 1.0
        **/
        ZERO_API class Log final
        {

        private:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /** ILogger **/
            static zILogger* mInstance;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            explicit Log() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            Log( const Log& ) = delete;
            Log( Log&& )      = delete;

            Log& operator=( const Log& ) = delete;
            Log& operator=( Log& )       = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ~Log() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * Is Logging enabled
             * 
             * @thread_safety - not required
             * @throws - no exceptions
            **/
            static bool enabled() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * Initialize Logger instance
             * 
             * @thread_safety - main-thread only
             * @throws - no exceptions
            **/
            static void Initialize( zILogger* const pInstance ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Terminate Logger instance
             * 
             * @thread_safety - main-thread only
             * @throws - no exceptiosn
            **/
            static void Terminate() ZERO_NOEXCEPT;

            /**
             * @brief
             * Print INFO-level message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void info( const char* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print INFO-level message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void info_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print DEBUG-level message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void debug( const char* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print DEBUG-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void debug_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print WARNING-level message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void warning( const char* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print WARNING-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void warning_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print ERROR-level message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void error( const char* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print ERROR-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void error_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print log-message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @param logLevel - log-level (@see zero::core::ELogLevels)
             * @throws - no exceptions
            **/
            static void print( const char* const pMessage, const zELogLevels logLevel ) ZERO_NOEXCEPT;

            /**
             * @brief
             * Print UTF-16 log-message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @param logLevel - log-level (@see zero::core::ELogLevels)
             * @throws - no exceptions
            **/
            static void print_w( const wchar_t* const pMessage, const zELogLevels logLevel ) ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        };

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

using zLog = zero::core::Log;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_LOG_HPP
