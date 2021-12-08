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
#ifndef ZERO_CORE_DEFAULT_LOGGER_HPP
#include "../../../../public/zero/core/log/DefaultLogger.hpp"
#endif // !ZERO_CORE_DEFAULT_LOGGER_HPP

// Include STL iostream
#include <iostream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// DefaultLogger
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        DefaultLogger::DefaultLogger() noexcept = default;

        DefaultLogger::~DefaultLogger() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS: ILogger
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool DefaultLogger::isEnabled() const noexcept
        { return true; }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS: ILogger
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void DefaultLogger::printInfo( const char* const pMessage ) ZERO_NOEXCEPT
        { std::cout << "INFO: " << pMessage << "\n"; }

        void DefaultLogger::printInfo_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        { std::wcout << "INFO: " << pMessage << "\n"; }

        void DefaultLogger::printDebug( const char* const pMessage ) ZERO_NOEXCEPT
        { std::cout << "DEBUG: " << pMessage << "\n"; }

        void DefaultLogger::printDebug_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        { std::wcout << "DEBUG: " << pMessage << "\n"; }

        void DefaultLogger::printWarning( const char* const pMessage ) ZERO_NOEXCEPT
        { std::cout << "WARNING: " << pMessage << "\n"; }

        void DefaultLogger::printWarning_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        { std::wcout << "WARNING: " << pMessage << "\n"; }

        void DefaultLogger::printError( const char* const pMessage ) ZERO_NOEXCEPT
        { std::cout << "ERROR: " << pMessage << "\n"; }

        void DefaultLogger::printError_w( const wchar_t* const pMessage ) ZERO_NOEXCEPT
        { std::wcout << "ERROR: " << pMessage << "\n"; }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
