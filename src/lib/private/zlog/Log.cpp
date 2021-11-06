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

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef ZERO_CORE_LOG_HPP
#include "../../public/zlog/Log.hpp"
#endif // !ZERO_CORE_LOG_HPP

// Include ILogger
#ifndef ZERO_CORE_I_LOGGER_HXX
#include "../../public/zlog/ILogger.hxx"
#endif // !ZERO_CORE_I_LOGGER_HXX

// DEBUG
#ifdef ZERO_DEBUG

// Include assert
#ifndef ZERO_ASSERT_HPP
#include "../../public/zlog/cfg/zero_assert.hpp"
#endif // !ZERO_ASSERT_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ILogger
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{
    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        zILogger* Log::mInstance( nullptr );

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Log::Log() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Log::~Log() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Log::enabled() noexcept
        { return mInstance && mInstance->isEnabled(); }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void Log::Initialize( zILogger* const pInstance ) ZERO_NOEXCEPT
        {
            if ( !mInstance )
                mInstance = pInstance;
        }

        void Log::Terminate() ZERO_NOEXCEPT
        {
            delete mInstance;
            mInstance = nullptr;
        }

        void Log::info( const char* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::info: instance is not set !" );
            zAssert( pMessage && "Log::info: empty message !" );
#endif // DEBUG

            mInstance->printInfo( pMessage );
        }

        void Log::info_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::info_w: instance is not set !" );
            zAssert( pMessage && "Log::info_w: empty message !" );
#endif // DEBUG

            mInstance->printInfo_w( pMessage );
        }

        void Log::debug( const char* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::debug: instance is not set !" );
            zAssert( pMessage && "Log::debug: empty message !" );
#endif // DEBUG

            mInstance->printDebug( pMessage );
        }

        void Log::debug_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::debug_w: instance is not set !" );
            zAssert( pMessage && "Log::debug_w: empty message !" );
#endif // DEBUG

            mInstance->printDebug_w( pMessage );
        }

        void Log::warning( const char* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::warning: instance is not set !" );
            zAssert( pMessage && "Log::warning: empty message !" );
#endif // DEBUG

            mInstance->printWarning( pMessage );
        }

        void Log::warning_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::warning_w: instance is not set !" );
            zAssert( pMessage && "Log::warning_w: empty message !" );
#endif // DEBUG

            mInstance->printWarning_w( pMessage );
        }

        void Log::error( const char* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::error: instance is not set !" );
            zAssert( pMessage && "Log::error: empty message !" );
#endif // DEBUG

            mInstance->printError( pMessage );
        }

        void Log::error_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            zAssert( mInstance && "Log::error_w: instance is not set !" );
            zAssert( pMessage && "Log::error_w: empty message !" );
#endif // DEBUG

            mInstance->printError_w( pMessage );
        }

        void Log::print( const char* const pMessage, const zELogLevels logLevel ) ZERO_NOEXCEPT
        {

            switch( logLevel )
            {
                case zELogLevels::LEVEL_INFO:
                    info( pMessage );
                break;

                case zELogLevels::LEVEL_DEBUG:
                    debug( pMessage );
                break;

                case zELogLevels::LEVEL_WARNING:
                    warning( pMessage );
                break;

                case zELogLevels::LEVEL_ERROR:
                    error( pMessage );
                break;
            }

        }

        void Log::print_w( const wchar_t* const pMessage, const zELogLevels logLevel ) ZERO_NOEXCEPT
        {

            switch( logLevel )
            {
                case zELogLevels::LEVEL_INFO:
                    info_w( pMessage );
                break;

                case zELogLevels::LEVEL_DEBUG:
                    debug_w( pMessage );
                break;

                case zELogLevels::LEVEL_WARNING:
                    warning_w( pMessage );
                break;

                case zELogLevels::LEVEL_ERROR:
                    error_w( pMessage );
                break;
            }

        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
