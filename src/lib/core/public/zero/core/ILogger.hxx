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

#ifndef ZERO_CORE_I_LOGGER_HXX
#define ZERO_CORE_I_LOGGER_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_API_HPP
#include "cfg/zero_api.hpp"
#endif // !ZERO_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // ILogger
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /**
         * @brief
         * ILogger - logger contract
         * 
         * @version 1.0
        **/
        ZERO_API class ILogger
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // META
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ZERO_INTERFACE

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * ILogger destructor
             * 
             * @throws - no exceptions
            **/
            virtual ~ILogger() noexcept = default;

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
            virtual bool isEnabled() const noexcept = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * Print INFO-level message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printInfo( const char* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print INFO-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printInfo_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print DEBUG-level message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printDebug( const char* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print DEBUG-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printDebug_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print WARNING-level message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printWarning( const char* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print WARNING-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printWarning_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print ERROR-level message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printError( const char* const pMessage ) ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Print ERROR-level UTF-16 message
             * 
             * @thread_safety - not thread-safe
             * @param pMessage - message to print
             * @throws - not exceptions
            **/
            virtual void printError_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::ILogger

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

using zILogger = zero::core::ILogger;
#define ZERO_CORE_I_LOGGER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_I_LOGGER_HXX
