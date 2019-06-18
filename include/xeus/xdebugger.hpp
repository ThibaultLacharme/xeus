/***************************************************************************
* Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef XEUS_DEBUGGER_HPP
#define XEUS_DEBUGGER_HPP

#include "zmq.hpp"
#include "nlohmann/json.hpp"

#include "xeus.hpp"
#include "xkernel_configuration.hpp"

namespace xeus
{
    class XEUS_API xdebugger
    {
    public:

        xdebugger() = default;
        virtual ~xdebugger() = default;

        xdebugger(const xdebugger&) = delete;
        xdebugger& operator=(const xdebugger&) = delete;

        xdebugger(xdebugger&&) = delete;
        xdebugger& operator=(xdebugger&&) = delete;

        void process_request(const nlohmann::json& message);

    private:

        virtual void process_request_impl(const nlohmann::json& message) = 0;
    };

    XEUS_API
    std::unique_ptr<xdebugger> make_null_debugger(zmq::context_t&, const xconfiguration&);
            
}

#endif

